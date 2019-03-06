#include "stdafx.h"
#include "GameState.h"

namespace sg
{
    GameState::GameState(size_t framesPerSecond)
        : m_fps(framesPerSecond)
    {
    }

    size_t GameState::GetFps() const
    {
        return m_fps;
    }

    void GameState::SetExitState()
    {
        m_exitState = true;
    }
    bool GameState::GetExitState() const
    {
        return m_exitState;
    }

    void GameState::SetLastScore(size_t score)
    {
        m_lastScore = score;

        if (m_lastScore > m_highScore)
        {
            m_highScore = m_lastScore;
        }
    }

    size_t GameState::GetLastScore() const
    {
        return m_lastScore;
    }

    size_t GameState::GetHighScore() const
    {
        return m_highScore;
    }

    void GameState::SetDifficulty(Difficulty difficulty)
    {
        m_difficulty = difficulty;
    }

    Difficulty GameState::GetDifficulty() const
    {
        return m_difficulty;
    }
}