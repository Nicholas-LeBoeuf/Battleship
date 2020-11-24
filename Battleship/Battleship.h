#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"
class Battleship : public Ship
{
public:
	int nextSpot(int index, char orientation);
	bool checkInvalidIndex(int index);
	void resetCounter();

private:
	int counter = 1;
	int invalidCompIndex[30] = { 7, 8, 9, 17, 18, 19, 27, 28, 29, 37, 38, 39, 47, 48, 49, 57, 58, 59, 67, 68, 69, 77, 78, 79, 87, 88, 89, 97, 98, 99 };
};

