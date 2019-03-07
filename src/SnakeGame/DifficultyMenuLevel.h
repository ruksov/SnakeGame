#pragma once
#include "ILevel.h"
#include "GameState.h"
#include "ItemList.h"

namespace sg
{
    class DifficultyMenuLevel : public ILevel
    {
    public:
        explicit DifficultyMenuLevel(GameState& gameState);

        void Update(Input input) override;
        void Draw() override;

    private:
        void HandleInput(Input input);

    private:
        ItemList m_items;
        GameState& m_gameState;
    };
}


