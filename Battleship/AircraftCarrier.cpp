#include "AircraftCarrier.h"
#include "Ship.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Ship.h"
#include "Submarine.h"
#include "Board.h"

int AircraftCarrier::nextSpot(int index, char orientation) //Goes to the next spot. If its vertical, it will +10, if its horizontal it will +1
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

bool AircraftCarrier::checkInvalidIndex(int index)  //For vertical orientation, anything with a starting index that will eventually run off the board will return false
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
