#include <iostream>
#include "Marks\Marks.h"
#include "Marks\Cross.h"
#include "Marks\Nought.h"
#include "Grid\GameGrid.h"

void markChoice();
void gridReset();
void gridWipe();
void printNumberGrid();
void placeMark(Marks* marksObj, int markingPlace, GameGrid* grid);
void markFixer(Marks* markObj, GameGrid* gridObj, int markingPlace);
void checkWin(Marks* marksObj, GameGrid* gridObj);

char markingChoice;

int main()
{
	std::cout << "Welcome to this game of Tic Tac Toe\n\n" << std::endl;

	markChoice();

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
				markFixer(mark_cross, gridMain, markingPlace);
				placeMark(mark_cross, markingPlace, gridMain);
				checkWin(mark_cross, gridMain);
			}
			else // So if it's an O.
			{
				markFixer(mark_nought, gridMain, markingPlace);
				placeMark(mark_nought, markingPlace, gridMain);
				checkWin(mark_nought, gridMain);
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

void placeMark(Marks* marksObj, int markingPlace, GameGrid* grid) {
	grid->markArea(marksObj, markingPlace);
	gridWipe();
	grid->printGameGrid();
}

void checkWin(Marks* marksObj, GameGrid* gridObj) {
	if (gridObj->winCondition(marksObj)) {
		std::cout << marksObj->mark << " won! \n";
		std::cout << "To exit, hit enter" << std::endl;
		std::cin.get();
		exit(0);
	}
}

// this is to ensure the user can place his own mark even after he made a mistake, choosing a spot with an existing mark
void markFixer(Marks* markObj, GameGrid* gridObj, int markingPlace) {
	if (gridObj->checkGridValue(markingPlace) == true) {
		if (markObj->mark == 'O') {
			markingChoice = 'X';
		}
		else {
			markingChoice = 'O';
		}
	}
	else {
		markingChoice = markObj->mark;
	}
}