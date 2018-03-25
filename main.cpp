#include <iostream>
#include "Marks\Marks.h"
#include "Marks\Cross.h"
#include "Marks\Nought.h"
#include "Grid\GameGrid.h"

void markChoice();


int main()
{
	std::cout << "Welcome to this game of TicTacToe\n\n" << std::endl;
	GameGrid grid;
	Cross* mark_cross = new Cross;
	Nought* mark_nought = new Nought;

	grid.printGameGrid();

	//grid.printGameGrid(mark_cross);


	std::cin.get();
}

void markChoice() {
	std::cout << "what mark would you like to be? (X/O)\n";
	char markingChoice;
	std::cin >> markingChoice;

	if (markingChoice == 'x' || markingChoice == 'o') {
		std::cout << "where would you like to place your cursor? (1-9)";
		int markingPlace;
		std::cin >> markingPlace;
		if (markingChoice == 'x') {
			Cross* mark_cross = new Cross;
		}
	}
	else {
		markChoice();
	}
}