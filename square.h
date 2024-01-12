#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"
#include <Graphics.hpp>

class square
{
public:
	square(sf::Vector2f position , float &size_square , piece* current_piece);
	void fill_highlight();
	void fill_checkingmate();
	void print_square(sf::RenderWindow& window);
private:
	piece* current_piece;
	sf::Vector2f position , size;
	float size_square;
	std::string color;
	bool highlight;
	bool checkingmate;
	sf::RectangleShape rectangle;
	sf::CircleShape highlight_circle_shape;
};

#endif