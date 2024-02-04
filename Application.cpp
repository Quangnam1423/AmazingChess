#include "Application.h"
#include <iostream>


Application::Application()
{
	window = new sf::RenderWindow(sf::VideoMode(this->Width, this->Height), "Amazing Chess");

	TextBox* Queen_button = new TextBox(100, 30, "Queen");
	Queen_button->setPositionForTextBox(sf::Vector2i(820, 100));

	buttons.push_back(Queen_button);

	TextBox* Bishop_button = new TextBox(100, 30, "Bishop");
	Bishop_button->setPositionForTextBox(sf::Vector2i(820, 300));

	buttons.push_back(Bishop_button);

	TextBox* Knight_button = new TextBox(100, 30, "Knight");
	Knight_button->setPositionForTextBox(sf::Vector2i(820, 500));

	buttons.push_back(Knight_button);

	TextBox* Rook_button = new TextBox(100, 30, "Rook");
	Rook_button->setPositionForTextBox(sf::Vector2i(820, 700));

	buttons.push_back(Rook_button);

}

Application::~Application()
{
	delete window;
}

void Application::run()
{
	Engine* game = new Engine('w', this->SquareSize);

	window->setFramerateLimit(60);

	bool promotion = false;

	std::string status = "White Move!";

	while (window->isOpen())
	{
		game->getStatus(status, promotion);
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (promotion)

				{
					std::string temp = checkCollision(sf::Mouse::getPosition(*window));
					if (temp == "Queen")
						game->setPromotion("q");
					else if (temp == "Bishop")
						game->setPromotion("b");
					else if (temp == "Knight")
						game->setPromotion("n");
					else if (temp == "Rook")
						game->setPromotion("r");
				}

				else
					game->handleClicked(sf::Mouse::getPosition(*window));
				break;
			}

			if (event.type == sf::Event::MouseMoved)
			{
				checkCollision(sf::Mouse::getPosition(*window), false);
			}
		}

		window->clear();

		//this->print(window);

		game->print(*window);

		if (promotion)
		{
			for (TextBox* button : buttons)
				button->displayText(*window);
		}

		window->display();
	}

	delete game;
}

std::string Application::checkCollision(sf::Vector2i position)
{
	for (TextBox* button : buttons)
	{
		if (button->getGlobalBounds().contains(static_cast<sf::Vector2f> (position)))
			{
				button->setLight(true);
				return button->getNotation();
			}
			else button->setLight(false);
		}
	return "nothing";
}

void  Application::checkCollision(sf::Vector2i position , bool value)
{
	for (TextBox* button : buttons)
	{
		if (button->getGlobalBounds().contains(static_cast<sf::Vector2f> (position)))
		{
			button->setLight(true);
		}
		else button->setLight(false);
	}
	return;
}

