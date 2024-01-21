#include "Piece.h"

Piece::Piece(std::string notation, sf::Vector2i coordinate, float size, sf::Texture *texture)
{
	this->notation = notation[1];
	this->color = notation[0];
	this->hasMove = false;
	this->size = size;
	this->coordinate = coordinate;
	texture->setSmooth(true);
	this->sprite.setTexture(*texture);
	sf::Vector2u originalSize = texture->getSize();
	sprite.setScale(sf::Vector2f(size / originalSize.x, size / originalSize.y));
	this->sprite.setPosition(this->coordinate.x * this->size, this->coordinate.y * this->size);
}

Piece::~Piece()
{

}

void Piece::print(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

sf::Vector2i Piece::getCoordinate()
{
	return this->coordinate;
}

void Piece::setCoordinate(sf::Vector2i newCoordinate)
{
	this->hasMove = true;
	this->coordinate = newCoordinate;
	this->sprite.setPosition(this->coordinate.x * this->size, this->coordinate.y * this->size);
}

void Piece::setPosition(sf::Vector2f newPosition)
{
	this->sprite.setPosition(newPosition);
}

void Piece::setPosition(sf::Vector2i newPosition)
{
	this->sprite.setPosition(newPosition.x , newPosition.y);
}

char Piece::getColor()
{
	return this->color;
}

char Piece::getNotation()
{
	return this->notation;
}