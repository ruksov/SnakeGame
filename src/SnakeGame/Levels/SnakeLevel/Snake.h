#pragma once
#include "Common/Board.h"

namespace sg
{
    enum class MoveDirection
    {
        Undefined,
        Up,
        Left,
        Down,
        Right
    };

    enum class SnakeAction
    {
        Move,
        EatFruit,
        Break
    };

    using OnSnakeActionCb = std::function<void(SnakeAction)>;

    class Snake
    {
    public:
        Snake(MoveDirection startDir, Point startPos, OnSnakeActionCb onActionCb);

        void SetDirection(MoveDirection newDir);
        MoveDirection GetDirection() const;

        size_t GetSize() const;

        void Move(Board& board);

    private:
        Point GetLookAtPoint();

    private:
        MoveDirection m_dir;
        std::deque<Point> m_body;
        OnSnakeActionCb m_onActionCb;
    };
}