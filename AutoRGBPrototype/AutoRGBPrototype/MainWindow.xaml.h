#pragma once

#include "MainWindow.g.h"

#include "GraphicsManager.h"
#include "RGBDeviceManager.h"

namespace winrt::AutoRGBPrototype::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        ~MainWindow() {}

        void captureButton_Click(
            winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

        AutoRGBPrototype::GraphicsManager m_graphicsManager = winrt::make<GraphicsManager>();
        RGBDeviceManager m_rgbDeviceManager;
    };
}

namespace winrt::AutoRGBPrototype::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
