#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "data/object/Engine.h"
#include "Manager/TextBox.h"

class Application
{
public:
	float Height = 800.0f;
	float Width = 1000.0f;
	float SquareSize = 640 / 8;
	sf::RenderWindow* window;
	std::vector<TextBox*> buttons;
public:
	Application();
	~Application();
	std::string checkCollision(sf::Vector2i);
	void  checkCollision(sf::Vector2i position , bool value);
	void run();
};

#endif