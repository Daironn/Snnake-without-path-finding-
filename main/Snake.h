#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum directions{Left,Right,Up,Down,Stop};

class Map;
class Dot;
class Ghost_snake;
class Snake
{

friend class Dot;

private:
	directions dire;

	bool died = false;
	bool canmove = true;
	bool addNext = false;

	sf::Vector2f current_pos;
protected:

	std::vector<sf::CircleShape> body;

public:

	Snake();
	~Snake() = default;
public:
	virtual void update(sf::Event & event, Map & map, Dot & dot);
	virtual void draw(sf::RenderWindow & window);
	void eventCatcher(sf::Event & event);
private:
	void move();


};

