#pragma once
#include "ILevel.h"
#include "Board.h"
#include "GameState.h"
#include "Snake.h"
#include "SnakeController.h"

namespace sg
{
    class SnakeLevel : public ILevel
    {
    public:
        explicit SnakeLevel(GameState& gameState);

        void Update(Input input) override;
        void Draw() override;

    private:
        void OnSnakeAction(SnakeAction snakeAction);
        void BuildWalls();
        
        Point GetRandomEmptyPos();
        SnakePtr CreateSnake();

    private:
        size_t m_score = 0;
        size_t m_scoreMultiplier = 0;
        bool m_isGameOver = false;
        GameState& m_gameState;
        Board m_board;
        SnakeController m_snakeCtrl;
    };
}


