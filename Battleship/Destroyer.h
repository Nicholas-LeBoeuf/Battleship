#pragma once
#include <iostream>
#include "Ship.h"
class Destroyer : public Ship
{
public:
	int nextSpot(int index, char orientation);
	bool checkInvalidIndex(int index);
	void resetCounter();

private:
	int counter = 1;
	int invalidCompIndex[10] = { 9, 19, 29, 39, 49, 59, 69, 79, 89, 99 };
};

