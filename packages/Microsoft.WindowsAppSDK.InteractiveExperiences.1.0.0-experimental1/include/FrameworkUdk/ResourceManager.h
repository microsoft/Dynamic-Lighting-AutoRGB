// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once

// filePath needs to be freed with LocalFree
STDAPI ResourceManager_GetDefaultResourcePathForPackageFullName(_In_opt_ PCWSTR packageFullName, _Outptr_ PWSTR* filePath) noexcept;