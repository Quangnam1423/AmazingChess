#include "piece.h"
#include <Graphics.hpp>
#include <iostream>

piece::piece(sf::Vector2f position, float size_piece, std::string notation)
{
	this->position = position;
	this->size_piece = size_piece;
	std::string path = "data\\imgs\\" + notation + ".png";
	this->texture.loadFromFile(path);
	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
	sf::Vector2u originalSize = texture.getSize();
	sprite.setScale(sf::Vector2f(size_piece / originalSize.x,size_piece / originalSize.y));
	this->sprite.setPosition(this->position.x * this->size_piece, this->position.y * this->size_piece);
}
piece::~piece()
{
	
}
void piece::Piece_print(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}
/*
	sf::Vector2f position;
	float size_piece;
	sf::Texture texture;
	sf::Sprite sprite;

*/