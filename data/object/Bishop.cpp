#include "Bishop.h"

std::vector<sf::Vector2i> Bishop::getPossibleMove(std::string config[][8])
{
	std::vector<sf::Vector2i> output;
	for (int i = 1; i < 8; i++)
	{
		int x = this->coordinate.x + i;
		int y = this->coordinate.y + i;
		if (x < 0 || x >= 8 || y < 0 || y >= 8)
			break;

		if (config[y][x] == "--")
		{
			output.push_back(sf::Vector2i(x, y));
		}
		else if (config[y][x][0] == this->color)
			break;
		else if (config[y][x][0] != this->color)
		{
			output.push_back(sf::Vector2i(x, y));
		}
	}

	for (int i = 1; i < 8; i++)
	{
		int x = this->coordinate.x - i;
		int y = this->coordinate.y - i;
		if (x < 0 || x >= 8 || y < 0 || y >= 8)
			break;

		if (config[y][x] == "--")
		{
			output.push_back(sf::Vector2i(x, y));
		}
		else if (config[y][x][0] == this->color)
			break;
		else if (config[y][x][0] != this->color)
		{
			output.push_back(sf::Vector2i(x, y));
		}
	}

	for (int i = 1; i < 8; i++)
	{
		int x = this->coordinate.x - i;
		int y = this->coordinate.y + i;
		if (x < 0 || x >= 8 || y < 0 || y >= 8)
			break;

		if (config[y][x] == "--")
		{
			output.push_back(sf::Vector2i(x, y));
		}
		else if (config[y][x][0] == this->color)
			break;
		else if (config[y][x][0] != this->color)
		{
			output.push_back(sf::Vector2i(x, y));
		}
	}

	for (int i = 1; i < 8; i++)
	{
		int x = this->coordinate.x + i;
		int y = this->coordinate.y - i;
		if (x < 0 || x >= 8 || y < 0 || y >= 8)
			break;

		if (config[y][x] == "--")
		{
			output.push_back(sf::Vector2i(x, y));
		}
		else if (config[y][x][0] == this->color)
			break;
		else if (config[y][x][0] != this->color)
		{
			output.push_back(sf::Vector2i(x, y));
		}
	}
	return output;
}