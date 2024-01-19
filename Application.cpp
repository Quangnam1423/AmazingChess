#include "Application.h"


Application::Application()
{

	this->ptrgetTexture = &Application::getTexture;
	this->game;
}

void Application::run()
{

	sf::RenderWindow window(sf::VideoMode(this->Height, this->Width), "Amazing Chess");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			
			else if (event.type == sf::Event::MouseButtonPressed)
			{
			
			}
		}
	}
}

sf::Texture* Application::getTexture(std::string notation)
{
	return this->map_Texture[notation];
}