// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include <Windows.ApplicationModel.core.h>

STDAPI FinalUnhandledErrorDetected_RegisterHandler(
        _In_  ::ABI::Windows::Foundation::IEventHandler<ABI::Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs*>  *pHandler, 
        _Out_ EventRegistrationToken *pToken
        ) noexcept;
STDAPI FinalUnhandledErrorDetected_UnregisterHandler(_Inout_ EventRegistrationToken* pToken) noexcept;
