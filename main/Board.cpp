#include "pch.h"
#include "Board.h"
#include "Checker.h"

Board::Board(float width, float height, float x, float y) :
	size(width, height), position(sf::Vector2f(x, y))
{

}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < squareArray.size(); i++)
		target.draw(squareArray[i], states);
}

void Board::fill()
{

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			squareArray.push_back(sf::RectangleShape());
			squareArray[squareArrayInt].setPosition(position.x + spaceX, position.y + spaceY);
			squareArray[squareArrayInt].setSize(sf::Vector2f(size.x, size.y));
			squareArray[squareArrayInt].setFillColor(sf::Color::Black);

			squareArrayInfo.push_back(squareInfo());
			squareArrayInfo[squareArrayInt].squareID = squareArrayInt;
			squareArrayInfo[squareArrayInt].Type = BLACK;

			if (squareArrayInt % 8 == 0)
				squareArrayInfo[squareArrayInt].line = 0;
			else if (squareArrayInt % 8 == 1)
				squareArrayInfo[squareArrayInt].line = 1;
			else if (squareArrayInt % 8 == 2)
				squareArrayInfo[squareArrayInt].line = 2;
			else if (squareArrayInt % 8 == 3)
				squareArrayInfo[squareArrayInt].line = 3;
			else if (squareArrayInt % 8 == 4)
				squareArrayInfo[squareArrayInt].line = 4;
			else if (squareArrayInt % 8 == 5)
				squareArrayInfo[squareArrayInt].line = 5;
			else if (squareArrayInt % 8 == 6)
				squareArrayInfo[squareArrayInt].line = 6;
			else if (squareArrayInt % 8 == 7)
				squareArrayInfo[squareArrayInt].line = 7;

			if (squareArrayInt < 8)
				squareArrayInfo[squareArrayInt].row = 0;

			else if (squareArrayInt > 7 && squareArrayInt < 16)
				squareArrayInfo[squareArrayInt].row = 1;

			else if (squareArrayInt > 15 && squareArrayInt < 24)
				squareArrayInfo[squareArrayInt].row = 2;

			else if (squareArrayInt > 23 && squareArrayInt < 32)
				squareArrayInfo[squareArrayInt].row = 3;

			else if (squareArrayInt > 31 && squareArrayInt < 40)
				squareArrayInfo[squareArrayInt].row = 4;

			else if (squareArrayInt > 39 && squareArrayInt < 48)
				squareArrayInfo[squareArrayInt].row = 5;

			else if (squareArrayInt > 47 && squareArrayInt < 56)
				squareArrayInfo[squareArrayInt].row = 6;

			else if (squareArrayInt > 55 && squareArrayInt < 64)
				squareArrayInfo[squareArrayInt].row = 7;




			squareArrayInt++;

			spaceX += size.x + 5;

		}
		spaceX = 0;
		spaceY += size.y + 5;
	}
	unsigned turn = 0;
	for (int row = 0; row < 64; row += 8) {

		if (turn % 2 == 0) {
			for (int i = 0; i < 8; i += 2) {
				squareArray[i + row].setFillColor(sf::Color::Red);
				squareArrayInfo[i + row].Type = RED;
			}
		}
		if (turn % 2 == 1) {
			for (int i = 1; i < 8; i += 2) {
				squareArray[i + row].setFillColor(sf::Color::Red);
				squareArrayInfo[i + row].Type = RED;
			}
		}
		turn++;
	}
}

void Board::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < squareArray.size(); i++)
		//if(!squareArrayInfo[i].killed)
		window.draw(squareArray[i]);
}

void Board::tagging(sf::Vector2f mousePos, Checker & eluwa)
{

	for (int j = 0; j < eluwa.checkerArrayBLACKInt; j++) {

		for (int i = 0; i < squareArray.size(); i++) {

			if (eluwa.checkerArrayBLACK[j].getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				for (int n = 0; n < eluwa.checkerArrayBLACKInt; n++) {

					eluwa.checkerArrayInfoBLACK[n].tagged = false;
					eluwa.checkerArrayInfoRED[n].tagged = false;
				}

				eluwa.checkerArrayInfoBLACK[j].tagged = true;

			}

		}
	}

	for (int j = 0; j < eluwa.checkerArrayREDInt; j++) {

		for (int i = 0; i < squareArray.size(); i++) {

			if (eluwa.checkerArrayRED[j].getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				for (int n = 0; n < eluwa.checkerArrayREDInt; n++) {

					eluwa.checkerArrayInfoRED[n].tagged = false;
					eluwa.checkerArrayInfoBLACK[n].tagged = false;
				}

				eluwa.checkerArrayInfoRED[j].tagged = true;

			}
		}
	}
}

void Board::update(Checker & eluwa)
{
	for (int i = 0; i < squareArray.size(); i++) {

		for (int j = 0; j < eluwa.checkerArrayBLACK.size(); j++) {

			if (squareArray[i].getGlobalBounds().contains(eluwa.checkerArrayBLACK[j].getPosition())) {

				squareArrayInfo[i].ifContainpawn = true;
				squareArrayInfo[i].isItBLACK = true;
			}
		}
	}

	for (int i = 0; i < squareArray.size(); i++) {

		for (int j = 0; j < eluwa.checkerArrayRED.size(); j++) {

			if (squareArray[i].getGlobalBounds().contains(eluwa.checkerArrayRED[j].getPosition())) {

				squareArrayInfo[i].ifContainpawn = true;
				squareArrayInfo[i].isItRED = true;
			}
		}
	}
}

void Board::check(sf::Vector2f mousePos, Checker & CheckerObject)
{

	for (int j = 0; j < squareArray.size(); j++) {

		for (int i = 0; i < CheckerObject.checkerArrayBLACK.size(); i++) {

			if (squareArray[j].getGlobalBounds().contains(CheckerObject.checkerArrayBLACK[i].getPosition())) {

				CheckerObject.checkerArrayInfoBLACK[i].onWhatSquare = j;
			}
		}
	}

	for (int j = 0; j < squareArray.size(); j++) {

		for (int i = 0; i < CheckerObject.checkerArrayRED.size(); i++) {

			if (squareArray[j].getGlobalBounds().contains(CheckerObject.checkerArrayRED[i].getPosition())) {

				CheckerObject.checkerArrayInfoRED[i].onWhatSquare = j;
			}
		}
	}
}