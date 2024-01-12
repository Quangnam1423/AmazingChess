#include <Graphics.hpp>
#include <Audio.hpp>
#include <Network.hpp>
#include "square.h"
#include "GameEngine.h"

/*
* tiep theo day se la nhung define ve size man hinh, size kich thuoc con co ... vv
*/

float screen_width = 800.0f;
float screen_height = 800.0f;
float size_square = screen_height / 8;


int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_width , screen_height), "AmaZing Chess");
    window.setFramerateLimit(60);
    GameEngine newgame(size_square, true);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        newgame.Print(window);
        window.display();
    }

    return 0;
}