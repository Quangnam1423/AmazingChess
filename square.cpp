#include "square.h"

square::square(sf::Vector2f position, sf::Vector2f& size_square)
{
	this->position = position;
	this->size_square = size_square;
	//set the size of the square
	this->rectangle.setSize(this->size_square);
	this->highlight_circle_shape.setRadius(this->size_square.x / 4);
	sf::Vector2f temp(this->position.x + this->size_square.x, this->position.x + this->size_square.x);
	this->highlight_circle_shape.setPosition(temp);
	
	if ((int)(this->position.x + this->position.y) % 2 == 0)
		this->color = "white";
	else
		this->color = "black";
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
	if (this->checkingmate == true)
	{
		rectangle.setFillColor(sf::Color::Red);
		window.draw(this->rectangle);
	}
	else
	{
		if (color == "black")
			rectangle.setFillColor(sf::Color::Black);
		else
			rectangle.setFillColor(sf::Color::White);
		window.draw(this->rectangle);
		if (this->highlight == true)
		{
			window.draw(highlight_circle_shape);
		}
	}
}