#pragma once

#include <SFML/Graphics.hpp>

const int TARGET_FPS = 60.f;
const sf::Time TIME_PER_FRAME = sf::seconds( 1.0f / TARGET_FPS );

class Timer
{
public:
    inline static Timer* get()
    {
        return instance = ( instance != nullptr ) ? instance : new Timer();
    }

    void tick();

    inline float getDeltaTime() const
    {
        return delta_time;
    }

private:
    static Timer* instance;

    Timer();

    sf::Clock clock;
    float delta_time;
};
