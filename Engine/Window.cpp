#include "Window.hpp"

Window::Window()
{
    setup( "Window", sf::Vector2u( 640, 480 ) );
}

Window::Window( const std::string& title, const sf::Vector2u& size )
{
    setup( title, size );
}

Window::~Window()
{
    destroy();
}

void Window::setup( const std::string& title, const sf::Vector2u& size )
{
    window_title = title;
    window_size = size;
    is_fullscreen = false;
    is_done = false;
    create();
}

void Window::create()
{
    auto style = ( is_fullscreen ? sf::Style::Fullscreen : sf::Style::Default );
    window.create( { window_size.x, window_size.y, 32 }, window_title, style );
}

void Window::destroy()
{
    window.close();
}

void Window::update()
{
    sf::Event event{};

    while( window.pollEvent( event ) )
    {
        if( event.type == sf::Event::Closed )
        {
            is_done = true;
        }
        else if( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5 )
        {
            toggleFullscreen();
        }
    }
}

void Window::toggleFullscreen()
{
    is_fullscreen = !is_fullscreen;
    destroy();
    create();
}

void Window::beginDraw()
{
    window.clear( sf::Color::Black );
}

void Window::draw( sf::Drawable& drawable )
{
    window.draw( drawable );
}

void Window::endDraw()
{
    window.display();
}

bool Window::isFullscreen() const
{
    return is_fullscreen;
}

bool Window::isDone() const
{
    return is_done;
}

sf::Vector2u Window::getWindowSize()
{
    return window_size;
}

sf::RenderWindow* Window::getRenderWindow()
{
    return &window;
}
