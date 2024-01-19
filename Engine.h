#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "Square.h"
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>

class Engine
{
public:
	Engine();
	//~Engine();
	void Init(char turn , float sizeSquare);
	//void getSquareFromMouse(sf::Vector2i MousePosition);
	//void Completion(sf::Vector2i MousePosition);
	//void setupBoard();
	//sf::Texture* getTexture(std::string notation);	
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
private:

	std::string turn;
	Square* ptrSelectedSquare , ptrMoveSquare;
	Piece* selectedPiece;
	std::vector<Square*> Squares;
	bool checkmate;
	bool isInCheckMate;
	bool pawnAdvancement;

	float SquareSize;
};

#endif