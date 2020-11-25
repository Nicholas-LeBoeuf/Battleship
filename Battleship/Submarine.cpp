#include "Submarine.h"

int Submarine::nextSpot(int index, char orientation) //Goes to the next spot. If its vertical, it will +10, if its horizontal it will +1
{
	int val = 0;

	if (orientation == 'V')
		val = 10;
	else if (orientation == 'H')
		val = 1;

	if (counter != 1)
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

void Submarine::resetCounter()
{
	counter = 1;
}