#pragma once

namespace sg
{
    //
    // Types of difficulty on game level.
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
        explicit GameState(size_t framesPerSecond);
        
        size_t GetFps() const;

        void SetExitState();
        bool GetExitState() const;

        void SetLastScore(size_t score);
        size_t GetLastScore() const;

        size_t GetHighScore() const;

        void SetDifficulty(Difficulty difficulty);
        Difficulty GetDifficulty() const;

    private:
        size_t m_fps = 0;
        bool m_exitState = false;
        size_t m_lastScore = 0;
        size_t m_highScore = 0;
        Difficulty m_difficulty = Difficulty::Undefined;
    };
}


