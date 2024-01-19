#include "Square.h"

Square::Square(Piece* piece, sf::Vector2i coordinate, float size)
{
	this->currentPiece = piece;
	this->coordinate = coordinate;
	if (this->coordinate.x + this->coordinate.y % 2 == 0)
	{
		this->color = "white";
	}
	else this->color = "black";
	this->size = size;
	this->rectangle.setSize(sf::Vector2f(this->size, this->size));
	this->rectangle.setPosition(this->coordinate.x * this->size, this->coordinate.y * this->size);
	this->highlight = false;
	this->selected = false;
}

Square::~Square()
{
	if (this->currentPiece != nullptr)
	{
		delete this->currentPiece;
	}
}

sf::Vector2i Square::getCoordinate()
{
	return this->coordinate;
}

Piece* Square::getPiece()
{
	return this->currentPiece;
}

void Square::setPiece(Piece* newPiece)
{
	this->currentPiece = newPiece;
	newPiece->setCoordinate(this->coordinate);
}

void Square::setCoordinate(sf::Vector2i coordinate)
{
	this->coordinate = coordinate;
	this->rectangle.setPosition(this->coordinate.x * this->size, this->coordinate.y * this->size);
}

void Square::print(sf::RenderWindow& window)
{
	window.draw(this->rectangle);
	if (this->selected == false && this->currentPiece != nullptr)
	{
		this->currentPiece->print(window);
	}
}