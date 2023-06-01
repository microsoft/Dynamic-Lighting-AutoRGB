// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <Windows.Media.Playback.h>

STDAPI AudioGraphSettingsExtension_SetUseSpatialAudioApi(
    _In_ ::ABI::Windows::Media::Audio::IAudioGraphSettings* audioGraphSettings,
    BOOLEAN value) noexcept;
