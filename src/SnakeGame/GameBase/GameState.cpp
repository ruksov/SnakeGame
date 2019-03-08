#include "stdafx.h"
#include "GameState.h"

#include "Common/Exceptions.h"

namespace sg
{
    GameState::GameState(size_t framesPerSecond, OnGameEventCb onGameEventCb)
        : m_fps(framesPerSecond)
        , m_onGameEventCb(onGameEventCb)
    {
        THROW_IF(!m_onGameEventCb, "Failed to create game state class: On game event callback can't be NULL");
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

    void GameState::Notify(GameEvent ev)
    {
        m_onGameEventCb(ev);
    }
}