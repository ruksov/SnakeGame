#include "stdafx.h"
#include "SnakeController.h"

#include "Common/Exceptions.h"

namespace sg
{
    SnakeController::SnakeController(Board& board, size_t gameFps, Difficulty difficulty)
        : m_board(board)
        , m_gameFps(gameFps)
    {
        THROW_IF(gameFps % 10 != 0, "Failed to create contorller: Game fps rate must be divided on 10");

        //
        // Initialize snake move rate according to game difficulty.
        //
        switch (difficulty)
        {
        case Difficulty::Easy:
            m_framesDivider = 2;
            break;

        case Difficulty::Normal:
            m_framesDivider = 5;
            break;

        case Difficulty::Hard:
            m_framesDivider = 10;
            break;

        default:
            THROW("Failed to construst snake controller: Unkonw difficulty value " << static_cast<size_t>(difficulty));
            break;
        }
    }

    void SnakeController::Update(Input input)
    {
        if (!m_isDirectionChanged)
        {
            //
            // Between snake moves direction can be changed only once.
            //
            HandleInput(input);
        }

        if (++m_framesFromLastMove == m_gameFps / m_framesDivider)
        {
            //
            // m_framesDivider is a number of blocks, which snake cross per second.
            //
            m_framesFromLastMove = 0;
            m_isDirectionChanged = false;

            m_snake->Move(m_board);
        }
    }

    void SnakeController::SetSnake(SnakePtr snake)
    {
        THROW_IF(!snake, "Failed to set snake in snake controller: Snake pointer can't be NULL");
        m_snake = std::move(snake);
    }

    void SnakeController::HandleInput(Input input)
    {
        const size_t snakeSize = m_snake->GetSize();
        const MoveDirection snakeDir = m_snake->GetDirection();

        switch (input)
        {
        case Input::Up:
            if (snakeSize == 1 || MoveDirection::Down != snakeDir)
            {
                m_snake->SetDirection(MoveDirection::Up);
                m_isDirectionChanged = true;
            }
            break;

        case sg::Input::Left:
            if (snakeSize == 1 || MoveDirection::Right != snakeDir)
            {
                m_snake->SetDirection(MoveDirection::Left);
                m_isDirectionChanged = true;
            }
            break;

        case sg::Input::Down:
            if (snakeSize == 1 || MoveDirection::Up != snakeDir)
            {
                m_snake->SetDirection(MoveDirection::Down);
                m_isDirectionChanged = true;
            }
            break;

        case sg::Input::Right:
            if (snakeSize == 1 || MoveDirection::Left != snakeDir)
            {
                m_snake->SetDirection(MoveDirection::Right);
                m_isDirectionChanged = true;
            }
            break;

        default:
            break;
        }

    }
}

