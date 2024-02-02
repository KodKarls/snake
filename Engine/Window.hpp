#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    Window( const std::string& title, const sf::Vector2u& size );
    ~Window();

    void update();

    void beginDraw();
    void draw( sf::Drawable& drawable );
    void endDraw();

    void toggleFullscreen();

    bool isFullscreen() const;
    bool isDone() const;

    sf::Vector2u  getWindowSize();

    sf::RenderWindow* getRenderWindow();

private:
    void setup( const std::string& title, const sf::Vector2u& size );

    void create();
    void destroy();

    bool is_done{ false };
    bool is_fullscreen{ false };

    std::string window_title;
    sf::Vector2u window_size;
    sf::RenderWindow window;
};
