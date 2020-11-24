#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"
class AircraftCarrier : public Ship
{
public:
	int nextSpot(int index, char orientation);
	bool checkInvalidIndex(int index);
	void resetCounter();
	
private:
	int counter = 1;
	int invalidCompIndex[40] = { 6, 7, 8, 9, 16, 17, 18, 19, 26, 27, 28, 29, 36, 37, 38, 39, 46, 47, 48, 49, 56, 57, 58, 59, 66, 67, 68, 69, 76, 77, 78, 79, 86, 87, 88, 89, 96, 97, 98, 99 };
};

