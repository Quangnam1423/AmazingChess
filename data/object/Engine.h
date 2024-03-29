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
	bool Is_In_Check(int x , int y);
	bool checkValidMove(sf::Vector2i oldSquare, sf::Vector2i newSquare);
	std::vector<sf::Vector2i> getValidMove();
	std::vector<sf::Vector2i> getValidMove(Square* sq , std::vector<sf::Vector2i> input);
	void handleClicked(sf::Vector2i MousePosition);
	void reset();
	char getTurn();
	bool Completion(Square* clickedSquare);

	void nextMoveSetup();

	void getStatus(std::string& st, bool &pro);


	void setPromotion(std::string notation);

	void fillHighlight(bool value);
	void print(sf::RenderWindow& window);	

private:
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
	Engine* game;
	Square* selectedSquare;
	Piece* selectedPiece;
	char turn;
	std::vector<sf::Vector2i> PossibleMove;
	std::vector<Square*> Squares;
	bool checkmate;
	float SquareSize;
	int status;
	bool promotion;
};

#endif

//switchTurnAndSetupBoard()
//nextMoveSetup()
//handleNextPlayer()
//updateGameAfterMove()
//advanceToNextTurn()
//processNextMove()
//togglePlayerTurn()