#include "Square.h"

Square::Square()
{

}

Square::Square(Piece* piece, sf::Vector2i coordinate, float size)
{
	this->currentPiece = piece;
	this->coordinate = coordinate;
	if ((this->coordinate.x + this->coordinate.y) % 2 == 0)
	{
		this->color = "white";
	}
	else this->color = "black";
	this->size = size;
	this->rectangle.setSize(sf::Vector2f(this->size, this->size));
	this->rectangle.setPosition(this->coordinate.x * this->size, this->coordinate.y * this->size);
	this->rectangle.setOutlineThickness(3.f);
	this->rectangle.setOutlineColor(sf::Color::White);
	this->highlight = false;
	this->selected = false;
	this->highlight_circle_shape.setRadius(this->size / 8);
	this->highlight_circle_shape.setOrigin(this->size / 8, this->size / 8);
	this->highlight_circle_shape.setPosition(this->coordinate.x * this->size + this->size / 2,this->coordinate.y * this->size + this->size / 2);
	this->highlight_circle_shape.setFillColor(sf::Color(10 , 10 , 10));
	this->highlight_circle_shape.setOutlineThickness(3.f);
	this->highlight_circle_shape.setOutlineColor(sf::Color::Yellow);
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
	if (this->currentPiece != nullptr)
		newPiece->setCoordinate(this->coordinate);
}

void Square::setCoordinate(sf::Vector2i coordinate)
{
	this->coordinate = coordinate;
	this->rectangle.setPosition(this->coordinate.x * this->size, this->coordinate.y * this->size);
}

void Square::print(sf::RenderWindow& window)
{
	if (this->highlight && this->currentPiece != nullptr)
		rectangle.setFillColor(sf::Color::Red);
	else if (this->color == "black")
		rectangle.setFillColor(sf::Color(153, 204, 0));
	else
		rectangle.setFillColor(sf::Color(255, 255, 204));
	window.draw(this->rectangle);
	if (this->highlight == true && this->currentPiece == nullptr)
	{
		window.draw(highlight_circle_shape);
	}
	if (this->selected == false && this->currentPiece != nullptr)
	{
		this->currentPiece->print(window);
	}
}

void Square::markHighlight(bool value)
{
	if (value == true)
		this->highlight = true;
	else this->highlight = false;
	return;
}