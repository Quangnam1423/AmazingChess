#include "Application.h"


Application::Application()
{

}

void Application::run()
{

	sf::RenderWindow window(sf::VideoMode(this->Height, this->Width), "Amazing Chess");

	Engine* game = new Engine('w', this->SquareSize);

	window.setFramerateLimit(60);

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
				game->handleClicked(sf::Mouse::getPosition(window));
			}
		}

		window.clear();

		game->print(window);

		window.display();
	}
}
