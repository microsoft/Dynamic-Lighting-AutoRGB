// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include <BackButtonPressedListener.h>

STDAPI BackButtonIntegration_RegisterListener(_In_ ::ABI::Microsoft::Internal::FrameworkUdk::IBackButtonPressedListener* listener) noexcept;
STDAPI BackButtonIntegration_UnregisterListener(_In_ ::ABI::Microsoft::Internal::FrameworkUdk::IBackButtonPressedListener* listener) noexcept;
STDAPI BackButtonIntegration_InjectBackButtonPress(_Out_ BOOL* handled) noexcept;
