#include "Cruiser.h"

int Cruiser::nextSpot(int index, char orientation)
{
	int val = 0;

	if (orientation == 'V')
		val = 10;
	else if (orientation == 'H')
		val = 1;

	if (counter != 3)
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

bool Cruiser::checkInvalidIndex(int index)
{
	for (int i = 0; i < 20; i++)
	{
		if (index == invalidCompIndex[i])
			return false;
	}
	return true;
}

void Cruiser::resetCounter()
{
	counter = 1;
}
