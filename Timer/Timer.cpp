#include "Timer.hpp"

Timer* Timer::instance = nullptr;

Timer::Timer()
{
    delta_time = clock.restart().asSeconds();
}

void Timer::tick()
{
    delta_time = clock.restart().asSeconds();

    if( delta_time < TIME_PER_FRAME.asSeconds() )
    {
        sf::sleep( TIME_PER_FRAME - sf::seconds( delta_time ) );
    }
}
