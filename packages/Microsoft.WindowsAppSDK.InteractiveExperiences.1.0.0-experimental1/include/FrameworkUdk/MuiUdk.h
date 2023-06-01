// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

STDAPI Mui_PropagateApplicationLanguages() noexcept;

STDAPI Mui_GetFontFallbackLanguageList(
    _In_opt_ PCWSTR primaryLanguageOverride,
    _In_ size_t languageListCapacity,
    _Out_writes_to_opt_(languageListCapacity, *languageListSize) PWSTR languageList,
    _Out_ size_t * languageListSize) noexcept;