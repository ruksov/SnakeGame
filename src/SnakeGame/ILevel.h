#pragma once
#include "Input.h"

namespace sg
{
    struct ILevel
    {
        virtual ~ILevel() = default;

        virtual void Update(Input input) = 0;
        virtual void Draw() = 0;
    };
}