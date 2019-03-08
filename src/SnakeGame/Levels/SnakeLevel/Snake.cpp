#include "stdafx.h"
#include "Snake.h"

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
        ElementType lookAtElement = board.GetElement(lookAtPoint);

        if (ElementType::Wall == lookAtElement 
            || (ElementType::Snake == lookAtElement && lookAtPoint != m_body.back()))
        {
            action = SnakeAction::Break;
        }
        else if (ElementType::Fruit == lookAtElement)
        {
            action = SnakeAction::EatFruit;
            m_body.push_front(lookAtPoint);
            board.SetElement(ElementType::Snake, lookAtPoint);
        }
        else
        {
            Point prevNodePos = lookAtPoint;
            for (auto& node : m_body)
            {
                Point oldPos = node;
                node = prevNodePos;
                prevNodePos = oldPos;
            }

            board.SetElement(ElementType::Empty, prevNodePos);
            board.SetElement(ElementType::Snake, lookAtPoint);
        }

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