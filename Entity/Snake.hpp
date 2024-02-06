#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Entity/SnakeStructure.hpp"

class Snake
{
public:
    explicit Snake( int blockSize );
    ~Snake() = default;

    void tick();
    void move();
    void cut( int segments );

    void reset();
    void extend();

    void setDirection( Direction dir );
    Direction getDirection();
    Direction getPhysicalDirection();

    int getSpeed() const;
    sf::Vector2i getPosition();

    int getLives() const;
    int getScore() const;
    void increaseScore();

    void lose();
    void toggleLost();
    bool hasLost() const;

    void render( sf::RenderWindow& window );

private:
    void checkCollision();

    sf::RectangleShape body_rect;

    SnakeContainer snake_body;
    int size;
    Direction direction{ Direction::NONE };
    int speed{ 15 };
    int lives{ 3 };
    int score{ 0 };
    bool lost{ false };
};
