#pragma once
#include "Snake.h"
#include "Input.h"
#include "GameState.h"

namespace sg
{
    using SnakePtr = std::unique_ptr<Snake>;

    class SnakeController
    {
    public:
        SnakeController(Board& board, size_t gameFps, Difficulty difficulty);
        
        void Update(Input input);
        void SetSnake(SnakePtr snake);

    private:
        void HandleInput(Input input);

    private:
        Board& m_board;
        SnakePtr m_snake;
        size_t m_gameFps = 0;
        size_t m_framesDivider = 0;
        size_t m_framesFromLastMove = 0;
        bool m_isDirectionChanged = false;
    };
}


