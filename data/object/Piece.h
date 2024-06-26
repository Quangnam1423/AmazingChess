#pragma once

#ifndef PIECE_H
#define PIECE_H
#include <SFML/Graphics.hpp>

class Engine;

class Piece
{
public:
	Piece(std::string notation , sf::Vector2i coordintae , float size , sf::Texture *texture);
	~Piece();
	void print(sf::RenderWindow& window);
	sf::Vector2i getCoordinate();
	virtual void setCoordinate(sf::Vector2i newCoordinate , bool value = true);
	void setPosition(sf::Vector2f newPosition);
	void setPosition(sf::Vector2i newPosition);
	char getColor();
	char getNotation();
	bool getStatus();
	virtual std::vector<sf::Vector2i> getPossibleMove(std::string config[][8] , Engine *game) = 0;

protected:
	char notation;
	char color;
	sf::Vector2i coordinate;
	float size;
	sf::Sprite sprite;
	bool hasMove;
};

#endif