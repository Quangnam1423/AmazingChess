#include "Piece.h"

Piece::Piece(std::string notation, sf::Vector2f &size_piece, sf::Vector2f &position)
{
	this->current_pos = &position;
	this->notation = notation;
	this->has_move = false;
	std::string path = "data\\imgs\\" + this->notation + ".png";
	sf::Texture texture; 
	texture.loadFromFile(path);
	this->sprite.setTexture(texture);
	this->sprite.setPosition(*this->current_pos);
	this->sprite.setScale(size_piece);
}

void Piece::PrintOnSquare(sf::RenderWindow &window)
{
	window.draw(sprite);
	return;
}

void Piece::update_position(sf::Vector2f& new_position)
{
	this->current_pos = &new_position;
	this->sprite.setPosition(*this->current_pos);
	if (!this->has_move) has_move = true;
	return;
}

void Piece::update_size_piece(sf::Vector2f& new_size_piece)
{
	this->sprite.setScale(new_size_piece);
	return;
}