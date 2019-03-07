#include "stdafx.h"
#include "SnakeLevel.h"

namespace sg
{
    SnakeLevel::SnakeLevel(GameState & gameState)
        : m_gameState(gameState)
        , m_board(22, 22)
        , m_snakeCtrl(m_board, m_gameState.GetFps(), m_gameState.GetDifficulty())
    {
        switch (gameState.GetDifficulty())
        {
        case Difficulty::Easy:
            m_scoreMultiplier = 1;
            break;

        case Difficulty::Normal:
            m_scoreMultiplier = 2;
            break;

        case Difficulty::Hard:
            m_scoreMultiplier = 4;
            break;

        default:
            break;
        }

        BuildWalls();
        m_board.SetElement(ElementType::Fruit, GetRandomEmptyPos());
        m_snakeCtrl.SetSnake(CreateSnake());
    }

    void SnakeLevel::Update(Input input)
    {
        m_snakeCtrl.Update(input);
    }

    void SnakeLevel::Draw()
    {
        std::cout << m_board.FormatBoard()
            << "\n score: " << m_score
            << "\n high score: " << m_gameState.GetHighScore();
    }

    void SnakeLevel::OnSnakeAction(SnakeAction snakeAction)
    {
        switch (snakeAction)
        {
        case sg::SnakeAction::Move:
            break;
        case sg::SnakeAction::EatFruit:
            m_score += 10 * m_scoreMultiplier;
            m_board.SetElement(ElementType::Fruit, GetRandomEmptyPos());
            break;

        case sg::SnakeAction::Break:
            //
            // Game over. Save score and send event to load game over level.
            //
            m_gameState.SetLastScore(m_score);
            m_gameState.Notify(GameEvent::LoadMainMenu);
            break;

        default:
            break;
        }
    }

    void SnakeLevel::BuildWalls()
    {
        const size_t width = m_board.GetWidth();
        const size_t height = m_board.GetHeight();

        auto setWallFn = [&board = m_board, width, height](Point p, bool isGrowX)
        {
            auto& growCoord = isGrowX ? p.X : p.Y;
            
            for (; p.X < width && p.Y < height; ++growCoord)
            {
                board.SetElement(ElementType::Wall, p);
            }
        };

        setWallFn({ 0, 0 }, true);              // first raw
        setWallFn({ 0, 1 }, false);             // first collumn
        setWallFn({ 1, height - 1 }, true);     // last raw
        setWallFn({ width - 1, 1 }, false);     // last collumn

    }

    Point SnakeLevel::GetRandomEmptyPos()
    {
        Point emptyPos;
        while (ElementType::Empty != m_board.GetElement(emptyPos))
        {
            emptyPos.X = std::rand() % m_board.GetWidth();
            emptyPos.Y = std::rand() % m_board.GetHeight();
        }
        return emptyPos;
    }

    SnakePtr SnakeLevel::CreateSnake()
    {
        Point startPoint = GetRandomEmptyPos();
        const Point centerPoint(m_board.GetWidth() / 2, m_board.GetHeight() / 2);

        int xDelta = startPoint.X - centerPoint.X;
        int yDelta = startPoint.Y - centerPoint.Y;

        //
        // Set direction to move from the nearest wall.
        //
        MoveDirection startDir = MoveDirection::Undefined;
        
        if (startPoint == centerPoint)
        {
            //
            // Snake was generated in center, so we generate random direction.
            //
            startDir = static_cast<MoveDirection>((std::rand() % 4) + 1);
        }
        if (xDelta > yDelta)
        {
            startDir = xDelta > 0 ? MoveDirection::Left : MoveDirection::Right;
        }
        else
        {
            startDir = yDelta > 0 ? MoveDirection::Up : MoveDirection::Down;
        }

        return std::make_unique<Snake>(startDir, startPoint, [this](auto action) { OnSnakeAction(action); });
    }
}
