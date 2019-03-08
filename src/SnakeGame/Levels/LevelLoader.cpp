#include "stdafx.h"
#include "LevelLoader.h"

#include "Common/Exceptions.h"

#include "MainMenuLevel.h"
#include "DifficultyMenuLevel.h"
#include "SnakeLevel/SnakeLevel.h"
#include "GameOverMenuLevel.h"

namespace sg
{
    LevelPtr LevelLoader::LoadLevel(LevelType type, GameState& gameState)
    {
        LevelPtr level;
        switch (type)
        {
        case LevelType::MainMenu:
            level = std::make_unique<MainMenuLevel>(gameState);
            break;
        case LevelType::DifficultyMenu:
            level = std::make_unique<DifficultyMenuLevel>(gameState);
            break;
        case LevelType::SnakeGame:
            level = std::make_unique<SnakeLevel>(gameState);
            break;
        case LevelType::GameOverMenu:
            level = std::make_unique<GameOverMenuLevel>(gameState);
            break;
        
        default:
            THROW("Failed to load level: Unknown level type " << static_cast<size_t>(type));
            break;
        }

        return level;
    }
}
