#include "World.hpp"

World::World( sf::Vector2u windSize )
{
    block_size = 16;
    window_size = windSize;

    respawnApple();
    apple_shape.setFillColor( sf::Color::Red );
    apple_shape.setRadius( block_size * 0.5 );

    for( int i = 0; i < 4; ++i )
    {
        bounds[ i ].setFillColor( sf::Color{ 150, 0, 0 } );
        if( !( ( i + 1 ) % 2 ) )
        {
            bounds[ i ].setSize( sf::Vector2f{ static_cast< float >( window_size.x ),
                                               static_cast< float >( block_size ) } );
        }
        else
        {
            bounds[ i ].setSize( sf::Vector2f{static_cast< float >( block_size ),
                                              static_cast< float >( window_size.y ) } );
        }
        if( i < 2 )
        {
            bounds[ i ].setPosition( 0,0 );
        }
        else
        {
            bounds[ i ].setOrigin( bounds[ i ].getSize() );
            bounds[ i ].setPosition( sf::Vector2f{ window_size } );
        }
    }
}

void World::respawnApple()
{
    int maxX = window_size.x / block_size - 2;
    int maxY = window_size.y / block_size - 2;

    item = sf::Vector2i{ rand() % maxX + 1, rand() % maxY + 1 };
    apple_shape.setPosition( item.x * block_size, item.y * block_size );
}

void World::update( Snake& player )
{
    if( player.getPosition() == item )
    {
        player.extend();
        player.increaseScore();
        respawnApple();
    }

    int gridSizeX = window_size.x / block_size;
    int gridSizeY = window_size.y / block_size;

    if( player.getPosition().x <= 0 || player.getPosition().y <= 0 ||
        player.getPosition().x >= gridSizeX - 1 || player.getPosition().y >= gridSizeY - 1 )
    {
        player.lose();
    }
}

void World::render( sf::RenderWindow& window )
{
    for(const auto & bound : bounds)
    {
        window.draw( bound );
    }
    window.draw( apple_shape );
}

int World::getBlockSize() const
{
    return block_size;
}
