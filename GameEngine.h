#pragma once
#include <vector>
#include "square.h"
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine
{
public:
	GameEngine(float size_square ,bool go_first);
	~GameEngine();
	void Print(sf::RenderWindow& window);
private:
	int config[8][8] = {
		{2 , 3 , 4 , 6 , 5 , 4 , 3 , 2 },
		{1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
		{-1, -1, -1, -1,-1 ,-1 ,-1 ,-1 },
		{-2, -3, -4, -6, -5, -4, -3, -2}
	};
	bool turn;
	bool endgame;
	std::vector<square*> squares;
};

#endif