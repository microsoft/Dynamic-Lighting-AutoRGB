// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <Windows.Media.Playback.h>

enum class MediaPlayerExtension_MediaPlayerCastingRenderLocation : int
{
    None = 0,
    RenderLocal,
    RenderExternal,
};

STDAPI MediaPlayerExtension_GetCurrentMediaPlaybackItem(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    _COM_Outptr_ ::ABI::Windows::Media::Playback::IMediaPlaybackItem** value) noexcept;

STDAPI MediaPlayerExtension_GetMediaPlayerCastingRenderLocation(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    _Out_ MediaPlayerExtension_MediaPlayerCastingRenderLocation* value) noexcept;

STDAPI MediaPlayerExtension_GetVideoSwapchainHandle(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    _Out_ HANDLE* value) noexcept;

STDAPI MediaPlayerExtension_DisableVisibilityHandling(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer) noexcept;

STDAPI MediaPlayerExtension_AddCastingRenderLocationChanged(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    _In_ ::ABI::Windows::Foundation::ITypedEventHandler<::ABI::Windows::Media::Playback::MediaPlayer*, IInspectable*>* handler,
    _Out_ EventRegistrationToken* token) noexcept;

STDAPI MediaPlayerExtension_RemoveCastingRenderLocationChanged(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    EventRegistrationToken token) noexcept;

STDAPI MediaPlayerExtension_AddIsLoopingEnabledChanged(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    _In_ ::ABI::Windows::Foundation::ITypedEventHandler<::ABI::Windows::Media::Playback::MediaPlayer*, IInspectable*>* handler,
    _Out_ EventRegistrationToken* token) noexcept;

STDAPI MediaPlayerExtension_RemoveIsLoopingEnabledChanged(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlayer* mediaPlayer,
    EventRegistrationToken token) noexcept;