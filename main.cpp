#include <Graphics.hpp>
#include <Audio.hpp>
#include <Network.hpp>
#include <iostream>
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
    GameEngine game(size_square, true);

    bool getPiece = false , selectingMoving = false;
    square* ptrSelectedSquare = nullptr , * ptrMovingSquare = nullptr;
    piece* ptrSelectedPiece = nullptr;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << getPiece << std::endl;
                if (getPiece == false)
                {
                    ptrSelectedSquare = game.getSquareFromMouse(sf::Mouse::getPosition(window));
                    if (ptrSelectedSquare != nullptr)
                    {
                        ptrSelectedPiece = ptrSelectedSquare->getCurrentPiece();
                        getPiece = true;
                    }
                    else
                    {
                        ptrSelectedSquare = nullptr;
                    }
                }
                else
                {
                    ptrMovingSquare = game.getSquareFromMouse(sf::Mouse::getPosition(window));
                    if (ptrMovingSquare != nullptr && ptrMovingSquare != ptrSelectedSquare)
                    {
                        game.Completion(ptrSelectedSquare, ptrMovingSquare, ptrSelectedPiece);
                    }
                    getPiece = false;
                }
            }
        }

        window.clear();
        game.Print(window);
        window.display();
    }

    return 0;
}