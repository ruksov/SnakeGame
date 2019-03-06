#pragma once
#include "ILevel.h"
#include "GameState.h"

namespace sg
{
    enum class LevelType
    {
        Undefined = 0,
        MainMenu,
        DifficultyMenu,
        Game,
        GameOverMenu
    };

    using LevelPtr = std::unique_ptr<ILevel>;

    //
    // Interface for loading levels.
    //
    struct ILevelLoader
    {
        virtual ~ILevelLoader() = default;
        virtual LevelPtr LoadLevel(LevelType levelType, GameState& gameState) = 0;
    };
}