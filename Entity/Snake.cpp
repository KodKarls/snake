#include "Snake.hpp"

Snake::Snake( int blockSize )
{
    size = blockSize;
    body_rect.setSize( sf::Vector2f{static_cast< float >( size - 1 ),
                                    static_cast<float>(size - 1) } );
    reset();
}

void Snake::reset()
{
    snake_body.clear();

    snake_body.emplace_back( 5, 7 );
    snake_body.emplace_back( 5, 6 );
    snake_body.emplace_back( 5, 5 );

    setDirection( Direction::NONE );
    speed = 15;
    lives = 3;
    score = 0;
    lost = false;
}

void Snake::tick()
{
    if( snake_body.empty() )
    {
        return;
    }

    if( direction == Direction::NONE )
    {
        return;
    }

    move();
    checkCollision();
}

void Snake::move()
{
    for( size_t i = snake_body.size() - 1; i > 0; --i )
    {
        snake_body[ i ].position = snake_body[ i - 1 ].position;
    }

    if( direction == Direction::LEFT )
    {
        --snake_body[ 0 ].position.x;
    }
    else if( direction == Direction::RIGHT )
    {
        ++snake_body[ 0 ].position.x;
    }
    else if( direction == Direction::UP )
    {
        --snake_body[ 0 ].position.y;
    }
    else if( direction == Direction::DOWN )
    {
        ++snake_body[ 0 ].position.y;
    }
}

void Snake::checkCollision()
{
    if( snake_body.size() < 5 )
    {
        return;
    }

    SnakeSegment& head = snake_body.front();
    for( auto itr = snake_body.begin() + 1; itr != snake_body.end(); ++itr )
    {
        if( itr->position == head.position )
        {
            int segments = snake_body.end() - itr;
            cut( segments );
            break;
        }
    }
}

void Snake::cut( int segments )
{
    for( int i = 0; i < segments; ++i )
    {
        snake_body.pop_back();
    }

    --lives;
    if( !lives )
    {
        lose();
        return;
    }
}

void Snake::extend()
{
    if( snake_body.empty() )
    {
        return;
    }

    SnakeSegment& tailHead = snake_body[ snake_body.size() - 1 ];
    if( snake_body.size() > 1 )
    {
        SnakeSegment& tailBone = snake_body[ snake_body.size() - 2 ];
        if( tailHead.position.x == tailBone.position.x )
        {
            if( tailHead.position.y > tailBone.position.y )
            {
                snake_body.emplace_back( tailHead.position.x, tailHead.position.y + 1 );
            }
            else
            {
                snake_body.emplace_back( tailHead.position.x, tailHead.position.y - 1 );
            }
        }
        else if( tailHead.position.y == tailBone.position.y )
        {
            if( tailHead.position.x > tailBone.position.x )
            {
                snake_body.emplace_back( tailHead.position.x + 1, tailHead.position.y );
            }
            else
            {
                snake_body.emplace_back( tailHead.position.x - 1, tailHead.position.y );
            }
        }
    }
    else
    {
        if( direction == Direction::UP )
        {
            snake_body.emplace_back( tailHead.position.x, tailHead.position.y + 1 );
        }
        else if( direction == Direction::DOWN )
        {
            snake_body.emplace_back( tailHead.position.x, tailHead.position.y - 1 );
        }
        else if( direction == Direction::LEFT )
        {
            snake_body.emplace_back( tailHead.position.x + 1, tailHead.position.y );
        }
        else if( direction == Direction::RIGHT )
        {
            snake_body.emplace_back( tailHead.position.x - 1, tailHead.position.y );
        }
    }
}

void Snake::setDirection( Direction dir )
{
    direction = dir;
}

Direction Snake::getDirection()
{
    return direction;
}

Direction Snake::getPhysicalDirection()
{
    if( snake_body.size() <= 1 )
    {
        return Direction::NONE;
    }

    SnakeSegment& head = snake_body[ 0 ];
    SnakeSegment& neck = snake_body[ 1 ];

    if( head.position.x == neck.position.x )
    {
        return ( head.position.y > neck.position.y ? Direction::DOWN : Direction::UP );
    }
    else if( head.position.y == neck.position.y )
    {
        return ( head.position.x > neck.position.x ? Direction::RIGHT : Direction::LEFT );
    }

    return Direction::NONE;
}

int Snake::getSpeed() const
{
    return speed;
}

sf::Vector2i Snake::getPosition()
{
    return ( !snake_body.empty() ? snake_body.front().position : sf::Vector2i{ 1, 1 } );
}

int Snake::getLives() const
{
    return lives;
}

int Snake::getScore() const
{
    return score;
}

void Snake::increaseScore()
{
    score += 10;
}

bool Snake::hasLost() const
{
    return lost;
}

void Snake::lose()
{
    lost = true;
}

void Snake::toggleLost()
{
    lost = !lost;
}

void Snake::render( sf::RenderWindow& window )
{
    if( snake_body.empty() )
    {
        return;
    }

    auto head = snake_body.begin();
    body_rect.setFillColor( sf::Color::Yellow );
    body_rect.setPosition( head->position.x * size, head->position.y * size );
    window.draw( body_rect );

    body_rect.setFillColor( sf::Color::Green );
    for( auto itr = snake_body.begin() + 1; itr != snake_body.end(); ++itr )
    {
        body_rect.setPosition( itr->position.x * size, itr->position.y * size );
        window.draw( body_rect );
    }
}
