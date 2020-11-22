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
	int userSpot, userSpotTemp, counter;
	char orientation;
	bool validPlacement = true;

	std::cout << "\t**********************************" << std::endl;
	std::cout << "\t\t    BATTLESHIP" << std::endl;
	std::cout << "\t**********************************\n\n" << std::endl;


	board.setChar();
	board.displayBoard();

	//Place aircraft carrier start
	std::cout << "Specify where you want to place the edge of your Aircraft Carrier (5 spaces). (Example 'A1')" << std::endl;
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
	counter = 1;
	while (counter != 6)
	{
		userSpotTemp = aircraftCarrier.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.checkForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
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
	//End of placing aircraft carrier


	//Place battleship start
	std::cout << "Specify where you want to place the edge of your Battleship (4 spaces). (Example 'A1')" << std::endl;
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

	orientation = battleship.orientation();

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 5)
	{
		userSpotTemp = battleship.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.checkForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		for (int i = 1; i < 4; i++)
		{
			userSpot = battleship.nextSpot(userSpot, orientation);
			board.updateBoard(userSpot);
		}

		board.displayBoard();
	}
	//End of placing battleship

	//Place cruiser start
	std::cout << "Specify where you want to place the edge of your Cruiser (3 spaces). (Example 'A1')" << std::endl;
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

	orientation = cruiser.orientation();

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 4)
	{
		userSpotTemp = cruiser.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.checkForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		for (int i = 1; i < 3; i++)
		{
			userSpot = cruiser.nextSpot(userSpot, orientation);
			board.updateBoard(userSpot);
		}

		board.displayBoard();
	}
	//End of placing cruiser


	//Place first destroyer start
	std::cout << "Specify where you want to place the edge of your first Destroyer (2 spaces). (Example 'A1')" << std::endl;
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

	orientation = destroyer.orientation();

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 3)
	{
		userSpotTemp = destroyer.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.checkForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		for (int i = 1; i < 2; i++)
		{
			userSpot = destroyer.nextSpot(userSpot, orientation);
			board.updateBoard(userSpot);
		}

		board.displayBoard();
	}
	//End of placing first destroyer

	//Place second destroyer start
	std::cout << "Specify where you want to place the edge of your second Destroyer (2 spaces). (Example 'A1')" << std::endl;
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

	orientation = destroyer.orientation();

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 3)
	{
		userSpotTemp = destroyer.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.checkForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		for (int i = 1; i < 2; i++)
		{
			userSpot = destroyer.nextSpot(userSpot, orientation);
			board.updateBoard(userSpot);
		}

		board.displayBoard();
	}
	//End of placing second destroyer


	//Place first submarine start
	std::cout << "Specify where you want to place the edge of your first Submarine (1 Space). (Example 'A1')" << std::endl;
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

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		board.displayBoard();
	}
	//End of placing first submarine


	//Place second submarine start
	std::cout << "Specify where you want to place the edge of your second Submarine (1 Space). (Example 'A1')" << std::endl;
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

	if (validPlacement == true)
	{
		board.updateBoard(userSpot);
		board.displayBoard();
	}
	//End of placing second submarine

	std::cin.get();
	return 0;
}