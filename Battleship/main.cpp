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
	Ship ship;
	AircraftCarrier aircraftCarrier;
	Battleship battleship;
	Cruiser cruiser;
	Destroyer destroyer;
	Submarine submarine;

	std::string userInput;
	int userSpot, userSpotTemp;
	char orientation;
	bool validPlacement = true;

	std::cout << "\t**********************************" << std::endl;
	std::cout << "\t\t    BATTLESHIP" << std::endl;
	std::cout << "\t**********************************\n\n" << std::endl;


	board.setChar();
	board.displayBoard();

	std::cout << "Specify where you want to place the edge of your ship. (Example 'A1')" << std::endl;
	std::cin >> userInput;
	while (!board.checkInput(userInput))
	{
		std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
		std::cin >> userInput;
	}

	userSpot = board.findArrayIndex(userInput);

	while (!board.checkForEmptySpot(userSpot))
	{
		std::cout << "Spot is already taken! Please choose another spot." << std::endl;
		std::cin >> userInput;
		while (!board.checkInput(userInput))
		{
			std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
			std::cin >> userInput;
		}
		userSpot = board.findArrayIndex(userInput);
	}

	orientation = aircraftCarrier.orientation();

	userSpotTemp = userSpot;
	
	while (userSpotTemp != 101)
	{
		userSpotTemp = aircraftCarrier.nextSpot(userSpot, orientation);
		if (board.checkForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
	}

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		for (int i = 1; i < 5; i++)
		{
			userSpot = aircraftCarrier.nextSpot(userSpot, orientation);
			board.updateBoard(userSpot);
		}

		board.displayBoard();
	}

	std::cin.get();
	return 0;
}