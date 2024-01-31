#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    Pawn(std::string notation, sf::Vector2i coordinate, float size, sf::Texture* texture);
    std::vector<sf::Vector2i> getPossibleMove(std::string config[][8] , Engine *game) override;
    void setCoordinate(sf::Vector2i newCoordinate, bool value) override;
    void update_DoubleMove(bool value);
    bool getDoubleMove();

private:
    bool double_move;
};

