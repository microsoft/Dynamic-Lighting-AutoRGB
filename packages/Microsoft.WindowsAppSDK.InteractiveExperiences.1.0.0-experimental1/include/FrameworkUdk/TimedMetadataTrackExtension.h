// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <Windows.Media.Playback.h>

STDAPI TimedMetadataTrackExtension_AddCueEntered(
    _In_ ::ABI::Windows::Media::Core::ITimedMetadataTrack* timedMetadataTrack,
    _In_ ::ABI::Windows::Foundation::ITypedEventHandler<::ABI::Windows::Media::Core::TimedMetadataTrack*, ::ABI::Windows::Media::Core::MediaCueEventArgs*>* handler,
    _Out_ EventRegistrationToken* token) noexcept;

STDAPI TimedMetadataTrackExtension_RemoveCueEntered(
    _In_ ::ABI::Windows::Media::Core::ITimedMetadataTrack* timedMetadataTrack,
    _In_ EventRegistrationToken token) noexcept;
