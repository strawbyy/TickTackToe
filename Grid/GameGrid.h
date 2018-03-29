#pragma once
#include "../Marks/Marks.h"
class GameGrid
{
public:
	GameGrid();
	void printGameGrid();
	void printNumberedGameGrid() const;
	void markArea(Marks*, int);
	bool winCondition(Marks*);
	bool checkGridValue(int);
	enum position{};
	bool playerTurn;
	void checkPositionStatus(char&, Marks*);
	void gridCleaner();
	~GameGrid();
private:
	char a, b, c, d, e, f, g, h, i;

};

