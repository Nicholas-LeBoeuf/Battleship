#pragma once
#include <iostream>
#include "Ship.h"
class Cruiser : public Ship
{
public:
	int nextSpot(int index, char orientation);

private:
	int counter = 1;
};

