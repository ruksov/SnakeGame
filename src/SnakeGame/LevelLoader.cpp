#include "stdafx.h"
#include "LevelLoader.h"
#include "Exceptions.h"

namespace sg
{
    LevelPtr LevelLoader::LoadLevel(LevelType type, GameState & gameState)
    {
        LevelPtr level;
        switch (type)
        {
        case LevelType::MainMenu:
            break;
        case LevelType::DifficultyMenu:
            break;
        case LevelType::Game:
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
