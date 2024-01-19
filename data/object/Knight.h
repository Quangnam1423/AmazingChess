#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
public:
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8]) override;
};

