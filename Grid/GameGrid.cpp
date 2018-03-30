#include "GameGrid.h"
#include "../Marks/Cross.h"
#include "../Marks/Nought.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

Cross* crossObj = new Cross;
Nought* noughtObj = new Nought;

enum position {
	topLeft = 1, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight
};

GameGrid::GameGrid()
	:a(' '), b(' '), c(' '), d(' '), e(' '), f(' '), g(' '), h(' '), i(' ')
{
}
void GameGrid::printGameGrid()
{
	std::cout
		<< "                 " << a << " | " << b << " | " << c << "\n"
		<< "               -------------\n"
		<< "                 " << d << " | " << e << " | " << f << "\n"
		<< "               -------------\n"
		<< "                 " << g << " | " << h << " | " << i << "\n\n";
}

void GameGrid::printNumberedGameGrid() const
{
	std::cout
		<< "                   1  | 2 |  3  \n"
		<< "                 ---------------\n"
		<< "                   4  | 5 |  6  \n"
		<< "                 ---------------\n"
		<< "                   7  | 8 |  9 \n\n";
}

void GameGrid::markArea(Marks* markType, int position) {

	switch (position)
	{
	case topLeft:
		placePositionHuman(a, markType);
		break;
	case topMiddle:
		placePositionHuman(b, markType);
		break;
	case topRight:
		placePositionHuman(c, markType);
		break;
	case middleLeft:
		placePositionHuman(d, markType);
		break;
	case middleMiddle:
		placePositionHuman(e, markType);
		break;
	case middleRight:
		placePositionHuman(f, markType);
		break;
	case bottomLeft:
		placePositionHuman(g, markType);
		break;
	case bottomMiddle:
		placePositionHuman(h, markType);
		break;
	case bottomRight:
		placePositionHuman(i, markType);
	default:
		return;
	}
}



bool GameGrid::winCondition(Marks* markType)
{
	if (a == markType->mark && b == markType->mark && c == markType->mark)
	{
		return true;
	}
	else if (a == markType->mark && e == markType->mark && i == markType->mark)
	{
		return true;
	}
	else if (a == markType->mark && d == markType->mark && g == markType->mark)
	{
		return true;
	}
	else if (b == markType->mark && e == markType->mark && h == markType->mark)
	{
		return true;
	}
	else if (c == markType->mark && f == markType->mark && i == markType->mark)
	{
		return true;
	}
	else if (c == markType->mark && e == markType->mark && g == markType->mark)
	{
		return true;
	}
	else if (d == markType->mark && e == markType->mark && f == markType->mark)
	{
		return true;
	}
	else if (g == markType->mark && h == markType->mark && i == markType->mark)
	{
		return true;
	}
	else {
		return false;
	}

}

bool GameGrid::checkGridValue(int place)
{
	switch (place) {
	case 1:
		return a == ' ';
	case 2:
		return b == ' ';
	case 3:
		return c == ' ';
	case 4:
		return d == ' ';
	case 5:
		return e == ' ';
	case 6:
		return f == ' ';
	case 7:
		return g == ' ';
	case 8:
		return h == ' ';
	case 9:
		return i == ' ';

	}
}

void GameGrid::gridCleaner() {
	a = ' ';
	b = ' ';
	c = ' ';
	d = ' ';
	e = ' ';
	f = ' ';
	g = ' ';
	h = ' ';
	i = ' ';
}

bool GameGrid::checkPositionStatus(char& letter, Marks* markType) {
	if (letter == ' ') {
		return false;
	}
	else {
		return true;
	}
}

void GameGrid::placePositionHuman(char& letter, Marks* markType) {
	if (checkPositionStatus(letter, markType) == false) {
		letter = markType->mark;
	}
	else {
		if (identity != 'c') {
			std::cout << "-the place is marked already" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else {
			if (markType->mark == 'X') {
				computerOpponent(noughtObj);
				identity = 'h';
			}
			else  {
				computerOpponent(crossObj);
				identity = 'h';
			}
		}
	}
}


// :( 

void GameGrid::computerOpponent(Marks* markObj) {
	identity = 'c'; // for computer.
	//std::srand(std::time(0));
	int randomPosition = std::rand() % 10;
	placePositionComputer(e, markObj);
}

void GameGrid::placePositionComputer(char &letter, Marks* markType) {
	//std::srand(std::time(0));
	int randomPosition = std::rand() % 10;
	markArea(markType, randomPosition);
}

GameGrid::~GameGrid()
{
}