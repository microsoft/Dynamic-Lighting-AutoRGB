// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

STDAPI Windowing_GetWindowIdFromWindowHandle(_In_ HWND hwnd, _Out_ ::ABI::Microsoft::UI::WindowId* id) noexcept;
STDAPI Windowing_GetWindowHandleFromWindowId(_In_ ::ABI::Microsoft::UI::WindowId id, _Out_ HWND* hwnd) noexcept;

STDAPI Windowing_GetDisplayIdFromMonitorHandle(_In_ HMONITOR a, _Out_ ::ABI::Microsoft::UI::DisplayId* b) noexcept;
STDAPI Windowing_GetMonitorHandleFromDisplayId(_In_ ::ABI::Microsoft::UI::DisplayId a, _Out_ HMONITOR* b) noexcept;

STDAPI Windowing_EnableModernWindowBackground(_In_ ::ABI::Microsoft::UI::WindowId id, _In_ BOOL isEnabled) noexcept;
STDAPI Windowing_IsModernWindowBackgroundEnabled(_In_ ::ABI::Microsoft::UI::WindowId id, _Out_ BOOL* pIsEnabled) noexcept;

STDAPI Windowing_GetIconIdFromIconHandle(_In_ HICON a, _Out_ ::ABI::Microsoft::UI::IconId* b) noexcept;
STDAPI Windowing_GetIconHandleFromIconId(_In_ ::ABI::Microsoft::UI::IconId a, _Out_ HICON* b) noexcept;
