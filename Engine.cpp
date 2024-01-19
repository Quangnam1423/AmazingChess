#include "Engine.h"

Piece* getNewPiece(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture);

Engine::Engine()
{

}

void Engine::Init(char turn, float sizeSquare)
{
	this->turn = turn;
	this->SquareSize = sizeSquare;
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

	//..............................................................//

	for (int i = 0 ; i < 8 ; i++ )
	{
		for (int j = 0 ; j < 8 ; j++ )
		{
			std::string notation = this->config[i][j];
			sf::Vector2i coordinate(j, i);
			Piece* newPiece;
			if (notation != "--")
			{
				sf::Texture* temp = this->map_Texture[notation];
				newPiece = getNewPiece(notation, coordinate, sizeSquare, temp);
				
			}
			this->Squares.push_back(new Square(newPiece, coordinate, this->SquareSize));
		}
	}
}

Piece* getNewPiece(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture)
{
	if (notation == )
}