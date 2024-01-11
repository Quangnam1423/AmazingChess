#include "square.h"

square::square(sf::Vector2f position, float &size_square)
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
	sf::Vector2f temp(this->position.x + this->size.x, this->position.x + this->size.x);

	// config the started condition of the game
	this->checkingmate = false;
	this->highlight = false;
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
}