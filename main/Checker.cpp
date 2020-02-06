#include "pch.h"
#include "Checker.h"
#include "pch.h"
#include "Checker.h"

void Checker::fill()
{

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 4; j++) {

			if (i != 1) {
				checkerArrayBLACK.push_back(sf::CircleShape());
				checkerArrayBLACK[checkerArrayBLACKInt].setPosition(position.x + spaceX, position.y + spaceY);
				checkerArrayBLACK[checkerArrayBLACKInt].setRadius(radius);
				checkerArrayBLACK[checkerArrayBLACKInt].setFillColor(sf::Color::Black);
				checkerArrayBLACK[checkerArrayBLACKInt].setOutlineThickness(10);
				checkerArrayBLACK[checkerArrayBLACKInt].setOutlineColor(sf::Color::Red);

				spaceX += radius + 190;
				checkerArrayInfoBLACK.push_back(checkerInfo());
				checkerArrayInfoBLACK[checkerArrayBLACKInt].checkerID = checkerArrayBLACKInt;
				checkerArrayInfoBLACK[checkerArrayBLACKInt].tagged = false;
				checkerArrayBLACKInt++;
			}

			if (i == 1) {

				checkerArrayBLACK.push_back(sf::CircleShape());
				checkerArrayBLACK[checkerArrayBLACKInt].setPosition(position.x + spaceX + 117, position.y + spaceY);
				checkerArrayBLACK[checkerArrayBLACKInt].setRadius(radius);
				checkerArrayBLACK[checkerArrayBLACKInt].setFillColor(sf::Color::Black);
				checkerArrayBLACK[checkerArrayBLACKInt].setOutlineThickness(10);
				checkerArrayBLACK[checkerArrayBLACKInt].setOutlineColor(sf::Color::Red);

				spaceX += radius + 190;
				checkerArrayInfoBLACK.push_back(checkerInfo());
				checkerArrayInfoBLACK[checkerArrayBLACKInt].checkerID = checkerArrayBLACKInt;
				checkerArrayInfoBLACK[checkerArrayBLACKInt].tagged = false;
				checkerArrayBLACKInt++;
			}
		}
		spaceX = 0;
		spaceY += radius + 72;
	}

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 4; j++) {

			if (i != 1) {

				checkerArrayRED.push_back(sf::CircleShape());
				checkerArrayRED[checkerArrayREDInt].setPosition(position.x + spaceX + 117, position.y + spaceY + 235);
				checkerArrayRED[checkerArrayREDInt].setRadius(radius);
				checkerArrayRED[checkerArrayREDInt].setFillColor(sf::Color::Red);
				checkerArrayRED[checkerArrayREDInt].setOutlineThickness(10);
				checkerArrayRED[checkerArrayREDInt].setOutlineColor(sf::Color::Black);

				spaceX += radius + 190;

				checkerArrayInfoRED.push_back(checkerInfo());
				checkerArrayInfoRED[checkerArrayREDInt].checkerID = checkerArrayBLACKInt;
				checkerArrayInfoRED[checkerArrayREDInt].tagged = false;

				checkerArrayREDInt++;

			}

			if (i == 1) {

				checkerArrayRED.push_back(sf::CircleShape());
				checkerArrayRED[checkerArrayREDInt].setPosition(position.x + spaceX, position.y + spaceY + 235);
				checkerArrayRED[checkerArrayREDInt].setRadius(radius);
				checkerArrayRED[checkerArrayREDInt].setFillColor(sf::Color::Red);
				checkerArrayRED[checkerArrayREDInt].setOutlineThickness(10);
				checkerArrayRED[checkerArrayREDInt].setOutlineColor(sf::Color::Black);

				spaceX += radius + 190;

				checkerArrayInfoRED.push_back(checkerInfo());
				checkerArrayInfoRED[checkerArrayREDInt].checkerID = checkerArrayBLACKInt;
				checkerArrayInfoRED[checkerArrayREDInt].tagged = false;

				checkerArrayREDInt++;
			}
		}
		spaceX = 0;
		spaceY += radius + 72;
	}

}


void Checker::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < checkerArrayRED.size(); i++)
		window.draw(checkerArrayRED[i]);
	for (int i = 0; i < checkerArrayBLACK.size(); i++)
		window.draw(checkerArrayBLACK[i]);
}

void Checker::update(sf::Vector2f mousePos, Board & BoardObject, bool & turn)
{
	if (turn) {
		for (int j = 0; j < BoardObject.squareArray.size(); j++) {

			for (int i = 0; i < checkerArrayBLACKInt; i++) {

				if (checkerArrayInfoBLACK[i].tagged == true) {



					checkerArrayBLACK[i].setOutlineColor(sf::Color::Green);

					if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].line == 0) {

						if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row < 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;



										turn = false;
									}
								}
							}

							else if ((BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;

										/*		BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].killed = true;
												BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = false;
												BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = false;
												BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItRED = false;*/

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;


										turn = false;
									}
								}
							}
						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}

						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 7) {

							checkerArrayInfoBLACK[i].typeQueen = true;

						}
					}
					else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].line == 7) {

						if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row < 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}

							else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}

						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 7) {

							checkerArrayInfoBLACK[i].typeQueen = true;

						}
					}
					else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].line == 1) {

						if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row < 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							else if ((BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}

						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 7) {

							checkerArrayInfoBLACK[i].typeQueen = true;

						}
					}
					else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].line == 6) {
						if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row < 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}

						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 7) {

							checkerArrayInfoBLACK[i].typeQueen = true;

						}
					}
					else {

						if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row < 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 14].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							else if ((BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 18].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 6) {

							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 14].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 7].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
							if ((!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && !BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)
								|| (!BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn && BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 18].ifContainpawn)) {

								BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayBLACK[i].setPosition(BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoBLACK[i].onWhatSquare + 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].ifContainpawn = false;


										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare + 9].isItBLACK = true;
										BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].isItBLACK = false;

										turn = false;
									}
								}
							}
						}
						else if (BoardObject.squareArrayInfo[checkerArrayInfoBLACK[i].onWhatSquare].row == 7) {

							checkerArrayInfoBLACK[i].typeQueen = true;

						}
					}

					checkerArrayBLACK[i].setOutlineColor(sf::Color::Red);


					if (BoardObject.squareArrayInfo[j].Type == RED) {

						BoardObject.squareArray[j].setFillColor(sf::Color::Red);
						BoardObject.squareArrayInfo[j].ableToTake = false;
					}
					else if (BoardObject.squareArrayInfo[j].Type == BLACK) {

						BoardObject.squareArray[j].setFillColor(sf::Color::Black);
						BoardObject.squareArrayInfo[j].ableToTake = false;
					}
				}
			}
		}
	}


	else if (!turn) {
		for (int j = 0; j < BoardObject.squareArray.size(); j++) {

			for (int i = 0; i < checkerArrayREDInt; i++) {

				if (checkerArrayInfoRED[i].tagged == true) {

					taggetOne = i;
					checkerArrayRED[i].setOutlineColor(sf::Color::Green);

					if (BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].line == 0) {

						if (BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].row > 0) {

							if (!BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 7].ifContainpawn) {

								BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 7].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayRED[i].setPosition(BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].ifContainpawn = false;



										turn = true;
									}
								}
							}
						}
					}
					else if (BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].line == 7) {

						if (BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].row > 0) {

							if (!BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 9].ifContainpawn) {

								BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayRED[i].setPosition(BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].ifContainpawn = false;

										turn = true;
									}
								}
							}
						}
					}
					else {
						if (BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].row > 0) {

							if (!BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 9].ifContainpawn) {

								BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 9].ableToTake = true;

								if (BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayRED[i].setPosition(BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 9].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 9].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].ifContainpawn = false;

										turn = true;
									}
								}

							}
							if (!BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 7].ifContainpawn) {

								BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].setFillColor(sf::Color::Green);

								BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 7].ableToTake = true;


								if (BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].getGlobalBounds().contains(mousePos)) {

									if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

										checkerArrayRED[i].setPosition(BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].getPosition().x + 12,
											BoardObject.squareArray[checkerArrayInfoRED[i].onWhatSquare - 7].getPosition().y + 12);

										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare - 7].ifContainpawn = true;
										BoardObject.squareArrayInfo[checkerArrayInfoRED[i].onWhatSquare].ifContainpawn = false;

										turn = true;
									}
								}
							}
						}
					}

				}
				checkerArrayRED[i].setOutlineColor(sf::Color::Black);
			}
			if (BoardObject.squareArrayInfo[j].Type == RED) {

				BoardObject.squareArray[j].setFillColor(sf::Color::Red);
				BoardObject.squareArrayInfo[j].ableToTake = false;
			}
			else if (BoardObject.squareArrayInfo[j].Type == BLACK) {

				BoardObject.squareArray[j].setFillColor(sf::Color::Black);
				BoardObject.squareArrayInfo[j].ableToTake = false;
			}
		}
	}
}