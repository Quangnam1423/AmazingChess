#include "King.h"

std::vector<sf::Vector2i> King::getPossibleMove(std::string config[][8])
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
	return output;
}