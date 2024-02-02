#pragma once

#include "Engine/Window.hpp"

class Game
{
public:
    Game();
    ~Game() = default;

    void handleInput();
    void update();
    void render();

    Window* getWindow();

private:
    void moveCircle( float dt );

    sf::CircleShape circle;
    sf::Vector2i increment;

    Window window;
};
