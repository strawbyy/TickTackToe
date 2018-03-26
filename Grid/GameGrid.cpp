#include "GameGrid.h"
#include <iostream>

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
		if (a == ' ')
		{
			a = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
		break;
	case topMiddle:
		if (b == ' ')
		{
			b = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
		break;
	case topRight:
		if (c == ' ')
		{
			c = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
		break;
	case middleLeft:
		if (d == ' ')
		{
			d = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
		break;
	case middleMiddle:
		if (e == ' ')
		{
			e = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
		break;
	case middleRight:
		if (f == ' ')
		{
			f = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		};
		break;
	case bottomLeft:
		if (g == ' ')
		{
			g = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
		break;
	case bottomMiddle:
		if (h == ' ') {
			h = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already\n" << std::endl;
		}
		break;
	default:
		if (i == ' ') {
			i = markType->mark;
		}
		else {
			std::cout << "\nthe place is marked already" << std::endl;
		}
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
		if (a == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 2:
		if (b == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 3:
		if (c == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 4:
		if (d == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 5:
		if (e == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 6:
		if (f == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 7:
		if (g == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 8:
		if (h == ' ') {
			return false;
		}
		else {
			return true;
		}
	case 9:
		if (i == ' ') {
			return false;
		}
		else {
			return true;
		}
	}
}

GameGrid::~GameGrid()
{
}