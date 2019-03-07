#include "stdafx.h"
#include "MainMenuLevel.h"
#include "Exceptions.h"

namespace sg
{
    enum class MainMenuItems
    {
        NewGame = 0,
        Exit
    };

    MainMenuLevel::MainMenuLevel(GameState & gameState)
        : m_items({"New game", "Exit"})
        , m_gameState(gameState)
    {

    }

    void MainMenuLevel::Update(Input input)
    {
        HandleInput(input);
        m_items.Update(input);
    }

    void MainMenuLevel::Draw()
    {
        std::cout << "Main menu: \n"
            << m_items.FormatItemList() << '\n'
            << "last score: " << m_gameState.GetLastScore() << '\n'
            << "high score: " << m_gameState.GetHighScore() << '\n'
            << "\nSnake controls:\n"
            << "w, a, s, d - change snake direction\n"
            << "\nMenu controls:\n"
            << "w, a - move item mark\n"
            << "Enter - choose marked item\n"
            << "\n * press Esc to quit from game in any moment"
            << "\n\nCreated by Yegor Krasochenko (squanchy)";
    }

    void MainMenuLevel::HandleInput(Input input)
    {
        if (Input::Enter == input)
        {
            auto item = static_cast<MainMenuItems>(m_items.GetCurrentItemIdx());
            switch (item)
            {
            case MainMenuItems::NewGame:
                //TODO: remove default difficulty
                m_gameState.SetDifficulty(Difficulty::Normal);
                m_gameState.Notify(GameEvent::LoadSnakeLevel);
                break;

            case MainMenuItems::Exit:
                m_gameState.Notify(GameEvent::Exit);
                break;

            default:
                THROW("Failed to update main menu level: Invalid value of main menu item " << static_cast<size_t>(item));
                break;
            }
        }
    }
}