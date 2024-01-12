#pragma once
#ifndef PIECE_H
#define PIECE_H

#include <Graphics.hpp>

class piece
{
public:
	piece(sf::Vector2f position , float size_piece , std::string notation);
	~piece();
	void Piece_print(sf::RenderWindow& window);
private:
	sf::Vector2f position;
	float size_piece;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif