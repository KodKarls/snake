#include "TextBox.hpp"

TextBox::TextBox()
{
    setup( 5, 9, 200, sf::Vector2f{ 0 , 0 } );
}

TextBox::TextBox( int visible, int charSize, int width, sf::Vector2f screenPos )
{
    setup( visible, charSize, width, screenPos );
}

TextBox::~TextBox()
{
    clear();
}

void TextBox::setup( int visible, int charSize, int width, sf::Vector2f screenPos )
{
    num_visible = visible;

    sf::Vector2f  offset{ 2.0f, 2.0f };

    font.loadFromFile( "Assets/Fonts/Arial.ttf" );
    content.setFont( font );
    content.setString( "" );
    content.setCharacterSize( charSize );
    content.setFillColor( sf::Color::White );
    content.setPosition( screenPos + offset );

    backdoor.setSize( sf::Vector2f{ static_cast< float >( width ), ( visible * ( charSize * 1.2f ) ) } );
    backdoor.setFillColor( sf::Color{ 90, 90, 90, 90 } );
    backdoor.setPosition( screenPos );
}

void TextBox::add( const std::string& message )
{
    messages.push_back( message );

    if( messages.size() < 6 )
    {
        return;
    }
    messages.erase( messages.begin() );
}

void TextBox::clear()
{
    messages.clear();
}

void TextBox::render( sf::RenderWindow& window )
{
    std::string cont;

    for( auto& itr : messages )
    {
        cont.append( itr + "\n" );
    }

    if( !cont.empty() )
    {
        content.setString( cont );
        window.draw( backdoor );
        window.draw( content );
    }
}
