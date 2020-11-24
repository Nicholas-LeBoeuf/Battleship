#include "AircraftCarrier.h"
#include "Ship.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Ship.h"
#include "Submarine.h"
#include "Board.h"

int AircraftCarrier::nextSpot(int index, char orientation)
{	
	int val = 0;

	if (orientation == 'V')
		val = 10;
	else if (orientation == 'H')
		val = 1;

	if (counter != 5)
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

bool AircraftCarrier::checkInvalidIndex(int index)
{
	for (int i = 0; i < 40; i++)
	{
		if (index == invalidCompIndex[i])
			return false;
	}
	return true;
}

void AircraftCarrier::resetCounter()
{
	counter = 1;
}
