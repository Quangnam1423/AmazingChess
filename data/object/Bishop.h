#pragma once
#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8]) override;
};

#endif