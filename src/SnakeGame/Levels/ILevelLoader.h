#pragma once
#include "ILevel.h"
#include "GameBase/GameState.h"

namespace sg
{
    enum class LevelType
    {
        Undefined = 0,
        MainMenu,
        DifficultyMenu,
        SnakeGame,
        GameOverMenu
    };

    using LevelLoaderPtr = std::unique_ptr<struct ILevelLoader>;

    //
    // Interface for loading levels.
    //
    struct ILevelLoader
    {
        virtual ~ILevelLoader() = default;
        virtual LevelPtr LoadLevel(LevelType levelType, GameState& gameState) = 0;
    };
}