#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

struct SnakeSegment
{
    SnakeSegment( int x, int y ) : position( x, y )
    {
        // Empty body
    }

    sf::Vector2i position;
};

using SnakeContainer = std::vector< SnakeSegment >;

enum class Direction
{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};
