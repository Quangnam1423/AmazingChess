#include <Graphics.hpp>
#include <Audio.hpp>
#include <Network.hpp>

/*
* tiep theo day se la nhung define ve size man hinh, size kich thuoc con co ... vv
*/

float screen_width = 800.0f, screen_height = 800.0f;


int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height), "AmaZing Chess");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}