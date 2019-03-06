#pragma once

namespace sg
{
    enum class GameEvent
    {
        LoadMainMenu,
        LoadDifficultyMenu,
        LoadGameLevel,
        LoadGameOverMenu
    };

    using OnGameEventCb = std::function<void(GameEvent)>;
}