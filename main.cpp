#include <Graphics.hpp>
#include <Audio.hpp>
#include <Network.hpp>
#include "square.h"

/*
* tiep theo day se la nhung define ve size man hinh, size kich thuoc con co ... vv
*/

float screen_width = 800.0f;
float screen_height = 800.0f;
sf::Vector2f size_square(screen_width / 8, screen_height / 8);
sf::Vector2f size_board(screen_width, screen_height);


int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height), "AmaZing Chess");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}