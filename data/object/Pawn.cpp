#include "Pawn.h"
#include "Engine.h"


#include <iostream>

Pawn::Pawn(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture)
	: Piece(notation, coordinate, size, texture)
{
	this->double_move = false;
}

std::vector <sf::Vector2i> Pawn::getPossibleMove(std::string config[][8] , Engine *game)
{
	std::vector<sf::Vector2i> output;
	if (this->color == 'w')
	{

		int x = this->coordinate.x;
		int y = this->coordinate.y - 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x] == "--")
				output.push_back(sf::Vector2i(x, y));
		}
		if (this->hasMove == false)
		{
			y -= 1;
			if (config[y][x] == "--")
			{
				output.push_back(sf::Vector2i(x, y));
			}
		}
		x = this->coordinate.x + 1;
		y = this->coordinate.y - 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color && config[y][x] != "--")
				output.push_back(sf::Vector2i(x, y));
		}
		x = this->coordinate.x - 1;
		y = this->coordinate.y - 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color && config[y][x] != "--")
				output.push_back(sf::Vector2i(x, y));
		}
		// bat tot qua song 
		if (config[coordinate.y][coordinate.x - 1] == "bp")
		{
			Square* sq = game->getSquareFromCoord(sf::Vector2i(coordinate.x - 1, coordinate.y));
			Piece* pi = sq->getPiece();
			if (Pawn* check = dynamic_cast<Pawn*> (pi))
			{
				if (check->getDoubleMove() == true)
					output.push_back(sf::Vector2i(coordinate.x - 1, coordinate.y - 1));
			}
		}

		if (config[coordinate.y][coordinate.x + 1] == "bp")
		{
			Square* sq = game->getSquareFromCoord(sf::Vector2i(coordinate.x + 1, coordinate.y));
			Piece* pi = sq->getPiece();
			if (Pawn* check = dynamic_cast<Pawn*> (pi))
			{
				if (check->getDoubleMove() == true)
					output.push_back(sf::Vector2i(coordinate.x + 1, coordinate.y - 1));
			}
		}

	}
	else
	{
		int x = this->coordinate.x;
		int y = this->coordinate.y + 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x] == "--")
				output.push_back(sf::Vector2i(x, y));
		}
		if (this->hasMove == false)
		{
			y = y + 1;
			if (config[y][x] == "--")
			{
				output.push_back(sf::Vector2i(x, y));
			}
		}
		x = this->coordinate.x + 1;
		y = this->coordinate.y + 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color && config[y][x] != "--")
				output.push_back(sf::Vector2i(x, y));
		}
		x = this->coordinate.x - 1;
		y = this->coordinate.y + 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color && config[y][x] != "--") 
				output.push_back(sf::Vector2i(x, y));
		}
		// bat tot qua song
		if (coordinate.x - 1 >= 0 && coordinate.x - 1 <= 7 && config[coordinate.y][coordinate.x - 1] == "wp")
		{
			Square* sq = game->getSquareFromCoord(sf::Vector2i(coordinate.x - 1, coordinate.y));
			Piece* pi = sq->getPiece();
			if (Pawn* check = dynamic_cast<Pawn*> (pi))
			{
				if (check->getDoubleMove() == true)
					output.push_back(sf::Vector2i(coordinate.x - 1, coordinate.y + 1));
			}
		}

		if (coordinate.x + 1 >= 0 && coordinate.x + 1 <= 7 && config[coordinate.y][coordinate.x + 1] == "wp")
		{
			Square* sq = game->getSquareFromCoord(sf::Vector2i(coordinate.x + 1, coordinate.y));
			Piece* pi = sq->getPiece();
			if (Pawn* check = dynamic_cast<Pawn*> (pi))
			{
				if (check->getDoubleMove() == true)
					output.push_back(sf::Vector2i(coordinate.x + 1, coordinate.y + 1));
			}
		}

	}

	return output;
}

void Pawn::setCoordinate(sf::Vector2i newCoordinate, bool value)
{
	if (abs(this->coordinate.y - newCoordinate.y) == 2)
	{
		this->double_move = true;
	}
	Piece::setCoordinate(newCoordinate, value);
}

void Pawn::update_DoubleMove(bool value)
{
	this->double_move = value;
	return;
}

bool Pawn::getDoubleMove()
{
	return this->double_move;
}