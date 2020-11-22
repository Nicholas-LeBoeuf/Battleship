#include <iostream>
#include "Ship.h"

char Ship::orientation()
{
	char ori;

	std::cout << "Would you like to place your ship vertical or horizontal?" << std::endl;
	std::cout << "Please type 'V' for vertical or 'H' for horizontal" << std::endl;
	std::cin >> ori;

	while (ori != 'V' && ori != 'H')
	{
		std::cout << "Invalid input, please type 'V' or 'H'." << std::endl;
		std::cin >> ori;
	}

	return ori;
}
