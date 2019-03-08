#include "stdafx.h"
#include "Board.h"

namespace sg
{
    Board::Board(size_t width, size_t height)
        : m_board(height)
    {
        for (auto& row : m_board)
        {
            row.resize(width);
        }
    }

    void Board::SetElement(ElementType value, Point pos)
    {
        m_board.at(pos.Y).at(pos.X) = value;
    }

    ElementType Board::GetElement(Point pos) const
    {
        return m_board.at(pos.Y).at(pos.X);
    }

    std::string Board::FormatBoard() const
    {
        std::ostringstream os;
        for (auto& raw : m_board)
        {
            for (auto el : raw)
            {
                switch (el)
                {
                case ElementType::Empty:
                    os << ' ';
                    break;

                case ElementType::Fruit:
                    os << 'F';
                    break;

                case ElementType::Snake:
                    os << 'o';
                    break;

                case ElementType::Wall:
                    os << '#';
                    break;

                default:
                    throw std::runtime_error("Unknown element type");
                    break;
                }
            }
            os << '\n';
        }
        return os.str();
    }

    size_t Board::GetWidth() const
    {
        return m_board.empty() ? 0 : m_board.front().size();
    }

    size_t Board::GetHeight() const
    {
        return m_board.size();
    }
}