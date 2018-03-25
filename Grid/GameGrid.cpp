#include "GameGrid.h"
#include <iostream>

enum position {
	topLeft = 1, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight
};

GameGrid::GameGrid()
{
}
void GameGrid::printGameGrid()
{
	std::cout
		<< "  " << a << " | " << b << " | " << c << "\n"
		<< "-------------\n"
		<< "  " << d << " | " << e << " | " << f << "\n"
		<< "-------------\n"
		<< "  " << g << " | " << h << " | " << i << "\n";
}

void GameGrid::printNumberedGameGrid() const
{
	std::cout 
		<< "  1  | 2 |  3  \n"
		<< "---------------\n"
		<< "  4  | 5 |  6  \n"
		<< "---------------\n"
		<< "  7  | 8 |  9 \n";
}

void GameGrid::markArea(Marks* markType, int position) {
	switch (position)
	{
	case topLeft:
		a = markType->mark;
		break;
	case topMiddle:
		b = markType->mark;
		break;
	case topRight:
		c = markType->mark;
		break;
	case middleLeft:
		d = markType->mark;
		break;
	case middleMiddle:
		e = markType->mark;
		break;
	case middleRight:
		f = markType->mark;
		break;
	case bottomLeft:
		g = markType->mark;
		break;
	case bottomMiddle:
		h = markType->mark;
		break;
	default:
		i = markType->mark;
	}
}

GameGrid::~GameGrid()
{
}