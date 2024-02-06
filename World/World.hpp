#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Entity/Snake.hpp"
#include "Entity/TextBox.hpp"

class World
{
public:
    explicit World( sf::Vector2u windSize );
    ~World() = default;

    void respawnApple();

    void update( Snake& player, TextBox& textBox );
    void render( sf::RenderWindow& window );

    int getBlockSize() const;

private:
    sf::Vector2u window_size;
    sf::Vector2i item;
    int block_size;

    sf::CircleShape apple_shape;
    sf::RectangleShape bounds[ 4 ];
};
