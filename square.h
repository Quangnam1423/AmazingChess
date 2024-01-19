#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "Piece.h"
#include <Graphics.hpp>

class Square
{
public:
	Square(Piece* piece , sf::Vector2i coordinate ,float size);
	~Square();
	Piece* getPiece();
	void setPiece(Piece* newPiece);
	void setCoordinate(sf::Vector2i coordinate);
	sf::Vector2i getCoordinate();
	void print(sf::RenderWindow& window);

private:
	Piece* currentPiece;
	sf::Vector2i coordinate;
	float size;
	std::string color;
	sf::RectangleShape rectangle;
	sf::CircleShape highlight_circle_shape;

	bool selected , highlight;
};

#endif