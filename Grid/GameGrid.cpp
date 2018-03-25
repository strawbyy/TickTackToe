#include "GameGrid.h"
#include <iostream>


GameGrid::GameGrid()
{
}

void GameGrid::printGameGrid(Marks* mark)
{
	std::cout << "  ";
	mark->getMark();
	std::cout << " | ";
	mark->getMark();
	std::cout << " | ";
	mark->getMark();
	std::cout << "\n";

	std::cout << "-------------\n";

	std::cout << "  ";
	mark->getMark();
	std::cout << " | ";
	mark->getMark();
	std::cout << " | ";
	mark->getMark();
	std::cout << "\n";

	std::cout << "-------------\n";

	std::cout << "  ";
	mark->getMark();
	std::cout << " | ";
	mark->getMark();
	std::cout << " | ";
	mark->getMark();
	std::cout << "\n";

}

GameGrid::~GameGrid()
{
}

void GameGrid::printGameGrid() 
{
	std::cout << "  1  | 2 |  3  \n"
		<< "---------------\n"
		<< "  4  | 5 |  6  \n"
		<< "---------------\n"
		<< "  7  | 8 |  9 \n";

}
