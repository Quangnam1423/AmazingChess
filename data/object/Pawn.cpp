#include "Pawn.h"

std::vector <sf::Vector2i> Pawn::getPossibleMove(std::string config[][8])
{
	std::vector<sf::Vector2i> output;
	if (this->color == 'w')
	{
		int x = this->coordinate.x;
		int y = this->coordinate.y - 1;;
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
			if (config[y][x][0] != this->color)
				output.push_back(sf::Vector2i(x, y));
		}
		x = this->coordinate.x - 1;
		y = this->coordinate.y - 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color)
				output.push_back(sf::Vector2i(x, y));
		}
	}
	else
	{
		int x = this->coordinate.x;
		int y = this->coordinate.y + 1;;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x] == "--")
				output.push_back(sf::Vector2i(x, y));
		}
		if (this->hasMove == false)
		{
			y += 1;
			if (config[y][x] == "--")
			{
				output.push_back(sf::Vector2i(x, y));
			}
		}
		x = this->coordinate.x + 1;
		y = this->coordinate.y + 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color)
				output.push_back(sf::Vector2i(x, y));
		}
		x = this->coordinate.x - 1;
		y = this->coordinate.y + 1;
		if (x >= 0 && x < 8 && y >= 0 && y < 8)
		{
			if (config[y][x][0] != this->color)
				output.push_back(sf::Vector2i(x, y));
		}
	}
	return output;
}