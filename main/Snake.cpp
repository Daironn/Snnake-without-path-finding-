#include "pch.h"
#include "Map.h"
#include "Snake.h"
#include "Dot.h"
#include <time.h>

Snake::Snake() :dire(Up)
{
	srand(time(NULL));
	int v1 = rand() % 23;
	int v2 = rand() % 23;

	sf::CircleShape pion;
	pion.setRadius(10);
	pion.setFillColor(sf::Color::White);
	pion.setOutlineThickness(1);
	pion.setOutlineColor(sf::Color::White);
	pion.setPosition(115.f + (v1 * 30), 115.f + (v2 * 30));
	body.push_back(pion);
	body.push_back(pion);

	this->dire = Stop;
}

void Snake::update(sf::Event & event, Map & map, Dot & dot)
{

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
		std::cout << "SPACE";

		int v1 = rand() % 23;
		int v2 = rand() % 23;

		body[0].setPosition(115.f + (v1 * 30), 115.f + (v2 * 30));
		for (int i = 1; i < body.size()-1; i++) {
			body.pop_back();
		}
		died = false;
		dire = Stop;
	}
	
	for (int i = 0; i < map.sizeY; i++) {

		if (body[0].getPosition().y < map.map[0][1].getPosition().y
			|| body[0].getPosition().y > map.map[0][map.sizeY - 1].getPosition().y) {

			died = true;
		}
	}
	for (int i = 0; i < map.sizeY; i++) {

		if (body[0].getPosition().x < map.map[1][0].getPosition().x
			|| body[0].getPosition().x > map.map[map.sizeX - 1][0].getPosition().x) {
			died = true;
		}
	}

	if (body[0].getPosition() == dot.getPoss()) {
			addNext = true;
	}

	for (int i = 2; i < body.size() - 1; i++) {
		if (body[0].getPosition() == body[i].getPosition())
			this->died = true;
	}
	this->move();

	if (addNext == true) {

		body.push_back(body[0]);
		body[0+body.size()-1].setPosition(dot.getPoss());

		dot.spawn(this);

		addNext = false;
	}
}

void Snake::draw(sf::RenderWindow & window)
{	
	for(auto i: body)
	window.draw(i);
}

void Snake::move()
{


	if (!died) {
		if (dire == Left)
			body[0].setPosition(body[0].getPosition().x - 30, body[0].getPosition().y);
		else if (dire == Right)
			body[0].setPosition(body[0].getPosition().x + 30, body[0].getPosition().y);
		else if (dire == Up)
			body[0].setPosition(body[0].getPosition().x, body[0].getPosition().y - 30);
		else if (dire == Down)
			body[0].setPosition(body[0].getPosition().x, body[0].getPosition().y + 30);


		for (int i = body.size() - 1; i > 0; i--) {
			body[i].setPosition(body[i - 1].getPosition());
		}
		canmove = true;
	}
	else{

		std::cout << "U died"<<std::endl;
	}

	
}

void Snake::eventCatcher(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if ((event.key.code == sf::Keyboard::Left && canmove == true) && dire != Right)
		{
			this->dire = Left;

		}
		if ((event.key.code == sf::Keyboard::Right && canmove == true) && dire != Left) {

			this->dire = Right;

		}
		if ((event.key.code == sf::Keyboard::Up && canmove == true) && dire != Down) {

			this->dire = Up;

		}
		if ((event.key.code == sf::Keyboard::Down && canmove == true) && dire != Up) {

			this->dire = Down;


		}

		canmove = false;
	}
}
