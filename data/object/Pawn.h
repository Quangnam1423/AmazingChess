#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8]) override;
};

