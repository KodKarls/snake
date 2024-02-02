#include "Game.hpp"

#include "Timer/Timer.hpp"

Game::Game() : window( "Chapter 2", sf::Vector2u{ 800, 600 } )
{
    circle.setRadius( 50 );
    circle.setFillColor( sf::Color::Green );
    increment = sf::Vector2i{ 400, 400 };
}

void Game::handleInput()
{
    // Empty body
}

void Game::update()
{
    window.update();

    float deltaTime = Timer::get()->getDeltaTime();
    moveCircle( deltaTime );
}

void Game::moveCircle( float dt )
{
    sf::Vector2u windSize = window.getWindowSize();
    auto textSize = circle.getRadius() * 2;

    if( ( circle.getPosition().x > windSize.x - textSize && increment.x > 0 ) ||
        circle.getPosition().x < 0 && increment.x < 0 )
    {
        increment.x = -increment.x;
    }

    if( ( circle.getPosition().y > windSize.y - textSize && increment.y > 0 ) ||
        circle.getPosition().y < 0 && increment.y < 0 )
    {
        increment.y = -increment.y;
    }

    circle.setPosition( circle.getPosition().x + increment.x * dt,
                        circle.getPosition().y + increment.y * dt );
}

void Game::render()
{
    window.beginDraw();

    window.draw( circle );

    window.endDraw();
}

Window* Game::getWindow()
{
    return &window;
}
