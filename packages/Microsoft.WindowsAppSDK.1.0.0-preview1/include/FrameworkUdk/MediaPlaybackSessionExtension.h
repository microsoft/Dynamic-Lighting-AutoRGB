// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <Windows.Media.Playback.h>

STDAPI MediaPlaybackSessionExtension_IsPlaybackRateSupported(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlaybackSession* mediaPlaybackSession,
    DOUBLE rate,
    _Out_ BOOLEAN* value) noexcept;