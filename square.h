#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include <Graphics.hpp>

class square
{
public:
	square(sf::Vector2f position , float &size_square);
	void fill_highlight();
	void fill_checkingmate();
	void print_square(sf::RenderWindow& window);
private:
	sf::Vector2f position , size;
	float size_square;
	std::string color;
	bool highlight;
	bool checkingmate;
	sf::RectangleShape rectangle;
	sf::CircleShape highlight_circle_shape;
};

#endif