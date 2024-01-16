#include "square.h"
#include <iostream>

square::square(sf::Vector2i coordinate, float &size_square , piece* current_piece)
{
	//get the position for thr square on the monitor
	this->coordinate = coordinate;
	if ((int)(this->coordinate.x + this->coordinate.y) % 2 == 0)
		this->color = "white";
	else
		this->color = "black";
	this->size_square = size_square;
	this->size = sf::Vector2f(this->size_square, this->size_square);
	this->rectangle.setSize(this->size);
	this->rectangle.setPosition(this->coordinate.x * this->size_square , this->coordinate.y * this->size_square);

	// config the started condition of the game
	this->checkingmate = false;
	this->highlight = false;

	// config piece for square
	this->currentPiece = current_piece;
}

square::~square()
{
	if (this->currentPiece != nullptr)
		delete this->currentPiece;
	return;
}

void square::print(sf::RenderWindow& window)
{
	if (this->color == "black")
		rectangle.setFillColor(sf::Color(153, 204, 0));
	else
		rectangle.setFillColor(sf::Color(255, 255, 204));
	//if (this->highlight == true)
	//{
	//	window.draw(highlight_circle_shape);
	//}
	//if (this->current_piece != NULL)
	//{
	//	this->current_piece->Piece_print(window);
	//}
	window.draw(this->rectangle);
	if (this->currentPiece != nullptr)
	{
		this->currentPiece->print(window);
	}
}

void square::setCurrentPiece(piece* newPiece)
{
	this->currentPiece = newPiece;
	if (this->currentPiece != nullptr)
	{
		this->currentPiece->setPosition(this->coordinate);
	}
	return;
}
piece* square::getCurrentPiece()
{
	if (this->currentPiece != nullptr)
		return this->currentPiece;
	else return nullptr;
}

sf::Vector2i square::getCoordinate()
{
	return this->coordinate;
}

void square::fill_checkingmate()
{
	this->checkingmate = true;
	return;
}

void square::fill_highlight()
{
	this->highlight = true;
	return;
}