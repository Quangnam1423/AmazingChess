#pragma once

#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(std::string notation, sf::Vector2i coordintae, float size, sf::Texture* texture);
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8] , Engine *game) override;
};