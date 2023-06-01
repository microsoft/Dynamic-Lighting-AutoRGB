// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <Windows.Media.Playback.h>

STDAPI MediaPlaybackListExtension_AddCurrentItemChanged(
    _In_ IUnknown* sourceAsIUnknown,
    _In_ ::ABI::Windows::Foundation::ITypedEventHandler<::ABI::Windows::Media::Playback::MediaPlaybackList*, ::ABI::Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs*>* handler,
    _Out_ EventRegistrationToken* token) noexcept;

STDAPI MediaPlaybackListExtension_RemoveCurrentItemChanged(
    _In_ IUnknown* sourceAsIUnknown,
    _In_ EventRegistrationToken token) noexcept;

STDAPI MediaPlaybackListExtension_AddAutoRepeatChanged(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlaybackList* mediaPlaybackList,
    _In_ ::ABI::Windows::Foundation::ITypedEventHandler<::ABI::Windows::Media::Playback::MediaPlaybackList*, IInspectable*>* handler,
    _Out_ EventRegistrationToken* token) noexcept;

STDAPI MediaPlaybackListExtension_RemoveAutoRepeatChanged(
    _In_ ::ABI::Windows::Media::Playback::IMediaPlaybackList* mediaPlaybackList,
    _In_ EventRegistrationToken token) noexcept;
