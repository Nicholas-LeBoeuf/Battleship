#include "Destroyer.h"

int Destroyer::nextSpot(int index, char orientation)
{
	int val = 0;

	if (orientation == 'V')
		val = 10;
	else if (orientation == 'H')
		val = 1;

	if (counter != 2)
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

bool Destroyer::checkInvalidIndex(int index)
{
	for (int i = 0; i < 10; i++)
	{
		if (index == invalidCompIndex[i])
			return false;
	}
	return true;
}

void Destroyer::resetCounter()
{
	counter = 1;
}
