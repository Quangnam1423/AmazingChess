#include "square.h"
#include <iostream>

square::square(sf::Vector2f position, float &size_square , piece* current_piece)
{
	//get the position for thr square on the monitor
	this->position = position;
	if ((int)(this->position.x + this->position.y) % 2 == 0)
		this->color = "white";
	else
		this->color = "black";
	this->size_square = size_square;
	this->size = sf::Vector2f(this->size_square, this->size_square);
	this->rectangle.setSize(this->size);
	this->rectangle.setPosition(this->position.x * this->size_square , this->position.y * this->size_square);

	// config the started condition of the game
	this->checkingmate = false;
	this->highlight = false;

	// config piece for square
	this->current_piece = current_piece;
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


void square::print_square(sf::RenderWindow& window)
{

	if (this->color == "black")
		rectangle.setFillColor(sf::Color(153,204,0));
	else
		rectangle.setFillColor(sf::Color(255,255,204));
	window.draw(this->rectangle);


	if (this->highlight == true)
	{
		window.draw(highlight_circle_shape);
	}
	if (this->current_piece != NULL)
	{
		this->current_piece->Piece_print(window);
	}
}