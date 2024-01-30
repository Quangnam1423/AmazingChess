#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture);
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8] , Engine *game) override;
};

