#pragma once
#include <iostream>
#include "Ship.h"
#include "Board.h"
class Battleship : public Ship
{
public:
	int nextSpot(int index, char orientation);

private:
	int counter = 1;
};

