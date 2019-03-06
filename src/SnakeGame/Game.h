#pragma once
#include "ILevelLoader.h"
#include "GameState.h"
#include "GameEvent.h"

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