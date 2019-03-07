#pragma once

namespace sg
{
    enum class GameEvent
    {
        LoadMainMenu,
        LoadDifficultyMenu,
        LoadSnakeLevel,
        LoadGameOverMenu,
        Exit
    };

    using OnGameEventCb = std::function<void(GameEvent)>;
}