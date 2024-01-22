#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "Square.h"
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <unordered_set>

class Engine
{
public:
	Engine(char turn, float sizeSquare);
	~Engine();
	Square* getSquareFromMouse(sf::Vector2i MousePosition);
	Square* getSquareFromCoord(sf::Vector2i Coordinate);
	bool Is_In_Check();
	bool checkValidMove(sf::Vector2i oldSquare, sf::Vector2i newSquare);
	std::vector<sf::Vector2i> getValidMove();
	void handleClicked(sf::Vector2i MousePosition);
	void reset();
	char getTurn();
	bool Completion(Square* clickedSquare);
	void fillHighlight(bool value);
	std::unordered_map<std::string, sf::Texture*> map_Texture;
	std::string paths[6] = { "r" , "n" , "b" , "k" , "q" , "p" };
	std::string config[8][8] = {
		{"br" , "bn" , "bb" , "bk" , "bq" , "bb" , "bn" , "br"},
		{"bp" , "bp" , "bp" , "bp" , "bp" , "bp" , "bp" , "bp"},
		{"--" , "--" , "--" , "--" , "--" , "--" , "--" , "--"},
		{"--" , "--" , "--" , "--" , "--" , "--" , "--" , "--"},
		{"--" , "--" , "--" , "--" , "--" , "--" , "--" , "--"},
		{"--" , "--" , "--" , "--" , "--" , "--" , "--" , "--"},
		{"wp" , "wp" , "wp" , "wp" , "wp" , "wp" , "wp" , "wp"},
		{"wr" , "wn" , "wb" , "wk" , "wq" , "wb" , "wn" , "wr"}
	};
	void print(sf::RenderWindow& window);
private:

	Square* selectedSquare;
	Piece* selectedPiece;
	char turn;
	std::vector<sf::Vector2i> PossibleMove;
	std::vector<Square*> Squares;
	bool checkmate;
	float SquareSize;
};

#endif