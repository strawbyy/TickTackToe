#include <iostream>
#include "Marks\Marks.h"
#include "Marks\Cross.h"
#include "Marks\Nought.h"
#include "Grid\GameGrid.h"

void markChoice();
void gridReset(GameGrid* gridWiper);
void gridWipe();
void printNumberGrid();
void placeMarkHuman(Marks* marksObj, int markingPlace, GameGrid* grid);
void markFixer(Marks* markObj, GameGrid* gridObj, int markingPlace);
void checkWin(Marks* marksObj, GameGrid* gridObj);
void gameMenu();
void placeMarkComputer(Marks* marksObj, GameGrid* grid);

char markingChoice;

GameGrid* gridMain = new GameGrid;
Cross* mark_cross = new Cross;
Nought* mark_nought = new Nought;

int main()
{
	std::cout << "Welcome to this game of Tic Tac Toe\n\n" << std::endl;
	markChoice();
	std::cin.get();
	std::cin.get();
}

void markChoice()
{

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
				//markFixer(mark_cross, gridMain, markingPlace);
				placeMarkHuman(mark_cross, markingPlace, gridMain);
				checkWin(mark_cross, gridMain);
				placeMarkComputer(mark_nought, gridMain);
				checkWin(mark_nought, gridMain);
			}
			else // So if it's an O.
			{
				//markFixer(mark_nought, gridMain, markingPlace);
				placeMarkHuman(mark_nought, markingPlace, gridMain);
				checkWin(mark_nought, gridMain);
				placeMarkComputer(mark_cross, gridMain);
				checkWin(mark_cross, gridMain);
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

void gridReset(GameGrid* gridWiper) {
	gridWiper->gridCleaner();
	printNumberGrid();
}

void placeMarkHuman(Marks* marksObj, int markingPlace, GameGrid* grid) {
	grid->markArea(marksObj, markingPlace);
	gridWipe();
	grid->printGameGrid();
}

void placeMarkComputer(Marks* marksObj, GameGrid* grid) {
	grid->computerOpponent(marksObj);
	gridWipe();
	grid->printGameGrid();
}


void checkWin(Marks* marksObj, GameGrid* gridObj) {
	if (gridObj->winCondition(marksObj)) {
		std::cout << marksObj->mark << " won! \n";
		gameMenu();
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

void gameMenu() {
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1: Play another game, 2: Exit" << std::endl;
	
	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		gridReset(gridMain);
		int main();
		break;
	case 2:
		exit(0);
		break;
	default:
		return;
	}
}