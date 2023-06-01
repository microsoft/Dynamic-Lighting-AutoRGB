// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include <shobjidl_core.h>
#include "windows.foundation.h"

#include <windows.ui.viewmanagement.core.h>

// IFrameworkInputViewOcculusionsChangedListener is the bridge between UDK and lifted XAML(MUX).
namespace ABI::Microsoft::Internal::FrameworkUdk
{
    interface
        __declspec(uuid("D8D926FE-5F13-43AF-B43E-12A3B7C99538"))
        IFrameworkInputViewOcculusionsChangedListener
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFrameworkInputViewOcclusionsChanged(
            _In_ boolean handled,
            _In_ ABI::Windows::Foundation::Collections::IVectorView<ABI::Windows::UI::ViewManagement::Core::CoreInputViewOcclusion*> *pvOcclusions) = 0;
    };
}

STDAPI FrameworkInputView_RegisterListener(
            _In_ ABI::Windows::UI::ViewManagement::Core::ICoreInputView* coreInputView,
            _In_ ABI::Microsoft::Internal::FrameworkUdk::IFrameworkInputViewOcculusionsChangedListener* pListener) noexcept;

STDAPI FrameworkInputView_UnregisterListener(
            _In_ ABI::Windows::UI::ViewManagement::Core::ICoreInputView* coreInputView,
            _In_ ABI::Microsoft::Internal::FrameworkUdk::IFrameworkInputViewOcculusionsChangedListener* pListener) noexcept;
