#include "stdafx.h"
#include "Snake.h"

#include "MapElement.h"
#include "Common/Exceptions.h"

namespace sg
{
    Snake::Snake(MoveDirection startDir, Point startPos, OnSnakeActionCb onActionCb)
        : m_dir(startDir)
        , m_body({startPos})
        , m_onActionCb(onActionCb)
    {
        THROW_IF(!m_onActionCb, "Failed to construct snake: On action callback can't be NULL");
    }

    void Snake::SetDirection(MoveDirection newDir)
    {
        m_dir = newDir;
    }

    MoveDirection Snake::GetDirection() const
    {
        return m_dir;
    }

    size_t Snake::GetSize() const
    {
        return m_body.size();
    }

    void Snake::Move(Board & board)
    {
        auto action = SnakeAction::Move;
        Point lookAtPoint = GetLookAtPoint();
        char lookAtElement = board.GetElement(lookAtPoint);

        if (MapElement_Wall == lookAtElement
            || (MapElement_Snake == lookAtElement && lookAtPoint != m_body.back()))
        {
            //
            // Snake colides with wall or snake body.
            // We skip coliding with snake tail, because in this 
            // frame the tail changes it's position.
            //
            action = SnakeAction::Break;
        }
        else if (MapElement_Fruit == lookAtElement)
        {
            //
            // The snake eats fruit, so we can to increase size of our snake.
            // We just set snake node to fruit position.
            //
            action = SnakeAction::EatFruit;
            m_body.push_front(lookAtPoint);
            board.SetElement(MapElement_Snake, lookAtPoint);
        }
        else
        {
            //
            // This is standard moving of snake.
            //
            Point prevNodePos = lookAtPoint;
            for (auto& node : m_body)
            {
                Point oldPos = node;
                node = prevNodePos;
                prevNodePos = oldPos;
            }

            board.SetElement(MapElement_Empty, prevNodePos);
            board.SetElement(MapElement_Snake, lookAtPoint);
        }

        //
        // Send to some subscriber current snake action.
        //
        m_onActionCb(action);
    }

    Point Snake::GetLookAtPoint()
    {
        Point lookAtPoint = m_body.front();
        switch (m_dir)
        {
        case MoveDirection::Up:
            --lookAtPoint.Y;
            break;

        case MoveDirection::Left:
            --lookAtPoint.X;
            break;

        case MoveDirection::Down:
            ++lookAtPoint.Y;
            break;

        case MoveDirection::Right:
            ++lookAtPoint.X;
            break;

        default:
            THROW("Failed to get look at point in snake object: Invalid value of move direction " << static_cast<size_t>(m_dir));
            break;
        }

        return lookAtPoint;
    }
}