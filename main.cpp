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
    GameEngine game(size_square, true);

    bool getPiece = false;
    square* ptrSelectedSquare = nullptr;
    piece* ptrSelectedPiece = nullptr;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && getPiece == false)
            {
                ptrSelectedSquare = game.getSquareFromMouse(sf::Mouse::getPosition(window));
                ptrSelectedPiece = ptrSelectedSquare->getCurrentPiece();
                if (ptrSelectedPiece == nullptr)
                {
                    ptrSelectedPiece = nullptr;
                    ptrSelectedSquare = nullptr;
                }
                else
                    getPiece = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased && getPiece == true)
            {
                square* ptrMoveSquare = game.getSquareFromMouse(sf::Mouse::getPosition(window));
                if (ptrMoveSquare != ptrSelectedSquare)
                {
                    game.Completion(ptrSelectedSquare, ptrMoveSquare , ptrSelectedPiece);
                }
                ptrSelectedPiece = nullptr;
                ptrSelectedSquare = nullptr;
                getPiece = false;
            }
        }

        window.clear();
        game.Print(window);
        window.display();
    }

    return 0;
}