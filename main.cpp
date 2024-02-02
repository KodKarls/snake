#include "Engine/Game.hpp"

int main()
{
    Game game;

    while( !game.getWindow()->isDone() )
    {
        game.handleInput();
        game.update();
        game.render();
        game.restartClock();
    }

    return 0;
}