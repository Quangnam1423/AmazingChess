#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "Engine.h"


class Application
{
public:
	float Height = 800.0f;
	float Width = 800.0f;
	float SquareSize = Height / 8;
public:
	Application();
	void run();
};

#endif