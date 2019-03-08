#pragma once
#include "GameState.h"
#include "GameEvent.h"
#include "Levels/ILevelLoader.h"

namespace sg
{
    class Game
    {
    public:
        explicit Game(LevelLoaderPtr levelLoader);
        void Launch();

    private:
        void OnGameEvent(GameEvent ev);
        void ClearConsole();

    private:
        GameState m_state;
        LevelPtr m_nextLevel;
        LevelLoaderPtr m_levelLoader;
    };
}