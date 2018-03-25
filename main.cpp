#include <iostream>
#include "Marks\Marks.h"
#include "Marks\Cross.h"
#include "Marks\Nought.h"
#include "Grid\GameGrid.h"

void markChoice();


int main()
{
	std::cout << "Welcome to this game of TicTacToe\n\n" << std::endl;
	GameGrid* gridMain = new GameGrid;
	gridMain->printNumberedGameGrid();
	markChoice();
	gridMain->printGameGrid();

	//grid.printGameGrid(mark_cross);


	std::cin.get();
}

void markChoice()
{
	std::cout << "what mark would you like to be? (X/O)\n";
	char markingChoice;
	std::cin >> markingChoice;
	enum position {
		topLeft = 1, topMiddle, topRight, middleLeft, middleMiddle, middleRight, bottomLeft, bottomMiddle, bottomRight
	};

	if (markingChoice == 'X' || markingChoice == 'O' || markingChoice == 'x' || markingChoice == 'o') {
		std::cout << "\nwhere would you like to place your cursor? (1-9): ";
		int markingPlace;
		std::cin >> markingPlace;

		if (markingChoice == 'x') {
			Cross* mark_cross = new Cross;
			GameGrid grid;
			grid.markArea(mark_cross, markingPlace);
		}
		else {
			Nought* mark_nought = new Nought;
		}


	}

	std::cin.get();
}