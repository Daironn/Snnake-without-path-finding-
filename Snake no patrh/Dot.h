#pragma once
#include "Snake.h"
class Dot :
	public Snake
{

public:
	Dot(const Snake * snake);
	~Dot();
private:

	sf::Vector2f pos;
	sf::CircleShape dot;

	bool possible;
public:
	void spawn(const Snake * snake);
	void draw(sf::RenderWindow & window);
public:
	sf::Vector2f getPoss() const;

};

