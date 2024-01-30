#include "Knight.h"


Knight::Knight(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture)
	: Piece(notation, coordinate, size, texture)
{

}

std::vector<sf::Vector2i> Knight::getPossibleMove(std::string config[][8] , Engine *game)
{
	std::vector<sf::Vector2i> output;
	int x = this->coordinate.x;
	int y = this->coordinate.y;
	int move[8][2] = {
		{-2 , -1},
		{-1 , -2},
		{1 , -2},
		{2 , -1},
		{2 , 1},
		{1 , 2},
		{-1 , 2},
		{-2 , 1}
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
	return output;
}