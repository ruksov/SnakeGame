#pragma once
#include "Common/Input.h"
#include "GameBase/GameEvent.h"

namespace sg
{
    using LevelPtr = std::unique_ptr<struct ILevel>;

    struct ILevel
    {
        virtual ~ILevel() = default;

        virtual void Update(Input input) = 0;
        virtual void Draw() = 0;
    };
}