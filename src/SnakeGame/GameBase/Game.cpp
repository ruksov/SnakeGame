#include "stdafx.h"
#include "Game.h"

#include "Common/InputQueue.h"
#include "Common/Exceptions.h"

using namespace std::chrono_literals;

namespace sg
{
    Game::Game(LevelLoaderPtr levelLoader)
        : m_state(10, [this](auto ev) { OnGameEvent(ev); })
        , m_levelLoader(std::move(levelLoader))
    {
        THROW_IF(!m_levelLoader, "Failed to create game: Level loader can't be NULL");
    }

    void Game::Launch()
    {
        InputQueue inputs;
        const auto msPerFrame = 1000ms / m_state.GetFps();
        LevelPtr level = m_levelLoader->LoadLevel(LevelType::MainMenu, m_state);

        while (!m_state.GetExitState())
        {
            auto startFrameTime = std::chrono::high_resolution_clock::now();
            ClearConsole();

            Input input = inputs.Pop();
            
            //
            // Handle Esc input.
            // If it pressed, the game will be closed.
            //
            if (Input::Esc == input)
            {
                m_state.SetExitState();
                continue;
            }

            if (level)
            {
                level->Update(input);
                level->Draw();
            }

            if (m_nextLevel)
            {
                level = std::move(m_nextLevel);
            }

            //
            // Call sleep to achive stable fps.
            //
            std::this_thread::sleep_until(startFrameTime + msPerFrame);
        }

        ClearConsole();
        std::cout << "Please, press some key to exit from the game . . . \n";
    }

    void Game::OnGameEvent(GameEvent ev)
    {
        switch (ev)
        {
        case GameEvent::LoadMainMenu:
            m_nextLevel = m_levelLoader->LoadLevel(LevelType::MainMenu, m_state);
            break;

        case GameEvent::LoadDifficultyMenu:
            m_nextLevel = m_levelLoader->LoadLevel(LevelType::DifficultyMenu, m_state);
            break;

        case GameEvent::LoadSnakeLevel:
            m_nextLevel = m_levelLoader->LoadLevel(LevelType::SnakeGame, m_state);
            break;

        case GameEvent::LoadGameOverMenu:
            m_nextLevel = m_levelLoader->LoadLevel(LevelType::GameOverMenu, m_state);
            break;

        case GameEvent::Exit:
            m_state.SetExitState();
            break;

        default:
            THROW("Failed to handle game even: Unknow event " << static_cast<size_t>(ev));
            break;
        }
    }

    void Game::ClearConsole()
    {
        system("CLS");
    }
}

