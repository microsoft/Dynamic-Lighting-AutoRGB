// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <mfmediacapture.h>
#include <Windows.Media.Capture.h>

STDAPI MediaCaptureExtension_GetPreviewSource(
    _In_ ::ABI::Windows::Media::Capture::IMediaCapture* mediaCapture,
    _In_opt_ IInspectable* mfCaptureEngineSampleCallback,
    _Outptr_result_maybenull_ IInspectable** previewSource) noexcept;

