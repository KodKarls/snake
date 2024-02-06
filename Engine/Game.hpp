#pragma once

#include "Engine/Window.hpp"

#include "Entity/Snake.hpp"
#include "Entity/TextBox.hpp"
#include "World/World.hpp"

class Game
{
public:
    Game();
    ~Game() = default;

    void handleInput();
    void update();
    void render();

    void restartClock();

    Window* getWindow();

private:
    sf::Clock clock;
    float elapsed;

    Window window;
    World world;
    Snake snake;
    TextBox text_box;
};
