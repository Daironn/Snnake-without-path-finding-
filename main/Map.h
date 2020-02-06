#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Map
{
private:
	friend class Snake;

	const float square_size = 30;
	const float sizeX;
	const float sizeY;

	std::vector<std::vector<sf::RectangleShape>> map;
	std::vector<std::vector<sf::Vector2f>> blockpos;
public:
	void fill_map();
	void draw(sf::RenderWindow & window);

public:
	Map(float X, float Y);
	~Map() = default;
};
//ghost