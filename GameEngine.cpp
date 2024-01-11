#include "GameEngine.h"
#include <Graphics.hpp>

GameEngine::GameEngine(float size_square, bool go_first)
{
	this->turn = go_first;
	for (int i = 0 ; i < 8 ; i += 1)
		for (int j = 0 ; j < 8 ; j += 1)
		{
			sf::Vector2f temp((float)j, (float)i);
			this->squares.push_back(new square(temp, size_square));
		}
}
GameEngine::~GameEngine()
{
	for (square* x : this->squares)
		delete x;
}

void GameEngine::Print(sf::RenderWindow& window)
{
	for (square* x : this->squares)
	{
		x->print_square(window);
	}
}