//----------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
//----------------------------------------------------------------------------

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <winrt/Microsoft.UI.h>

namespace ABI::Microsoft::UI 
{
    using WindowId = winrt::Microsoft::UI::WindowId;
    using DisplayId = winrt::Microsoft::UI::DisplayId;
    using IconId = winrt::Microsoft::UI::IconId;
}

#include <FrameworkUdk/Windowing.h>


namespace winrt::Microsoft::UI 
{

__forceinline winrt::Microsoft::UI::WindowId GetWindowIdFromWindowHandle(_In_ const HWND& hwnd) 
{
    ::ABI::Microsoft::UI::WindowId abiWindowId;
    winrt::check_hresult(::Windowing_GetWindowIdFromWindowHandle(hwnd, &abiWindowId));
    winrt::Microsoft::UI::WindowId winrtWindowId { abiWindowId.Value };
    return winrtWindowId;
}


__forceinline HWND GetWindowHandleFromWindowId(_In_ const winrt::Microsoft::UI::WindowId& windowId) 
{
    HWND hwnd;
    ::ABI::Microsoft::UI::WindowId abiWindowId { windowId.Value };
    winrt::check_hresult(::Windowing_GetWindowHandleFromWindowId(abiWindowId, &hwnd));
    return hwnd;
}


__forceinline winrt::Microsoft::UI::DisplayId GetDisplayIdFromMonitorHandle(_In_ const HMONITOR& hmonitor) 
{
    ::ABI::Microsoft::UI::DisplayId abiDisplayId;
    winrt::check_hresult(::Windowing_GetDisplayIdFromMonitorHandle(hmonitor, &abiDisplayId));
    winrt::Microsoft::UI::DisplayId winrtDisplayId { abiDisplayId.Value };
    return winrtDisplayId;
}


__forceinline HMONITOR GetMonitorHandleFromDisplayId(_In_ const winrt::Microsoft::UI::DisplayId& displayId) 
{
    HMONITOR hmonitor;
    ::ABI::Microsoft::UI::DisplayId abiDisplayId { displayId.Value };
    winrt::check_hresult(::Windowing_GetMonitorHandleFromDisplayId(abiDisplayId, &hmonitor));
    return hmonitor;
}


__forceinline winrt::Microsoft::UI::IconId GetIconIdFromIconHandle(_In_ const HICON& hicon) 
{
    ::ABI::Microsoft::UI::IconId abiIconId;
    winrt::check_hresult(::Windowing_GetIconIdFromIconHandle(hicon, &abiIconId));
    winrt::Microsoft::UI::IconId winrtIconId { abiIconId.Value };
    return winrtIconId;
}


__forceinline HICON GetIconHandleFromIconId(_In_ const winrt::Microsoft::UI::IconId& iconId) 
{
    HICON hicon;
    ::ABI::Microsoft::UI::IconId abiIconId { iconId.Value };
    winrt::check_hresult(::Windowing_GetIconHandleFromIconId(abiIconId, &hicon));
    return hicon;
}

} // namespace winrt::Microsoft::UI
