#pragma once
#include <iostream>
#include "Ship.h"
class Submarine : public Ship
{
public:
	int nextSpot(int index, char orientation);
	void resetCounter();

private:
	int counter = 1;
};

