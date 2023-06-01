#include "pch.h"
#include "RGBDeviceManager.h"
#include "LightingWinRTWrapper.h"

#include <pplwin.h>
#include <ppltasks.h>
#include "wil/resource.h"
#include "wil/winrt.h"

namespace wrl
{
	using namespace ABI::Windows::Foundation;
	using namespace ABI::Windows::Foundation::Numerics;
	using namespace ABI::Windows::Devices::Enumeration;
	using namespace ABI::Windows::Devices::Lights;
	using namespace ABI::Windows::Devices::Lights::Effects;
	using namespace ABI::Windows::UI;
	using namespace Microsoft::WRL;
	using namespace Microsoft::WRL::Wrappers;
}

using namespace concurrency;

// Interop between WinRT and ABI
HRESULT RGBDeviceManager::InitializeWinRT()
{
	winrt::check_hresult(LightingWinRT::FindClassIDeviceInformationStatics(m_deviceInfoStatics));

	winrt::check_hresult(LightingWinRT::FindClassILampArrayStatics(m_lampArrayStatics));

	winrt::check_hresult(LightingWinRT::FindClassILampArrayCustomEffectFactory(m_effectFactory));

	winrt::check_hresult(LightingWinRT::FindClassILampArrayEffectPlaylistStatics(m_effectPlaylistStatics));

	winrt::check_hresult(LightingWinRT::FindClassIColorHelperStatics(m_colorHelperStatics));

	return S_OK;
}

HRESULT RGBDeviceManager::Initialize()
{
	winrt::check_hresult(InitializeWinRT());

	winrt::check_hresult(m_colorHelperStatics->FromArgb(255, 0, 0, 0, &m_colorClear));

	wrl::HString deviceSelector;
	winrt::check_hresult(m_lampArrayStatics->GetDeviceSelector(deviceSelector.GetAddressOf()));


	winrt::check_hresult(m_deviceInfoStatics->CreateWatcherAqsFilter(deviceSelector.Get(), &m_deviceWatcher));

	EventRegistrationToken addedEventToken;
	EventRegistrationToken removedEventToken;

	auto deviceAddedHandler =
		wrl::Callback<wrl::ITypedEventHandler<wrl::DeviceWatcher*, wrl::DeviceInformation*>>(this, &RGBDeviceManager::OnDeviceAdded);
	auto deviceRemovedHandler =
		wrl::Callback<wrl::ITypedEventHandler<wrl::DeviceWatcher*, wrl::DeviceInformationUpdate*>>(this, &RGBDeviceManager::OnDeviceRemoved);

	winrt::check_hresult(m_deviceWatcher->add_Added(deviceAddedHandler.Get(), &addedEventToken));
	winrt::check_hresult(m_deviceWatcher->add_Removed(deviceRemovedHandler.Get(), &removedEventToken));

	winrt::check_hresult(m_deviceWatcher->Start());

	return S_OK;
}

void RGBDeviceManager::GetDeviceInformation(
	const wrl::HString& id,
	wrl::IDeviceInformation** deviceInfo)
{
	wrl::IAsyncOperation<wrl::DeviceInformation*>* operation;
	m_deviceInfoStatics->CreateFromIdAsync(id.Get(), &operation);

	task<void> task([operation, &deviceInfo]()
		{
			HRESULT hr;
			do
			{
				WaitForSingleObjectEx(GetCurrentThread(), 30, FALSE);
				hr = operation->GetResults(deviceInfo);
			} while (FAILED(hr));

		});

	task.get();
}

void RGBDeviceManager::GetLampArray(
	const wrl::HString& id,
	wrl::ILampArray** lampArray)
{

	wrl::ComPtr<wrl::IAsyncOperation<wrl::LampArray*>> lampArrayOperation;
	m_lampArrayStatics->FromIdAsync(id, lampArrayOperation.GetAddressOf());
	wil::wait_for_completion_nothrow(lampArrayOperation.Get());

	lampArrayOperation->GetResults(lampArray);
}

HRESULT RGBDeviceManager::OnDeviceAdded(wrl::IDeviceWatcher*, wrl::IDeviceInformation* deviceInfo)
{
	wrl::HString id;
	winrt::check_hresult(deviceInfo->get_Id(id.GetAddressOf()));

	LightingDevice device;
	device._id = id.GetRawBuffer(nullptr);

	wrl::HString name;
	winrt::check_hresult(deviceInfo->get_Name(name.GetAddressOf()));
	device._name = name.GetRawBuffer(nullptr);

	wrl::IDeviceInformation* info = nullptr;
	GetDeviceInformation(id, &info);

	GetLampArray(id, &device._lampArray);
	wrl::ILampArray* lampArray = device._lampArray;

	winrt::check_hresult(lampArray->get_LampCount(&device._lampCount));

	for (int lamp = 0; lamp < device._lampCount; lamp++)
	{
		device._indices.push_back(lamp);

		wrl::ILampInfo* lampInfo;
		winrt::check_hresult(lampArray->GetLampInfo(lamp, &lampInfo));
		device._lampInfoList.push_back(lampInfo);
	}

	m_lightingDevices[device._id] = device;

	return S_OK;
}

HRESULT RGBDeviceManager::OnDeviceRemoved(wrl::IDeviceWatcher*, wrl::IDeviceInformationUpdate* info)
{
	wrl::HString id;
	winrt::check_hresult(info->get_Id(id.GetAddressOf()));

	std::wstring wId = id.GetRawBuffer(nullptr);
	if (m_lightingDevices.find(wId) != m_lightingDevices.end())
	{
		m_lightingDevices.erase(wId);
	}

	return S_OK;
}

// Change the color on all connected LampArray devices
void RGBDeviceManager::ChangeColor(uint8_t r, uint8_t g, uint8_t b)
{
	winrt::check_hresult(m_colorHelperStatics->FromArgb(255, r, g, b, &m_currentColor));
	for (auto device : m_lightingDevices)
	{
		device.second._lampArray->SetColor(m_currentColor);
	}
}
