#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"
#include <Graphics.hpp>

class square
{
public:
	square(sf::Vector2i coordintae , float &size_square , piece* current_piece);
	~square();
	void fill_highlight();
	void fill_checkingmate();
	void print(sf::RenderWindow& window);
	void setCurrentPiece(piece* newPiece);
	piece* getCurrentPiece();
	sf::Vector2i getCoordinate();
private:
	piece* currentPiece;
	sf::Vector2i coordinate;
	sf::Vector2f size;
	float size_square;
	std::string color;
	sf::RectangleShape rectangle;
	sf::CircleShape highlight_circle_shape;

	bool checkingmate, highlight;
};

#endif