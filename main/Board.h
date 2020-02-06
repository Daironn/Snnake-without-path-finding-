#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <vector>

enum squareType { RED = 0, BLACK = 1 };

struct squareInfo {

	squareType Type;

	unsigned squareID;

	unsigned row;
	unsigned line;

	bool ableToTake;
	bool ifContainpawn;
	bool isItRED;
	bool isItBLACK;
	//bool killed = false;

};
class Checker;
class Board :
	public sf::Drawable
{
public:

	Board(float width, float height, float x = 30, float y = 35);
	~Board() = default;
public:

	void fill();
	void draw(sf::RenderWindow & window);
	void tagging(sf::Vector2f mousePos, Checker & CheckerObject);
	void update(Checker & CheckerObject);
	void check(sf::Vector2f mousePos, Checker & CheckerObject);
private:

	std::vector<squareInfo> squareArrayInfo;

	std::vector<sf::RectangleShape> squareArray;
	unsigned squareArrayInt = 0;

	sf::Vector2f position;
	sf::Vector2f size;

	float spaceX = 0;
	float spaceY = 0;

	bool turn = false;

	friend class Checker;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};