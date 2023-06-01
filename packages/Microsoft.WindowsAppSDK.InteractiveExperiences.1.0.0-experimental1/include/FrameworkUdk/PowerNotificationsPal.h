// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

#include <poclass.h>
#include <Windows.h>

#pragma pack(push,8)
struct CompositeBatteryStatus
{
    BATTERY_INFORMATION Information;
    BATTERY_STATUS Status;
    ULONG ActiveBatteryCount;
    ULONG GlobalBatteryCount;
};
#pragma pop

DECLARE_HANDLE(CompositeBatteryStatusRegistration);
STDAPI PowerNotifications_GetCompositeBatteryStatus(_Out_ CompositeBatteryStatus* compositeBatteryStatusOut) noexcept;
typedef void (*OnCompositeBatteryStatusChanged)(CompositeBatteryStatus compositeBatteryStatus);
STDAPI PowerNotifications_RegisterCompositeBatteryStatusChangedListener(_In_ OnCompositeBatteryStatusChanged listener, _Out_ CompositeBatteryStatusRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterCompositeBatteryStatusChangedListener(_In_ CompositeBatteryStatusRegistration registration) noexcept;

DECLARE_HANDLE(DischargeTimeRegistration);
STDAPI PowerNotifications_GetDischargeTime(_Out_ ULONGLONG* DischargeTimeOut) noexcept;
typedef void (*OnDischargeTimeChanged)(ULONGLONG DischargeTime);
STDAPI PowerNotifications_RegisterDischargeTimeChangedListener(_In_ OnDischargeTimeChanged listener, _Out_ DischargeTimeRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterDischargeTimeChangedListener(_In_ DischargeTimeRegistration registration) noexcept;

enum EnergySaverStatus
{
    Uninitalized = 0,
    Disabled,
    Off,
    On
};

DECLARE_HANDLE(EnergySaverStatusRegistration);
STDAPI PowerNotifications_GetEnergySaverStatus(_Out_ EnergySaverStatus* energySaverStatusOut) noexcept;
typedef void (*OnEnergySaverStatusChanged)(EnergySaverStatus energySaverStatus);
STDAPI PowerNotifications_RegisterEnergySaverStatusChangedListener(_In_ OnEnergySaverStatusChanged listener, _Out_ EnergySaverStatusRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterEnergySaverStatusChangedListener(_In_ EnergySaverStatusRegistration registration) noexcept;

// Note: All the data below comes from NtPowerInformation, and the raw ABI of the
// state we get back from the low-level APIs is described at https://docs.microsoft.com/en-us/windows/win32/power/power-setting-guids.

DECLARE_HANDLE(PowerConditionRegistration);
STDAPI PowerNotifications_GetPowerCondition(_Out_ DWORD* powerConditionOut) noexcept;
typedef void (*OnPowerConditionChanged)(DWORD powerCondition);
STDAPI PowerNotifications_RegisterPowerConditionChangedListener(_In_ OnPowerConditionChanged listener, _Out_ PowerConditionRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterPowerConditionChangedListener(_In_ PowerConditionRegistration registration) noexcept;

DECLARE_HANDLE(DisplayStatusRegistration);
STDAPI PowerNotifications_GetDisplayStatus(_Out_ DWORD* displayStatusOut) noexcept;
typedef void (*OnDisplayStatusChanged)(DWORD displayStatus);
STDAPI PowerNotifications_RegisterDisplayStatusChangedListener(_In_ OnDisplayStatusChanged listener, _Out_ DisplayStatusRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterDisplayStatusChangedListener(_In_ DisplayStatusRegistration registration) noexcept;

DECLARE_HANDLE(SystemIdleStatusRegistration);
typedef void (*OnSystemIdleStatusChanged)();
STDAPI PowerNotifications_RegisterSystemIdleStatusChangedListener(_In_ OnSystemIdleStatusChanged listener, _Out_ SystemIdleStatusRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterSystemIdleStatusChangedListener(_In_ SystemIdleStatusRegistration registration) noexcept;

DECLARE_HANDLE(PowerSchemePersonalityRegistration);
STDAPI PowerNotifications_GetPowerSchemePersonality(_Out_ GUID* powerSchemePersonalityOut) noexcept;
typedef void (*OnPowerSchemePersonalityChanged)(GUID powerSchemePersonality);
STDAPI PowerNotifications_RegisterPowerSchemePersonalityChangedListener(_In_ OnPowerSchemePersonalityChanged listener, _Out_ PowerSchemePersonalityRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterPowerSchemePersonalityChangedListener(_In_ PowerSchemePersonalityRegistration registration) noexcept;

DECLARE_HANDLE(UserPresenceStatusRegistration);
STDAPI PowerNotifications_GetUserPresenceStatus(_Out_ DWORD* userPresenceStatusOut) noexcept;
typedef void (*OnUserPresenceStatusChanged)(DWORD userPresenceStatus);
STDAPI PowerNotifications_RegisterUserPresenceStatusChangedListener(_In_ OnUserPresenceStatusChanged listener, _Out_ UserPresenceStatusRegistration* registration) noexcept;
STDAPI PowerNotifications_UnregisterUserPresenceStatusChangedListener(_In_ UserPresenceStatusRegistration registration) noexcept;
