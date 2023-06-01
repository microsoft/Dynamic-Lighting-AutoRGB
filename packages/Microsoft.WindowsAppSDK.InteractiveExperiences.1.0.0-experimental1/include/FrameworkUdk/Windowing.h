// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

STDAPI WinUITryGetWindowIdFromWindow(_In_ HWND hwnd, _Out_ ::ABI::Microsoft::UI::WindowId* id) noexcept;
STDAPI WinUITryGetWindowFromWindowId(_In_ ::ABI::Microsoft::UI::WindowId id, _Out_ HWND* hwnd) noexcept;

STDAPI WinUITryGetDisplayIdFromMonitor(_In_ HMONITOR a, _Out_ ::ABI::Microsoft::UI::DisplayId* b) noexcept;
STDAPI WinUITryGetMonitorFromDisplayId(_In_  ::ABI::Microsoft::UI::DisplayId a, _Out_ HMONITOR* b) noexcept;

STDAPI Windowing_EnableModernWindowBackground(_In_ ::ABI::Microsoft::UI::WindowId id, _In_ BOOL isEnabled) noexcept;
STDAPI Windowing_IsModernWindowBackgroundEnabled(_In_ ::ABI::Microsoft::UI::WindowId id, _Out_ BOOL* pIsEnabled) noexcept;
