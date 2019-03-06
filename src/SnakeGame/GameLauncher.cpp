#include "stdafx.h"
#include "GameLauncher.h"
#include "Game.h"
#include "LevelLoader.h"

namespace sg
{
    void LaunchGame()
    {
        try
        {
            Game game(std::make_unique<LevelLoader>());
            game.Launch();
        }
        catch (const std::exception& ex)
        {
            std::cout << "SNAKE GAME ERROR: " << ex.what() << std::endl;
        }
    }
}

