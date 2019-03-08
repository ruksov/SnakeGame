#pragma once
#include "GameState.h"
#include "GameEvent.h"
#include "Levels/ILevelLoader.h"

namespace sg
{
    //
    // Main game class
    //
    class Game
    {
    public:
        explicit Game(LevelLoaderPtr levelLoader);

        //
        // Creates Input queue and first Main Menu level.
        // Launches game loop and control frame rate.
        //
        void Launch();

    private:
        //
        // Gets events from levels and reacts to them.
        // The GameState class will be use OnGameEvent in it's Notify method.
        //
        void OnGameEvent(GameEvent ev);
        void ClearConsole();

    private:
        const size_t m_fps;
        GameState m_state;
        LevelPtr m_nextLevel;
        LevelLoaderPtr m_levelLoader;
    };
}