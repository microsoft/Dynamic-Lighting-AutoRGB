// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

STDAPI CoreDragOperationFunctions_StartAsync(
    _In_ IUnknown* unk,
    _In_opt_ IInspectable * initialTarget,
    _In_ ABI::Windows::Foundation::Point initialPosition,
    _Outptr_ ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>** result) noexcept;