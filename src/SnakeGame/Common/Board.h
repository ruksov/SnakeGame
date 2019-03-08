#pragma once
#include "Point.h"

namespace sg
{
    class Board
    {
    public:
        Board(size_t width, size_t height);

        void SetElement(char value, Point pos);
        char GetElement(Point pos) const;

        std::string FormatBoard() const;

        size_t GetWidth() const;
        size_t GetHeight() const;

    private:
        std::vector<std::vector<char>> m_board;
    };
}

