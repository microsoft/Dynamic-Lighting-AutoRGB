// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

namespace Microsoft.WindowsAppSDK
{
    public class Release
    {
        public const ushort Major = 1;
        public const ushort Minor = 0;
        public const ushort Patch = 0;
        public const uint MajorMinor = 0x00010000;

        public const string Channel = "preview";

        public const string VersionTag = "preview1";

        public const string VersionShorttag = "p1";
    }

    namespace Runtime
    {
        public const string Publisher = "CN=Microsoft Corporation, O=Microsoft Corporation, L=Redmond, S=Washington, C=US";
        public const string PublisherId = "8wekyb3d8bbwe";

        public class Version
        {
            public const ushort Major = 0;
            public const ushort Minor = 258;
            public const ushort Build = 2116;
            public const ushort Revision = 0;
            public const ulong UInt64 = 0x0000010208440000;
            public const string DotQuadString = "0.258.2116.0";
        }
    }
}
