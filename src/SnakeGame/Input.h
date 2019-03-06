#pragma once

namespace sg
{
    enum class Input
    {
        Undefined = 0,
        Up = 'W',
        Left = 'A',
        Down = 'S',
        Right = 'D',
        Enter = '\r',
        Esc = '\x1b'
    };
}