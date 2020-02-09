#include "pch.h"
#include "Map.h"

void Map::fill_map()
{

	for (int i(0); i < sizeX; i++) {

		std::vector<sf::RectangleShape> pion;

		for (int j(0); j < sizeY; j++) {

			sf::RectangleShape shape(sf::Vector2f(square_size, square_size));

			if ((i != sizeX-1 && j != sizeY-1) && (i != 0 && j != 0)) {

				shape.setFillColor(sf::Color::Black);
				shape.setOutlineThickness(1);
				shape.setOutlineColor(sf::Color::Black);
	
			}
			else {
				shape.setFillColor(sf::Color::Red);
				shape.setOutlineThickness(1);
				shape.setOutlineColor(sf::Color::Red);
			}
			shape.setPosition(80.f + (square_size*i), 80.f + (square_size*j));
			pion.push_back(shape);
		}
		map.push_back(pion);
	}
}

void Map::draw(sf::RenderWindow & window)
{
	for (int i(0); i < sizeX; i++) {
		for (int j(0); j < sizeY; j++) {
			window.draw(map[i][j]);
		}
	}
}

Map::Map(float X, float Y):sizeX(X), sizeY(Y)
{
	this->fill_map();
}
