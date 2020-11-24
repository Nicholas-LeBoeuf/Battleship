#pragma once
#include <iostream>
#include "Ship.h"
class Cruiser : public Ship
{
public:
	int nextSpot(int index, char orientation);
	bool checkInvalidIndex(int index);
	void resetCounter();

private:
	int counter = 1;
	int invalidCompIndex[20] = { 8, 9, 18, 19, 28, 29, 38, 39, 48, 49, 58, 59, 68, 69, 78, 79, 88, 89, 98, 99 };
};

