// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include<basetyps.h>

namespace ABI::Microsoft::Internal::FrameworkUdk
 {
    interface
        __declspec(uuid("7297009C-AAC3-41AC-8F31-9E930C417F39"))
        ICoreWindowPositionChangedListener : public IUnknown
    {
    public:
        STDMETHOD (OnCoreWindowPositionChanged)() = 0;
    };
}