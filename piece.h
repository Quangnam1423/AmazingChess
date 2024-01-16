#pragma once
#ifndef PIECE_H
#define PIECE_H

#include <Graphics.hpp>

class piece
{
public:
	piece(sf::Vector2i coordinate , float size_piece , std::string notation);
	~piece();
	void print(sf::RenderWindow& window);
	void setPosition(int x, int y);
	void setPosition(sf::Vector2i const newPosition);
private:
	float size;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif