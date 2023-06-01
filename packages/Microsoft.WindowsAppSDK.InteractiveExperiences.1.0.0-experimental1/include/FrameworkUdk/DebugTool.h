// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

namespace DebugTool
{
#pragma pack(push)
#pragma pack(1)
    // Visual Diagnostics's Core Messaging based IPC
    struct Msg_ConnectToVisualTree
    {
        Msg_ConnectToVisualTree()
        {
            ZeroMemory(this, sizeof(Msg_ConnectToVisualTree));
        }

        UINT                MessageID;
        WCHAR               wszDllName[MAX_PATH];
        WCHAR               wszTAPDllName[MAX_PATH];
        WCHAR               wszInitializationData[MAX_PATH];
        CLSID               tapClsid;

        static const Msg_ConnectToVisualTree * SafeCast(_In_ const void * pMsg, _In_ int size)
        {
            if (size != sizeof(Msg_ConnectToVisualTree))
            {
                ASSERT(FALSE && L"Should have valid size");
                return nullptr;
            }

            return reinterpret_cast<const Msg_ConnectToVisualTree*>(pMsg);
        }
    };
#pragma pack(pop)
}