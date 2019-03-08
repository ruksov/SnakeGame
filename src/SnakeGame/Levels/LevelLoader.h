#pragma once
#include "ILevelLoader.h"

namespace sg
{
    //
    // The LevelLoader creates new level according to passed level type.
    //
    class LevelLoader : public ILevelLoader
    {
    public:
        LevelPtr LoadLevel(LevelType type, GameState& gameState) override;
    };
}

