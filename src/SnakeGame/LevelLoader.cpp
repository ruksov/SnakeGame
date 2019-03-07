#include "stdafx.h"
#include "LevelLoader.h"
#include "Exceptions.h"

#include "MainMenuLevel.h"
#include "SnakeLevel.h"

namespace sg
{
    LevelPtr LevelLoader::LoadLevel(LevelType type, GameState & gameState)
    {
        LevelPtr level;
        switch (type)
        {
        case LevelType::MainMenu:
            level = std::make_unique<MainMenuLevel>(gameState);
            break;
        case LevelType::DifficultyMenu:
            break;
        case LevelType::SnakeGame:
            level = std::make_unique<SnakeLevel>(gameState);
            break;
        case LevelType::GameOverMenu:
            break;
        
        case LevelType::Undefined:
        default:
            THROW("Failed to load level: Unknown level type " << static_cast<size_t>(type));
            break;
        }

        return level;
    }
}
