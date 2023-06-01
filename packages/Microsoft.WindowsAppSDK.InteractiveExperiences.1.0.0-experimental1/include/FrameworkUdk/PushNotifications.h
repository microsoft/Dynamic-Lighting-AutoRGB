// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

#include <PushNotificationsRT.h>

STDAPI PushNotifications_RegisterFullTrustApplication(
    _In_ PCWSTR appIdentifier,
    _In_ REFGUID remoteIdentifier) noexcept;

STDAPI PushNotifications_UnregisterFullTrustApplication(
    _In_ PCWSTR appIdentifier) noexcept;

STDAPI PushNotifications_RegisterNotificationSinkForFullTrustApplication(
    _In_ PCWSTR appIdentifier,
    _In_ ABI::Microsoft::Internal::PushNotifications::INotificationListener* notificationListener) noexcept;

STDAPI PushNotifications_UnregisterNotificationSinkForFullTrustApplication(
    _In_ PCWSTR appIdentifier) noexcept;

STDAPI PushNotifications_GetFullTrustApplicationsWithChannels(
    _Out_writes_(*appCount) PWSTR **appIds,
    _Out_ ULONG *appCount) noexcept;

STDAPI PushNotifications_CreateChannelWithRemoteIdentifier(
    _In_ PCWSTR appIdentifier,
    _In_ REFGUID remoteIdentifier,
    _Out_ HRESULT* error,
    _Out_ PWSTR* channelId,
    _Out_ PWSTR* channelUri,
    _Out_ ABI::Windows::Foundation::DateTime* expiryTime) noexcept;

STDAPI PushNotifications_CloseChannel(
    _In_ PCWSTR appIdentifier,
    _In_ PCWSTR channelId) noexcept;
