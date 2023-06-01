// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

namespace ABI {
    namespace Windows {
        namespace UI {
            namespace Text {
                namespace Core {
                    interface ICoreTextEditContext;
                } /* Core */
            } /* Text */
        } /* UI */
    } /* Windows */
} /* ABI */

enum class TextInput_InputSettings : DWORD
{
    None                                  = 0,
    EnableAutoCorrect                     = 3,
    DisableAutoCorrect                    = 2,
    EnableAutoSuggest                     = 12,
    DisableAutoSuggest                    = 8,
    EnableHaveTrailer                     = 48,
    DisableHaveTrailer                    = 32,
    EnableSpellCheck                      = 192,
    DisableSpellCheck                     = 128,
    EnableCandidatesOnDemand              = 768,
    DisableCandidatesOnDemand             = 512,
    EnableAutoCapitalization              = 3072,
    DisableAutoCapitalization             = 2048,
    EnablePrivateInputSetting             = 786432,
    DisablePrivateInputSetting            = 524288,
    PasswordObfuscated                    = 134217728,
    EnableManualInputPane                 = 805306368,
    DisableManualInputPane                = 536870912,
    BottomEdgeCandidateWindowAlignment    = 1073741824,
};

enum class TextInput_KeyboardSkins
{
    Default,
    Bitlocker,
};

STDAPI TextInputProxy_putInputSettings(_In_ ABI::Windows::UI::Text::Core::ICoreTextEditContext* textEditContext, TextInput_InputSettings value) noexcept;
STDAPI TextInput_SetTextPrediction(_In_ HWND hwnd) noexcept;
STDAPI TextInput_SetKeyboardSkin(_In_ TextInput_KeyboardSkins skin, _In_ HWND hwnd) noexcept;
