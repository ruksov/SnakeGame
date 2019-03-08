#pragma once
#include "ILevel.h"
#include "Common/ItemList.h"
#include "GameBase/GameState.h"

namespace sg
{
    class GameOverMenuLevel : public ILevel
    {
    public:
        explicit GameOverMenuLevel(GameState& gameState);

        void Update(Input input) override;
        void Draw() override;

    private:
        void HandleInput(Input input);

    private:
        ItemList m_items;
        GameState& m_gameState;
    };
}


