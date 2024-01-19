#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8]) override;
};

