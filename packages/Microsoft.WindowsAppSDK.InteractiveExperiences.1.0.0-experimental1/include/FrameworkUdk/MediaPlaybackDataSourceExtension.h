// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <Windows.Media.Playback.h>
#include "MediaExtensionEnums.h"

STDAPI MediaPlaybackDataSourceExtension_SendMediaPlaybackCommand(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer2* mediaPlayer2,
    MediaPlaybackDataSourceExtension_MediaPlaybackCommands playbackCommands) noexcept;

STDAPI MediaPlaybackDataSourceExtension_SendRepeatModeChangeRequest(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer2* mediaPlayer2,
    MediaPlaybackDataSourceExtension_RepeatMode playbackRepeatMode) noexcept;

STDAPI MediaPlaybackDataSourceExtension_SendPlaybackRateChangeRequest(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer2* mediaPlayer2,
    double playbackRate) noexcept;

STDAPI MediaPlaybackDataSourceExtension_SendPlaybackPositionChangeRequest(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer2* mediaPlayer2,
    INT64 playbackPosition) noexcept;
