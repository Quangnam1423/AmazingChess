#pragma once

#ifndef PIECE_H
#define PIECE_H
#include <SFML/Graphics.hpp>

class Piece
{
public:
	Piece(std::string notation , sf::Vector2i coordintae , float size , sf::Texture &texture);
	~Piece();
	void print(sf::RenderWindow& window);
	sf::Vector2i getCoordinate();
	void setCoordinate(sf::Vector2i newCoordinate);
	void setPosition(sf::Vector2f newPosition);
	void setPosition(sf::Vector2i newPosition);
	virtual std::vector<sf::Vector2i> getPossibleMove(std::string config[][8]) = 0;

protected:
	char notation;
	char color;
	sf::Vector2i coordinate;
	float size;
	sf::Sprite sprite;
	bool hasMove;
};

#endif