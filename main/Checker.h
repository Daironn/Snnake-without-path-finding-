#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <vector>
#include <iostream>


struct checkerInfo {

	unsigned checkerID;
	unsigned onWhatSquare;

	bool killed = false;
	bool typeQueen = false;
	bool tagged;
};


class Checker
{
public:

	Checker(float radius, float x = 40, float y = 45) : radius(radius), position(sf::Vector2f(x, y)) {};
	~Checker() = default;
public:

	void fill();
	void draw(sf::RenderWindow & window);
	void update(sf::Vector2f mousePos, Board & BoardObject, bool & turn);
private:

	std::vector<sf::CircleShape> checkerArrayRED;
	unsigned checkerArrayREDInt = 0;

	std::vector<sf::CircleShape> checkerArrayBLACK;
	unsigned checkerArrayBLACKInt = 0;

	sf::Vector2f position;
	float radius;

	float spaceX = 0;
	float spaceY = 0;

	std::vector<checkerInfo> checkerArrayInfoBLACK;
	std::vector<checkerInfo> checkerArrayInfoRED;

	unsigned taggetOne;

	friend class Board;

};


