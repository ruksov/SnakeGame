#include "stdafx.h"
#include "GameOverMenuLevel.h"
#include "Exceptions.h"

namespace sg
{
    enum class GameOverMenuItem
    {
        Restart,
        GoToMainMenu,
        Exit
    };

    GameOverMenuLevel::GameOverMenuLevel(GameState & gameState)
        : m_items({ "Restart", "Go to Main menu", "Exit" })
        , m_gameState(gameState)
    {
    }

    void GameOverMenuLevel::Update(Input input)
    {
        HandleInput(input);
        m_items.Update(input);
    }

    void GameOverMenuLevel::Draw()
    {
        std::cout << "Game over \n"
            << "Your score: " << m_gameState.GetLastScore() << '\n'
            << "High score: " << m_gameState.GetHighScore() << "\n\n"
            << "What you want to do next? \n"
            << m_items.FormatItemList();
    }

    void GameOverMenuLevel::HandleInput(Input input)
    {
        if (Input::Enter == input)
        {
            auto item = static_cast<GameOverMenuItem>(m_items.GetCurrentItemIdx());
            switch (item)
            {
            case GameOverMenuItem::Restart:
                m_gameState.Notify(GameEvent::LoadSnakeLevel);
                break;

            case GameOverMenuItem::GoToMainMenu:
                m_gameState.Notify(GameEvent::LoadMainMenu);
                break;

            case GameOverMenuItem::Exit:
                m_gameState.Notify(GameEvent::Exit);
                break;

            default:
                THROW("Failed to update game over menu level: Invalid value of game over menu item " << static_cast<size_t>(item));
                break;
            }
        }
    }
}