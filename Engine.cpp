#include "Engine.h"
#include <iostream>

Piece* getNewPiece(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture);

struct Vector2iHash {
	std::size_t operator()(const sf::Vector2i& v) const {
		return std::hash<int>()(v.x) ^ (std::hash<int>()(v.y) << 1);
	}
};

Engine::Engine(char turn, float sizeSquare)
{
	this->turn = turn;
	this->SquareSize = sizeSquare;
	this->checkmate = false;
	this->selectedPiece = nullptr;
	this->selectedSquare = nullptr;
	BlackKingCoordinate.x = 3;
	BlackKingCoordinate.y = 0;
	WhiteKingCoordinate.x = 3;
	WhiteKingCoordinate.y = 7;
	for (int i = 0; i < 6; i++)
	{
		std::string notation = 'w' + this->paths[i];
		std::string temp = "data\\imgs\\" + notation + ".png";
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(temp);
		this->map_Texture[notation] = texture;
	}
	for (int i = 0; i < 6; i++)
	{
		std::string notation = 'b' + this->paths[i];
		std::string temp = "data\\imgs\\" + notation + ".png";
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(temp);
		this->map_Texture[notation] = texture;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::string notation = this->config[i][j];
			sf::Vector2i coordinate(j, i);
			Piece* newPiece = nullptr;
			if (notation != "--")
			{
				sf::Texture* temp = this->map_Texture[notation];
				newPiece = getNewPiece(notation, coordinate, sizeSquare, temp);

			}
			this->Squares.push_back(new Square(newPiece, coordinate, this->SquareSize));
		}
	}
}

Engine::~Engine()
{
	for (Square* x : Squares)
	{
		delete x;
	}
}

Square* Engine::getSquareFromMouse(sf::Vector2i MousePosition)
{
	MousePosition.x = (int)MousePosition.x / this->SquareSize;
	MousePosition.y = (int)MousePosition.y / this->SquareSize;
	for (Square* x : Squares)
	{
		if (MousePosition == x->getCoordinate())
		{
			std::cout << MousePosition.x << " " << MousePosition.y << std::endl;
			return x;
		}
	}
	return nullptr;
}

Square* Engine::getSquareFromCoord(sf::Vector2i Coordinate)
{
	for (Square* x : this->Squares)
	{
		if (x->getCoordinate() == Coordinate)
		{
			return x;
		}
	}
	return nullptr;
}

char Engine::getTurn()
{
	return this->turn;
}

void Engine::print(sf::RenderWindow& window)
{
	for (Square* x : this->Squares)
	{
		x->print(window);
	}
}

void Engine::Completion(Square* clickedSquare)
{
	sf::Vector2i temp = clickedSquare->getCoordinate();
	bool check = true;
	for (sf::Vector2i x : this->PossibleMove)
	{
		if (x == temp)
		{
			check = false;
		}
	}
	if (!check)
	{
		this->selectedSquare->setPiece(nullptr);
		clickedSquare->setPiece(this->selectedPiece);
		sf::Vector2i newCoord = this->selectedPiece->getCoordinate();
		sf::Vector2i oldCoord = this->selectedSquare->getCoordinate();
		std::string trunggian = config[newCoord.y][newCoord.x];
		config[newCoord.y][newCoord.x] = config[oldCoord.y][oldCoord.x];
		config[oldCoord.y][oldCoord.x] = "--";
		if (this->selectedPiece->getNotation() == 'k')
		{
			// swap to piece and two config in the board chess 

			if (this->turn == 'b')
			{
				this->BlackKingCoordinate.x = newCoord.x;
				this->BlackKingCoordinate.y = newCoord.y;
			}
			else
			{
				this->WhiteKingCoordinate.x = newCoord.x;
				this->WhiteKingCoordinate.y = newCoord.y;
			}
		}
		if (this->turn == 'w')
			this->turn = 'b';
		else
			this->turn = 'w';
	}
	this->fillHighlight(false);
	this->PossibleMove.clear();
	this->selectedPiece = nullptr;
	this->selectedSquare = nullptr;
}

void Engine::handleClicked(sf::Vector2i MousePosition)
{
	Square* clickedSquare = this->getSquareFromMouse(MousePosition);
	if (clickedSquare != nullptr)
	{
		if (this->selectedPiece != nullptr)
		{
			this->Completion(clickedSquare);
		}
		else
		{
			this->selectedPiece = clickedSquare->getPiece();
			if (this->selectedPiece != nullptr && this->selectedPiece->getColor() == this->turn)
			{
				this->selectedSquare = clickedSquare;
				this->PossibleMove = this->selectedPiece->getPossibleMove(this->config);
				//this->PossibleMove = this->getValidMove();
				this->fillHighlight(true);
			}
			else
			{
				this->selectedPiece = nullptr;
				std::cout << "nullptr" << std::endl;
			}
		}
	}
	else
	{
		this->fillHighlight(false);
		this->PossibleMove.clear();
		this->selectedPiece = nullptr;
		this->selectedSquare = nullptr;
	}
}

bool Engine::Is_In_Check()
{
	std::unordered_set<sf::Vector2i , Vector2iHash> Coord;
	for (Square* x : Squares)
	{
		if (x->getPiece() != nullptr && x->getPiece()->getColor() != this->turn)
		{
			std::vector<sf::Vector2i> possibleMove = x->getPiece()->getPossibleMove(this->config);
			Coord.insert(possibleMove.begin(), possibleMove.end());
		}
	}
	if (this->turn == 'w' && Coord.find(this->WhiteKingCoordinate) != Coord.end())
		return true;
	if (this->turn == 'b' && Coord.find(this->BlackKingCoordinate) != Coord.end())
		return true;
	return false;
}

std::vector<sf::Vector2i> Engine::getValidMove()
{
	std::vector<sf::Vector2i> output;
	for (sf::Vector2i coord : this->PossibleMove)
	{
		if (this->checkValidMove(this->selectedSquare->getCoordinate(), coord) == true)
		{
			output.push_back(coord);
		}
	}
	return output;
}

bool Engine::checkValidMove(sf::Vector2i oldSquareCoord, sf::Vector2i newSquareCoord)
{
	Square* newSquare = this->getSquareFromCoord(newSquareCoord);
	Square* oldSquare = this->getSquareFromCoord(oldSquareCoord);
	Piece* tempPiece = newSquare->getPiece();
	std::string tempConfig = this->config[newSquareCoord.y][newSquareCoord.x];
	newSquare->setPiece(oldSquare->getPiece());
	oldSquare->setPiece(nullptr);
	this->config[oldSquareCoord.y][oldSquareCoord.x] = "--";
	bool output = this->Is_In_Check();
	this->config[oldSquareCoord.y][oldSquareCoord.x] = this->config[newSquareCoord.y][newSquareCoord.x];
	this->config[newSquareCoord.y][newSquareCoord.x] = tempConfig;
	oldSquare->setPiece(newSquare->getPiece());
	newSquare->setPiece(tempPiece);
	return output;
}

void Engine::fillHighlight(bool value) // fill highlight squares for each move...
{
	if (value)
	{
		for (sf::Vector2i x : this->PossibleMove)
		{
			Square* temp = this->getSquareFromCoord(x);
			temp->markHighlight(true);
		}
	}
	else
	{
		for (sf::Vector2i x : this->PossibleMove)
		{
			Square* temp = this->getSquareFromCoord(x);
			temp->markHighlight(false);
		}
	}
	return;
}

Piece* getNewPiece(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture)
{
	if (notation == "--")
		return nullptr;
	else if (notation == "wr" || notation == "br")
		return new Rook(notation, coordinate, size, texture);
	else if (notation == "wn" || notation == "bn")
		return new Knight(notation, coordinate, size, texture);
	else if (notation == "wb" || notation == "bb")
		return new Bishop(notation, coordinate, size, texture);
	else if (notation == "wk" || notation == "bk")
		return new King(notation, coordinate, size, texture);
	else if (notation == "wq" || notation == "bq")
		return new Queen(notation, coordinate, size, texture);
	else if (notation == "wp" || notation == "bp")
		return new Pawn(notation, coordinate, size, texture);
}

