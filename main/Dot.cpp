#include "pch.h"
#include "Dot.h"


Dot::Dot(const Snake * snake):
	Snake()
{
	sf::CircleShape pion;
	pion.setRadius(10);
	pion.setFillColor(sf::Color::Red);
	pion.setOutlineThickness(1);
	pion.setOutlineColor(sf::Color::Red);
	this->dot = pion;
	this->spawn(snake);
}


Dot::~Dot()
{
}

void Dot::spawn(const Snake * snake)
{
	int stopu = 0;

	bool stop = false;
	
	int v1 = rand() % 23;
	int v2 = rand() % 23;

	sf::Vector2i pos{ v1,v2 };
	while (stop == false) {

		srand(time(NULL));

		for (int i = 0; i < body.size() - 1; i++) {

			if ((sf::Vector2f)pos == snake->body[i].getPosition()) {

				stopu++;
				break;
			}
		}
		if (stopu == 0)

			stop = true;
	}
	dot.setPosition(115.f + (pos.x * 30), 115.f + (pos.y * 30));
}

void Dot::draw(sf::RenderWindow & window)
{
	window.draw(dot);
}

sf::Vector2f Dot::getPoss() const
{
	return dot.getPosition();
}
