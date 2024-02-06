#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

using MessageContainer = std::vector< std::string >;

class TextBox
{
public:
    TextBox();
    TextBox( int visible, int charSize, int width, sf::Vector2f screenPos );
    ~TextBox();

    void setup( int visible, int charSize, int width, sf::Vector2f screenPos );
    void add( const std::string& message );
    void clear();

    void render( sf::RenderWindow& window );

private:
    sf::RectangleShape backdoor;
    sf::Font font;
    sf::Text content;

    MessageContainer messages;
    int num_visible{ 0 };
};
