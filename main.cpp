#include <iostream>
#include "Marks\Marks.h"
#include "Marks\Cross.h"
#include "Marks\Nought.h"
#include "Grid\GameGrid.h"

void markChoice();
void gridReset();
void gridWipe();
void printNumberGrid();

int main()
{
	std::cout << "Welcome to this game of Tic Tac Toe\n\n" << std::endl;

	markChoice();

	std::cout << "Congratulations!" << std::endl;

	std::cin.get();
	std::cin.get();
}

void markChoice()
{

	GameGrid* gridMain = new GameGrid;
	Cross* mark_cross = new Cross;
	Nought* mark_nought = new Nought;

	gridMain->printNumberedGameGrid();

	std::cout << "what mark would you like to be? (X/O)\nInput 1 to quit. Choice: ";
	char markingChoice;
	std::cin >> markingChoice;

	while (markingChoice != 1)
	{
		if (markingChoice == 'X' || markingChoice == 'O' || markingChoice == 'x' || markingChoice == 'o')
		{
			std::cout << "\nwhere would you like to place your cursor? (1-9): ";
			int markingPlace;
			std::cin >> markingPlace;

			if (markingChoice == 'x' || markingChoice == 'X') 
			{
				if (gridMain->checkGridValue(markingPlace) == true) {
					markingChoice = 'o';
				}
				else {
					markingChoice = 'x';
				}
				gridMain->markArea(mark_cross, markingPlace);
				gridWipe();
				gridMain->printGameGrid();

				if (gridMain->winCondition(mark_cross)) {
					std::cout << mark_cross->mark << " WON!\n";
					return;
				}
			}
			else 
			{
				if (gridMain->checkGridValue(markingPlace) == true) {
					markingChoice = 'x';
				}
				else {
					markingChoice = 'o';
				}
				gridMain->markArea(mark_nought, markingPlace);
				gridWipe();
				gridMain->printGameGrid();

				if (gridMain->winCondition(mark_nought)) {
					std::cout << mark_nought->mark << " won!";
					return;
				}
			}
		}


	}

	std::cin.get();
}

void printNumberGrid()
{
	GameGrid gridNumber;
	gridNumber.printNumberedGameGrid();
}

void gridWipe() {
	system("CLS");
	std::cout << "----------------Tick Tac Toe-----------------\n\n";
}

void gridReset() {
	GameGrid gridWiper;
	gridWiper.gridCleaner();
	std::cout << "It was a tie!" << std::endl;
}