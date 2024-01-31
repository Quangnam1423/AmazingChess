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
	this->game = this;
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



bool Engine::Completion(Square* clickedSquare)
{
	Piece* removePiece = clickedSquare->getPiece();
	sf::Vector2i temp = clickedSquare->getCoordinate();
	bool check = false;
	for (sf::Vector2i x : this->PossibleMove)
		if (x == temp)
		{
			check = true;
			break;
		}
	if (check == false)
		return false;

	// handle the passen happening 

	if (this->selectedPiece->getNotation() == 'p')
	{
		if (clickedSquare->getPiece() == nullptr)
		{
			sf::Vector2i selectedpos = this->selectedSquare->getCoordinate();
			sf::Vector2i clickedpos = clickedSquare->getCoordinate();
			if (selectedpos.x != clickedpos.x && selectedpos.y != clickedpos.y)
			{
				sf::Vector2i passen_pos(clickedpos.x, selectedpos.y);
				Square* temp = this->getSquareFromCoord(passen_pos);
				temp->setPiece(nullptr);
				this->config[selectedpos.y][clickedpos.x] = "--";
			}
		}
	}

	this->selectedSquare->setPiece(nullptr);
	clickedSquare->setPiece(this->selectedPiece);
	sf::Vector2i newCoord = this->selectedPiece->getCoordinate();
	sf::Vector2i oldCoord = this->selectedSquare->getCoordinate();
	std::string trunggian = config[newCoord.y][newCoord.x];
	config[newCoord.y][newCoord.x] = config[oldCoord.y][oldCoord.x];
	config[oldCoord.y][oldCoord.x] = "--";

	// handle the castle if that move happens  
	if (this->selectedPiece->getNotation() == 'k')
	{
		if (newCoord.x - oldCoord.x == 2)
		{
			sf::Vector2i rookPos(7, newCoord.y);
			sf::Vector2i new_rookPos(newCoord.x - 1, newCoord.y);
			Square* rook = this->getSquareFromCoord(rookPos);
			Square* new_rook = this->getSquareFromCoord(new_rookPos);
			new_rook->setPiece(rook->getPiece());
			rook->setPiece(nullptr);
			this->config[newCoord.y][newCoord.x - 1] = this->config[newCoord.y][7];
			this->config[newCoord.y][7] = "--";
		}
		else if (oldCoord.x - newCoord.x == 2)
		{
			sf::Vector2i rookPos(0, newCoord.y);
			sf::Vector2i new_rookPos(newCoord.x + 1, newCoord.y);
			Square* rook = this->getSquareFromCoord(rookPos);
			Square* new_rook = this->getSquareFromCoord(new_rookPos);
			new_rook->setPiece(rook->getPiece());
			rook->setPiece(nullptr);
			this->config[newCoord.y][newCoord.x + 1] = this->config[newCoord.y][0];
			this->config[newCoord.y][0] = "--";
		}
	}
	if (removePiece != nullptr)
		delete removePiece;
	// already handle the castle
	return true;
}




void Engine::handleClicked(sf::Vector2i MousePosition)
{
	Square* clickedSquare = this->getSquareFromMouse(MousePosition);
	Piece* clickedPiece = clickedSquare->getPiece();
	if (clickedSquare == nullptr)
	{
		this->reset();
		return;
	}
	if (this->selectedPiece == nullptr)
	{
		if (clickedPiece == nullptr)
		{
			this->reset();
			return;
		}
		else if (clickedPiece->getColor() == this->turn)
		{
			this->selectedPiece = clickedPiece;
			this->selectedSquare = clickedSquare;
			this->PossibleMove = this->selectedPiece->getPossibleMove(this->config , this->game);
			this->PossibleMove = this->getValidMove();
			this->fillHighlight(true);
			if (this->PossibleMove.size() == 0)
			{
				this->reset();
				return;
			}
			// setup for choose piece Valid..................
		}
		else
		{
			this->reset();
			return;
		}
	}
	else
	{
		if (clickedPiece == this->selectedPiece)
			return;
		else
		{
			bool value = this->Completion(clickedSquare);
			if (value)
			{
				if (this->turn == 'w')
					this->turn = 'b';
				else
					this->turn = 'w';
			}
			this->reset();
			return;
		}
	}
	return;
}




bool Engine::Is_In_Check()
{
	std::vector<sf::Vector2i> coords;
	sf::Vector2i KingCoord = sf::Vector2i(-1 , -1);
	std::string notation;
	if (this->turn == 'w')
		notation = "wk";
	else
		notation = "bk";
	for (int i = 0; i < 8; i++)
	{
		if (KingCoord.x != -1)
			break;
		for (int j = 0; j < 8; j++)
		{
			if (this->config[i][j] == notation)
			{
				KingCoord.x = j;
				KingCoord.y = i;
				break;
			}
		}
	}
	for (Square* x : this->Squares)
	{
		if (x->getPiece() != nullptr && x->getPiece()->getColor() != this->turn)
		{
			std::vector<sf::Vector2i> possibleMove = x->getPiece()->getPossibleMove(this->config , this->game);
			for (sf::Vector2i coord : possibleMove)
			{
				coords.push_back(coord);
			}
		}
	}
	for (sf::Vector2i coord : coords)
	{
		if (coord == KingCoord)
			return false;
	}
	return true;
}



bool Engine::Is_In_Check(int x, int y)
{
	sf::Vector2i position(x, y);
	std::vector<sf::Vector2i> coords;

	for (Square* x : this->Squares)
	{
		if (x->getPiece() != nullptr && x->getPiece()->getColor() != this->turn)
		{
			std::vector<sf::Vector2i> possibleMove = x->getPiece()->getPossibleMove(this->config, this->game);
			for (sf::Vector2i coord : possibleMove)
			{
				coords.push_back(coord);
			}
		}
	}
	for (sf::Vector2i coord : coords)
	{
		if (coord == position)
			return false;
	}
	return true;
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
	newSquare->setPiece(oldSquare->getPiece() , false);
	oldSquare->setPiece(nullptr , false);
	this->config[newSquareCoord.y][newSquareCoord.x] = this->config[oldSquareCoord.y][oldSquareCoord.x];
	this->config[oldSquareCoord.y][oldSquareCoord.x] = "--";

	bool output = this->Is_In_Check();
	this->config[oldSquareCoord.y][oldSquareCoord.x] = this->config[newSquareCoord.y][newSquareCoord.x];
	this->config[newSquareCoord.y][newSquareCoord.x] = tempConfig;
	oldSquare->setPiece(newSquare->getPiece() , false);
	newSquare->setPiece(tempPiece , false);
	return output;
}



void Engine::fillHighlight(bool value)
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



void Engine::reset()
{
	this->fillHighlight(false);
	this->PossibleMove.clear();
	this->selectedPiece = nullptr;
	this->selectedSquare = nullptr;
	return;
}



Piece* getNewPiece(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture)
{
	if (notation == "--")
		return nullptr;
	if (notation == "wr" || notation == "br")
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
	return nullptr;
}

