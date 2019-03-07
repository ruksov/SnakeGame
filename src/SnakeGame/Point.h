#pragma once

namespace sg
{
    struct Point
    {
        size_t X = 0;
        size_t Y = 0;

    public:
        Point() = default;

        Point(size_t x, size_t y)
            : X(x)
            , Y(y)
        {
        }

        bool operator==(const Point& p)
        {
            return X == p.X && Y == p.Y;
        }

        bool operator!=(const Point& p)
        {
            return !operator==(p);
        }
    };
}