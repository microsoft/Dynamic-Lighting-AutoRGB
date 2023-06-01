// Copyright (c) Microsoft Corporation. All rights reserved.

#pragma once

enum class MediaPlaybackDataSourceExtension_RepeatMode : int
{
    None,
    One,
    All
};

enum class MediaPlaybackDataSourceExtension_MediaPlaybackCommands : int
{
    MediaPlaybackCommand_Play = 0,
    MediaPlaybackCommand_Pause = 1,
    MediaPlaybackCommand_FastForward = 4,
    MediaPlaybackCommand_Rewind = 5,
    MediaPlaybackCommand_Next = 6,
    MediaPlaybackCommand_Previous = 7,
};

