/*****************************************************************
Program: Battleship (Project 2)
Purpose: To create a real life game using objects and inheritance
Author: Nicholas LeBoeuf
Date: November 20th, 2020
*****************************************************************/
#include <iostream>

#include "Ship.h"
#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Ship.h"
#include "Submarine.h"
#include "Board.h"

int main()
{
	Board board;
	std::string userInput;

	std::cout << "\t**********************************" << std::endl;
	std::cout << "\t\t    BATTLESHIP" << std::endl;
	std::cout << "\t**********************************\n\n" << std::endl;


	board.setChar();
	board.displayBoard();
	
	std::cout << "Input place: ";
	std::cin >> userInput;

	if (board.checkInput(userInput))
		board.checkForNull(userInput);
	else
		std::cout << "false";

	std::cin.get();
	return 0;
}