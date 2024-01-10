#pragma once
#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
#include <Graphics.hpp>
class Piece
{
public:
	Piece(std::string notation, sf::Vector2f &size_piece , sf::Vector2f &position);
	~Piece();
	void PrintOnSquare(sf::RenderWindow &window);
	std::vector<sf::Vector2f> check_possible_move(); // phuong thuc nay se de cac class con ke thua va ghi de.
	void update_position(sf::Vector2f& new_position);
	void update_size_piece(sf::Vector2f& new_size_piece);

private:
	sf::Vector2f *current_pos;
	std::string notation;
	bool has_move;
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif