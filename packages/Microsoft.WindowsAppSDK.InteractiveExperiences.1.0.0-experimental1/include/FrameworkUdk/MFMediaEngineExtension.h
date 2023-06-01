// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <mfmediaengine.h>
#include <Windows.Media.Core.h>

STDAPI MFMediaEngineExtension_SetSourceFromMediaSource(
    _In_ IMFMediaEngineEx* mediaEngine,
    _In_ IUnknown* mediaSourceAsIUnknown) noexcept;

STDAPI MFMediaEngineExtension_GetCurrentMediaPlaybackItem(
    _In_ IMFMediaEngineEx* mediaEngine,
    _COM_Outptr_ ::ABI::Windows::Media::Playback::IMediaPlaybackItem** playbackItem) noexcept;

STDAPI MFMediaEngineExtension_DisableVisibilityHandling(
    _In_ IMFMediaEngineEx* mediaEngine) noexcept;
