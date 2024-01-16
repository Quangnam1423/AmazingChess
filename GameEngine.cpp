#include "GameEngine.h"
#include "piece.h"
#include <Graphics.hpp>
#include <math.h>

GameEngine::GameEngine(float size_square, bool go_first)
{
	this->turn = go_first;
	this->endgame = false;
	for (int i = 0 ; i < 8 ; i += 1)
		for (int j = 0 ; j < 8 ; j += 1)
		{
			std::string notation = get_notation(config[i][j]);
			sf::Vector2i temp(j,i);
			piece* ptr_piece;
			if (notation != "null")
				ptr_piece = new piece(temp , size_square ,  notation);
			else
				ptr_piece = nullptr;
			this->squares.push_back(new square(temp, size_square , ptr_piece));
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
		x->print(window);
	}
	return;
}

square* GameEngine::getSquareFromMouse(sf::Vector2i mousePosition)
{
	int x = (int) mousePosition.y / this->square_size;
	int y = (int) mousePosition.x / this->square_size;
	for (square* ptr_square : squares)
	{
		sf::Vector2i temp = ptr_square->getCoordinate();
		if (temp.x == x && temp.y == y)
		{
			return ptr_square;
		}
	}
	return nullptr;
}

void GameEngine::Completion(square* ptrSelectedSquare, square* ptrMoveSquare , piece* ptrSelectedPiece)
{
	ptrSelectedSquare->setCurrentPiece(ptrMoveSquare->getCurrentPiece());
	ptrMoveSquare->setCurrentPiece(ptrSelectedPiece);
	return;
}

std::string get_notation(int i)
{
	if (i == 0) return "null";
	else
	{
		std::string ans = "";
		if (abs(i) == 1) ans += 'p';
		if (abs(i) == 2) ans += 'r';
		if (abs(i) == 3) ans += 'n';
		if (abs(i) == 4) ans += 'b';
		if (abs(i) == 5) ans += 'q';
		if (abs(i) == 6) ans += 'k';
		if (i > 0)
			ans = 'w' + ans;
		else
			ans = 'b' + ans;
		return ans;
	}
}