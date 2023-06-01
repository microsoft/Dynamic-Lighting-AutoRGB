// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

typedef HRESULT (*VisualDiagnosticsCallbackFunc)(void* context, const void* payload, int size);

STDAPI VisualDiagnosticsPort_Register(_In_ const wchar_t* portName, _In_ VisualDiagnosticsCallbackFunc callbackFunc, _In_ void* context) noexcept;
STDAPI VisualDiagnosticsPort_Unregister() noexcept;