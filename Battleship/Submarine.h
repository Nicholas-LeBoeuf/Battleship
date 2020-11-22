#pragma once
#include <iostream>
#include "Ship.h"
class Submarine : public Ship
{
public:
	int nextSpot(int index, char orientation);

private:
	int counter = 1;
};

