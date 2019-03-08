#include "stdafx.h"
#include "Board.h"

namespace sg
{
    Board::Board(size_t width, size_t height)
        : m_board(height)
    {
        for (auto& row : m_board)
        {
            row.resize(width, ' ');
        }
    }

    void Board::SetElement(char value, Point pos)
    {
        m_board.at(pos.Y).at(pos.X) = value;
    }

    char Board::GetElement(Point pos) const
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
                os << el;
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