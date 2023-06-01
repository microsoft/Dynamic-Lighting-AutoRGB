#include "pch.h"
#include "GraphicsManager.h"
#if __has_include("GraphicsManager.g.cpp")
#include "GraphicsManager.g.cpp"
#endif

#include "pch.h"
#include "ColorShader.h"

#include <ppltasks.h>
#include <wil/resource.h>

namespace winrt
{
    using namespace Windows::Foundation;
    using namespace Windows::Graphics;
    using namespace Windows::Graphics::Capture;
    using namespace Windows::Graphics::DirectX;
    using namespace Windows::Graphics::DirectX::Direct3D11;
}

using namespace Windows::Graphics::DirectX::Direct3D11;

namespace winrt::AutoRGBPrototype::implementation
{
    void GraphicsManager::Initialize()
    {
        GetDisplayInfo();
        CreateDevices();
        CreateShaderResources();

        m_colorAlgorithm.Initialize(m_numPixels);
    }

    // Get information on the user's active monitor
    void GraphicsManager::GetDisplayInfo()
    {
        HWND window = GetActiveWindow();
        m_display = MonitorFromWindow(window, MONITOR_DEFAULTTOPRIMARY);

        MONITORINFO info = {};
        info.cbSize = sizeof(MONITORINFO);
        GetMonitorInfo(m_display, &info);

        m_height = info.rcMonitor.bottom - info.rcMonitor.top;
        m_width = info.rcMonitor.right - info.rcMonitor.left;
        m_numPixels = m_height * m_width;

        m_isCaptureSupported = winrt::GraphicsCaptureSession::IsSupported();
    }

    // Create all the D3D devices needed to take a screen capture and run the shader
    void GraphicsManager::CreateDevices()
    {
        HRESULT hr = D3D11CreateDevice(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            D3D11_CREATE_DEVICE_BGRA_SUPPORT,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            m_d3dDevice.put(),
            nullptr,
            nullptr);

        // WARP Fallback
        if (hr == DXGI_ERROR_UNSUPPORTED)
        {
            hr = D3D11CreateDevice(
                nullptr,
                D3D_DRIVER_TYPE_WARP,
                nullptr,
                D3D11_CREATE_DEVICE_BGRA_SUPPORT,
                nullptr,
                0,
                D3D11_SDK_VERSION,
                m_d3dDevice.put(),
                nullptr,
                nullptr);
        }

        winrt::check_hresult(hr);
        m_d3dDevice->GetImmediateContext(m_d3dDeviceContext.put());

        m_dxgiDevice = m_d3dDevice.as<IDXGIDevice>();
        winrt::com_ptr<::IInspectable> d3dDevice;
        hr = CreateDirect3D11DeviceFromDXGIDevice(m_dxgiDevice.get(), d3dDevice.put());

        winrt::check_hresult(hr);
    }

    // Create all the resources needed to run the shader
    void GraphicsManager::CreateShaderResources()
    {
        // The constant buffer will be used to pass struct info from the CPU to the GPU
        {
            D3D11_BUFFER_DESC desc = {};
            desc.ByteWidth = ComputePaddedBufferSize(sizeof(ScreenWidth));
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
            ScreenWidth sw = {};
            sw.Width = m_width;
            D3D11_SUBRESOURCE_DATA data = {};
            data.pSysMem = reinterpret_cast<void*>(&sw);

            winrt::check_hresult(m_d3dDevice->CreateBuffer(&desc, &data, m_constantBuffer.put()));
        }

        // Create a buffer to store the shader output. This buffer is tied to the UAV.
        {
            D3D11_BUFFER_DESC desc = {};
            desc.ByteWidth = ComputePaddedBufferSize(sizeof(uint32_t)) * NUM_BINS;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_UNORDERED_ACCESS;

            winrt::check_hresult(m_d3dDevice->CreateBuffer(&desc, nullptr, m_outputBuffer.put()));
        }

        // UAVs are read/write resources that can be bound to the shader
        {
            D3D11_UNORDERED_ACCESS_VIEW_DESC desc = {};
            desc.Format = DXGI_FORMAT_R32_UINT;
            desc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
            desc.Buffer.NumElements = NUM_BINS;

            winrt::check_hresult(m_d3dDevice->CreateUnorderedAccessView(m_outputBuffer.get(), &desc, m_outputUav.put()));
        }

        // The UAV will be copied into the readback buffer after the shader is run
        {
            D3D11_BUFFER_DESC desc = {};
            desc.ByteWidth = ComputePaddedBufferSize(sizeof(uint32_t)) * NUM_BINS;
            desc.Usage = D3D11_USAGE_STAGING;
            desc.BindFlags = 0;
            desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
            desc.StructureByteStride = ComputePaddedBufferSize(sizeof(uint32_t));

            winrt::check_hresult(m_d3dDevice->CreateBuffer(&desc, nullptr, m_readbackBuffer.put()));
        }

        // The 2D texture that the screen capture will be stored in
        {
            D3D11_TEXTURE2D_DESC desc = {};
            desc.Height = m_height;
            desc.Width = m_width;
            desc.MipLevels = 1;
            desc.ArraySize = 1;
            desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
            desc.SampleDesc.Count = 1;
            desc.Usage = D3D11_USAGE_DEFAULT;
            desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

            winrt::check_hresult(m_d3dDevice->CreateTexture2D(&desc, nullptr, m_captureTexture.put()));
            winrt::check_hresult(m_d3dDevice->CreateShaderResourceView(m_captureTexture.get(), nullptr, m_captureSrv.put()));
        }

        winrt::check_hresult(m_d3dDevice->CreateComputeShader(g_main, ARRAYSIZE(g_main), nullptr, m_shader.put()));
    }

    void GraphicsManager::StartCapture()
    {
        TakeScreenCapture();
    }

    std::future<void> GraphicsManager::TakeScreenCapture()
    {
        co_await TakeScreenCaptureAsync();
    }

    // Take a screen capture. When the capture is taken, convert the image to a 2D texture and run the shader on it
    std::future<void> GraphicsManager::TakeScreenCaptureAsync()
    {
        winrt::GraphicsCaptureItem item{ nullptr };

        auto interopFactory = winrt::get_activation_factory<winrt::GraphicsCaptureItem, IGraphicsCaptureItemInterop>();
        winrt::check_hresult(interopFactory->CreateForMonitor(m_display, winrt::guid_of<ABI::Windows::Graphics::Capture::IGraphicsCaptureItem>(), winrt::put_abi(item)));

        winrt::com_ptr<::IInspectable> device;
        winrt::check_hresult(CreateDirect3D11DeviceFromDXGIDevice(m_dxgiDevice.get(), device.put()));
        winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice d3dDevice = device.as<winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>();

        m_framePool = winrt::Direct3D11CaptureFramePool::Create(d3dDevice, winrt::DirectXPixelFormat::B8G8R8A8UIntNormalized, 1, item.Size());
        m_session = m_framePool.CreateCaptureSession(item);
        m_session.IsBorderRequired(false);

        m_framePool.FrameArrived([this](auto& framePool, auto&)
            {
                winrt::Direct3D11CaptureFrame frame = framePool.TryGetNextFrame();

                // Convert screen capture into a 2D texture, which will be passed into the shader as input
                winrt::com_ptr<ID3D11Texture2D> buffer;
                auto dxgiInterfaceAccess = frame.Surface().as<IDirect3DDxgiInterfaceAccess>();
                dxgiInterfaceAccess->GetInterface(winrt::guid_of<ID3D11Texture2D>(), buffer.put_void());
                m_d3dDeviceContext->CopyResource(m_captureTexture.get(), buffer.get());

                // Run the shader on the screen capture
                RunShader();
            });

        m_session.StartCapture();
        co_return;
    }

    // Create a histogram of RGB values for the screen capture
    // The compute shader iterates through each pixel in the screen capture and bins its R, G, and B value into each histogram
    void GraphicsManager::RunShader()
    {
        // Clear the output buffer
        {
            D3D11_BUFFER_DESC desc = {};
            m_outputBuffer->GetDesc(&desc);
            desc.BindFlags = 0;
            desc.MiscFlags = 0;
            winrt::com_ptr<ID3D11Buffer> clearOutputBuffer;

            winrt::check_hresult(m_d3dDevice->CreateBuffer(&desc, nullptr, clearOutputBuffer.put()));
            m_d3dDeviceContext->CopyResource(m_outputBuffer.get(), clearOutputBuffer.get());
        }

        // Set all the shader resources
        m_d3dDeviceContext->CSSetShader(m_shader.get(), nullptr, 0);
        std::vector<ID3D11ShaderResourceView*> srvs = { m_captureSrv.get() };
        m_d3dDeviceContext->CSSetShaderResources(0, static_cast<uint32_t>(srvs.size()), srvs.data());
        std::vector<ID3D11Buffer*> constants = { m_constantBuffer.get() };
        m_d3dDeviceContext->CSSetConstantBuffers(0, static_cast<uint32_t>(constants.size()), constants.data());
        std::vector<ID3D11UnorderedAccessView*> uavs = { m_outputUav.get() };
        m_d3dDeviceContext->CSSetUnorderedAccessViews(0, static_cast<uint32_t>(uavs.size()), uavs.data(), nullptr);

        // Run the shader
        m_d3dDeviceContext->Dispatch(m_height, 1, 1);

        // Extract the histogram data returned from the shader
        m_d3dDeviceContext->CopyResource(m_readbackBuffer.get(), m_outputBuffer.get());
        D3D11_MAPPED_SUBRESOURCE msr = {};
        winrt::check_hresult(m_d3dDeviceContext->Map(m_readbackBuffer.get(), 0, D3D11_MAP_READ, 0, &msr));

        auto shaderOutput = reinterpret_cast<uint32_t*>(msr.pData);

        auto color = m_colorAlgorithm.CalculatePredominantColor(shaderOutput);
        uint8_t r = static_cast<uint8_t>(color.x * 255);
        uint8_t g = static_cast<uint8_t>(color.y * 255);
        uint8_t b = static_cast<uint8_t>(color.z * 255);

        auto captureTakenEventArgs = make_self<CaptureTakenEventArgs>(r, g, b);
        m_captureTaken(*this, *captureTakenEventArgs);

        m_d3dDeviceContext->Unmap(m_readbackBuffer.get(), 0);
    }

    winrt::event_token GraphicsManager::CaptureTaken(winrt::TypedEventHandler<AutoRGBPrototype::GraphicsManager, AutoRGBPrototype::CaptureTakenEventArgs> const& handler)
    {
        return m_captureTaken.add(handler);
    }

    void GraphicsManager::CaptureTaken(winrt::event_token const& token) noexcept
    {
        m_captureTaken.remove(token);
    }

    // The ByteWidth of a constant buffer has to be a multiple of 16
    uint32_t GraphicsManager::ComputePaddedBufferSize(size_t size)
    {
        auto paddedSize = size;
        if (paddedSize < 16)
        {
            paddedSize = 16;
        }
        else
        {
            auto remainder = paddedSize % 16;
            paddedSize = paddedSize + remainder;
        }
        return static_cast<uint32_t>(paddedSize);
    }
}
