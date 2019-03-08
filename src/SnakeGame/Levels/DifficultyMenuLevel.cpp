#include "stdafx.h"
#include "DifficultyMenuLevel.h"

#include "Common/Exceptions.h"

namespace sg
{
    enum class DifficultyMenuItem
    {
        Easy,
        Normal,
        Hard
    };

    DifficultyMenuLevel::DifficultyMenuLevel(GameState & gameState)
        : m_items({"Easy", "Normal", "Hard"})
        , m_gameState(gameState)
    {
    }

    void DifficultyMenuLevel::Update(Input input)
    {
        HandleInput(input);
        m_items.Update(input);
    }

    void DifficultyMenuLevel::Draw()
    {
        std::cout << "Choose difficulty:\n"
            << m_items.FormatItemList();
    }

    void DifficultyMenuLevel::HandleInput(Input input)
    {
        if (Input::Enter == input)
        {
            auto item = static_cast<DifficultyMenuItem>(m_items.GetCurrentItemIdx());
            switch (item)
            {
            case DifficultyMenuItem::Easy:
                m_gameState.SetDifficulty(Difficulty::Easy);
                break;

            case DifficultyMenuItem::Normal:
                m_gameState.SetDifficulty(Difficulty::Normal);
                break;

            case DifficultyMenuItem::Hard:
                m_gameState.SetDifficulty(Difficulty::Hard);
                break;

            default:
                THROW("Failed to update difficulty menu level: Invalid value of difficulty menu item " << static_cast<size_t>(item));
                break;
            }

            m_gameState.Notify(GameEvent::LoadSnakeLevel);
        }
    }
}