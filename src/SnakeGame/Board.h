#pragma once
#include "Point.h"

namespace sg
{
    enum class ElementType
    {
        Empty,
        Wall,
        Fruit,
        Snake
    };

    class Board
    {
    public:
        Board(size_t width, size_t height);

        void SetElement(ElementType value, Point pos);
        ElementType GetElement(Point pos) const;

        std::string FormatBoard() const;

        size_t GetWidth() const;
        size_t GetHeight() const;

    private:
        std::vector<std::vector<ElementType>> m_board;
    };
}

