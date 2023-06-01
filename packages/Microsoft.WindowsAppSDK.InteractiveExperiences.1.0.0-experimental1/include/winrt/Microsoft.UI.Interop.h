//----------------------------------------------------------------------------
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//----------------------------------------------------------------------------

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <winrt/Microsoft.UI.h>


namespace winrt {
namespace Microsoft {
namespace UI {


STDAPI GetWindowHandleFromWindowId(_In_ ::winrt::Microsoft::UI::WindowId windowId, _Out_ HWND* result);
STDAPI GetWindowIdFromWindowHandle(_In_ HWND hwnd, _Out_ ::winrt::Microsoft::UI::WindowId* result);


} // namespace UI
} // namespace Microsoft
} // namespace winrt
