#include "Battleship.h"

int Battleship::nextSpot(int index, char orientation)
{
	int val = 0;

	if (orientation == 'V')
		val = 10;
	else if (orientation == 'H')
		val = 1;

	if (counter != 4)
	{
		index = index + val;
		counter++;
		return index;
	}
	else
	{
		counter = 1;
		return NULL;
	}
}

bool Battleship::checkInvalidIndex(int index)
{
	for (int i = 0; i < 30; i++)
	{
		if (index == invalidCompIndex[i])
			return false;
	}
	return true;
}

void Battleship::resetCounter()
{
	counter = 1;
}
