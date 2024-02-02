#include "Engine/Game.hpp"
#include "Timer/Timer.hpp"

int main()
{
    Game game;

    while( !game.getWindow()->isDone() )
    {
        game.handleInput();
        Timer::get()->tick();
        game.update();
        game.render();
    }

    return 0;
}