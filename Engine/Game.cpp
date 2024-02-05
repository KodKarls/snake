#include "Game.hpp"

Game::Game() :
    window( "Chapter 2", sf::Vector2u{ 800, 600 } ),
    world( sf::Vector2u{ 800, 600 } ),
    snake( world.getBlockSize() )
{
    text_box.setup( 5, 14, 350, sf::Vector2f{ 255, 0 } );

    elapsed = 0.0f;
}

void Game::handleInput()
{
    if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) && snake.getPhysicalDirection() != Direction::DOWN )
    {
        snake.setDirection( Direction::UP );
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) && snake.getPhysicalDirection() != Direction::UP )
    {
        snake.setDirection( Direction::DOWN );
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) && snake.getPhysicalDirection() != Direction::RIGHT )
    {
        snake.setDirection( Direction::LEFT );
    }
    else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) && snake.getPhysicalDirection() != Direction::LEFT )
    {
        snake.setDirection( Direction::RIGHT );
    }
}

void Game::update()
{
    window.update();

    float timeStep = 1.0f / snake.getSpeed();

    if( elapsed >= timeStep)
    {
        snake.tick();
        world.update( snake, text_box );
        elapsed -= timeStep;
        if( snake.hasLost() )
        {
            text_box.add( "GAME OVER! Score: " + std::to_string( snake.getScore() ) );
            snake.reset();
            text_box.add( "New game has started..." );
        }
    }
}

void Game::render()
{
    window.beginDraw();

    world.render( *window.getRenderWindow() );
    snake.render( *window.getRenderWindow() );
    text_box.render( *window.getRenderWindow() );

    window.endDraw();
}

Window* Game::getWindow()
{
    return &window;
}

void Game::restartClock()
{
    elapsed += clock.restart().asSeconds();
}
