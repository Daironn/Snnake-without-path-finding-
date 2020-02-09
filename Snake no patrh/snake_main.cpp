#include "pch.h"
#include "Map.h"
#include "Dot.h"
#include "Snake.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
	Map mapa(25.f,25.f);
	Snake snake;
	Dot dot(&snake);

	sf::Clock clock; // starts the clock

	while (window.isOpen())
	{
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			snake.eventCatcher(event);
		}
		window.clear();

		if (elapsed1.asMilliseconds() >= 50) {
			snake.update(event, mapa, dot);
			clock.restart();
		}

		mapa.draw(window);
		dot.draw(window);
		snake.draw(window);

		window.display();

	}

	return 0;
}