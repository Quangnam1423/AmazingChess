#include "King.h"
#include "Engine.h"

#include <iostream>
#include <vector>

King::King(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture)
	: Piece(notation, coordinate, size, texture)
{

}

std::vector<sf::Vector2i> King::getPossibleMove(std::string config[][8] , Engine* game)
{
	std::vector<sf::Vector2i> output;
	int x = this->coordinate.x;
	int y = this->coordinate.y;
	int move[8][2] = {
		{-1 , -1},
		{0 , -1},
		{1 , -1},
		{1 , 0},
		{1 , 1},
		{0 , 1},
		{-1 , 1},
		{-1 , 0}
	};
	for (int i = 0; i < 8; i++)
	{
		int h = x + move[i][0];
		int k = y + move[i][1];
		if (h >= 0 && h < 8 && k >= 0 && k < 8)
		{
			if (config[k][h] == "--")
				output.push_back(sf::Vector2i(h, k));
			else if (config[k][h][0] != this->color)
			{
				output.push_back(sf::Vector2i(h, k));
			}
		}
	}
	if (this->hasMove == false && this->color == game->getTurn() && game->Is_In_Check())
	{
		if (config[this->coordinate.y][0][0] == this->color && config[this->coordinate.y][0][1] == 'r')
		{
			bool check = true;
			sf::Vector2i rook_pos(0, this->coordinate.y);
			Square* leftrook = game->getSquareFromCoord(rook_pos);
			Piece* temp = leftrook->getPiece();
			if (temp->getStatus() == true)
				check = false;
			if (game->Is_In_Check(this->coordinate.x - 1, this->coordinate.y) == false)
				check = false;
			if (config[this->coordinate.y][this->coordinate.x - 1] != "--")
				check = false;
			if (config[this->coordinate.y][this->coordinate.x - 2] != "--")
				check = false;
			if (game->Is_In_Check(this->coordinate.x - 2, this->coordinate.y) == false)
				check = false;
			if (check)
			{
				output.push_back(sf::Vector2i(this->coordinate.x - 2, this->coordinate.y));
			}

		}
		if (config[this->coordinate.y][7][0] == this->color && config[this->coordinate.y][7][1] == 'r')
		{
			bool check = true;
			sf::Vector2i rook_pos(7, this->coordinate.y);
			Square* rightrook = game->getSquareFromCoord(rook_pos);
			Piece* temp = rightrook->getPiece();
			if (temp->getStatus() == true)
				check = false;
			if (game->Is_In_Check(this->coordinate.x + 1, this->coordinate.y) == false)
				check = false;
			if (game->Is_In_Check(this->coordinate.x + 2, this->coordinate.y) == false)
				check = false;
			if (config[this->coordinate.y][this->coordinate.x + 1] != "--")
				check = false;
			if (config[this->coordinate.y][this->coordinate.x + 2] != "--")
				check = false;
			if (check)
			{
				output.push_back(sf::Vector2i(this->coordinate.x + 2, this->coordinate.y));
			}
			
		}
	}
	return output;
}