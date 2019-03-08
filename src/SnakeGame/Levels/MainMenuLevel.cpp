#include "stdafx.h"
#include "MainMenuLevel.h"

#include "Common/Exceptions.h"

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
        std::cout << "Main Menu: \n"
            << m_items.FormatItemList() 
            << '\n'
            << "last score: " << m_gameState.GetLastScore() << '\n'
            << "high score: " << m_gameState.GetHighScore() << "\n"
            << '\n'
            << "menu controls:\n"
            << "\t w, a - move item mark\n" 
            << "\t Enter - choose marked item \n"
            << '\n'
            << "snake controls:\n"
            << "\t w, a, s, d - change snake direction \n"
            << '\n'
            << " * press Esc to quit from the game at any moment \n"
            << '\n'
            << '\n'
            << "Created by Yegor Krasochenko (squanchy) \n";
    }

    void MainMenuLevel::HandleInput(Input input)
    {
        if (Input::Enter == input)
        {
            auto item = static_cast<MainMenuItems>(m_items.GetCurrentItemIdx());
            switch (item)
            {
            case MainMenuItems::NewGame:
                m_gameState.Notify(GameEvent::LoadDifficultyMenu);
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