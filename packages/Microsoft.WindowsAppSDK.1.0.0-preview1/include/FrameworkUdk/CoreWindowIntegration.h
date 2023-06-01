// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include "CoreWindowIntegrationInterface.h"

STDAPI WindowPositionChanged_RegisterListener(_In_ ::ABI::Microsoft::Internal::FrameworkUdk::ICoreWindowPositionChangedListener* pListener) noexcept;
STDAPI WindowPositionChanged_UnregisterListener(_In_ ::ABI::Microsoft::Internal::FrameworkUdk::ICoreWindowPositionChangedListener* pListener) noexcept;
