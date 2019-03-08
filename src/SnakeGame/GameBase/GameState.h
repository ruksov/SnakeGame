#pragma once
#include "GameEvent.h"

namespace sg
{
    //
    // Types of difficulty in snake game level.
    //
    enum class Difficulty
    {
        Undefined,
        Easy,
        Normal,
        Hard
    };

    //
    // The GameState class will be shared between main 
    // Game class and current level. This class keeps game 
    // configurations and some values. 
    //
    // These values help level to send data to other levels, 
    // which will be loaded after it.
    //
    class GameState
    {
    public:
        GameState(size_t framesPerSecond, OnGameEventCb onGameEventCb);
        
        size_t GetFps() const;

        void SetExitState();
        bool GetExitState() const;

        void SetLastScore(size_t score);
        size_t GetLastScore() const;

        size_t GetHighScore() const;

        void SetDifficulty(Difficulty difficulty);
        Difficulty GetDifficulty() const;

        //
        // This method will be notify game state subscriber.
        // Now it is main Game class. And levels will send
        // via this method signal to Game class about loading
        // some new level.
        //
        void Notify(GameEvent ev);

    private:
        size_t m_fps = 0;
        bool m_exitState = false;
        size_t m_lastScore = 0;
        size_t m_highScore = 0;
        Difficulty m_difficulty = Difficulty::Undefined;
        OnGameEventCb m_onGameEventCb;
    };
}


