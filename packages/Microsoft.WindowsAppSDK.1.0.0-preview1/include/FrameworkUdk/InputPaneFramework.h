// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include <shobjidl_core.h>
#include <InputPaneListener.h>

STDAPI InputPaneFramework_RegisterListener(_In_ ABI::Windows::UI::ViewManagement::IInputPane* inputPane,
                                            _In_ ABI::Microsoft::Internal::FrameworkUdk::IInputPaneVisibilityChangedListener* pListener) noexcept;

STDAPI InputPaneFramework_UnregisterListener(_In_ ABI::Windows::UI::ViewManagement::IInputPane* inputPane,
                                                _In_ ABI::Microsoft::Internal::FrameworkUdk::IInputPaneVisibilityChangedListener* pListener) noexcept;

STDAPI InputPaneFramework_Advise(_In_ IFrameworkInputPane* inputPane,
                                 _In_ ABI::Windows::UI::Core::ICoreWindow* coreWindow,
                                 _In_ IFrameworkInputPaneHandler* handler,
                                 _Out_ DWORD* cookie) noexcept;
