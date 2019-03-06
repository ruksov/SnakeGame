#pragma once

namespace sg
{
    enum class GameEvent
    {
        LoadMainMenu,
        LoadDifficultyMenu,
        LoadGameLevel,
        LoadGameOverMenu,
        Exit
    };

    using OnGameEventCb = std::function<void(GameEvent)>;
}