#include "piece.h"
#include <Graphics.hpp>
#include <iostream>

piece::piece(sf::Vector2i coordinate, float size_piece, std::string notation)
{
	this->size = size_piece;
	std::string path = "data\\imgs\\" + notation + ".png";
	this->texture.loadFromFile(path);
	this->texture.setSmooth(true);
	this->sprite.setTexture(this->texture);
	sf::Vector2u originalSize = texture.getSize();
	sprite.setScale(sf::Vector2f(size_piece / originalSize.x,size_piece / originalSize.y));
	this->sprite.setPosition(coordinate.x * this->size, coordinate.y * this->size);
}
piece::~piece()
{
	
}
void piece::print(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

void piece::setPosition(int x, int y)
{
	this->sprite.setPosition(x * this->size, y * this->size);
}

void piece::setPosition(sf::Vector2i const newPosition)
{
	this->sprite.setPosition((float) newPosition.x , (float) newPosition.y);
}
