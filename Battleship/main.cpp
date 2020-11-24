/*****************************************************************
Program: Battleship (Project 2)
Purpose: To create a real life game using objects and inheritance
Author: Nicholas LeBoeuf
Date: November 20th, 2020
*****************************************************************/
#include <iostream>
#include <Windows.h>

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
	int userSpot, userSpotTemp, counter, maxIndex, compSpot, compSpotTemp;
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

	board.setCompChar();

	//Computer placing ships on board
	aircraftCarrier.resetCounter();
	//Aircraft carrier
	validPlacement = false;
	while (validPlacement == false) {
		orientation = aircraftCarrier.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 60;
			compSpot = aircraftCarrier.computerRandomIndex(maxIndex);

			while (!board.checkForEmptySpot(compSpot))
			{
				compSpot = aircraftCarrier.computerRandomIndex(maxIndex);
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 6)
			{
				compSpotTemp = aircraftCarrier.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
		else if (orientation == 'H')
		{
			maxIndex = 100;

			int f = 0;
			while (f < 1)
			{
				compSpot = aircraftCarrier.computerRandomIndex(maxIndex);
				if (aircraftCarrier.checkInvalidIndex(compSpot))
					if (board.checkForEmptySpot(compSpot))
						break;
					else
						continue;
				else
					continue;
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 6)
			{
				compSpotTemp = aircraftCarrier.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		for (int i = 1; i < 5; i++)
		{
			compSpot = aircraftCarrier.nextSpot(compSpot, orientation);
			if (compSpot == NULL)
				break;
			board.updateCompBoard(compSpot);
		}
		//board.displayCompBoard();
	}
	Sleep(3000);
	battleship.resetCounter();
	//Battleship
	validPlacement = false;
	while (validPlacement == false) {
		orientation = battleship.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = battleship.computerRandomIndex(maxIndex);

			while (!board.checkForEmptySpot(compSpot))
			{
				compSpot = battleship.computerRandomIndex(maxIndex);
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 5)
			{
				compSpotTemp = battleship.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
		else if (orientation == 'H')
		{
			maxIndex = 100;

			int f = 0;
			while (f < 1)
			{
				compSpot = battleship.computerRandomIndex(maxIndex);
				if (battleship.checkInvalidIndex(compSpot))
					if (board.checkForEmptySpot(compSpot))
						break;
					else
						continue;
				else
					continue;
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 5)
			{
				compSpotTemp = battleship.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		for (int i = 1; i < 5; i++)
		{
			compSpot = battleship.nextSpot(compSpot, orientation);
			if (compSpot == NULL)
				break;
			board.updateCompBoard(compSpot);
		}
		//board.displayCompBoard();
	}
	Sleep(3000);
	//Cruiser Start
	cruiser.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		orientation = cruiser.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = cruiser.computerRandomIndex(maxIndex);

			while (!board.checkForEmptySpot(compSpot))
			{
				compSpot = cruiser.computerRandomIndex(maxIndex);
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 4)
			{
				compSpotTemp = cruiser.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
		else if (orientation == 'H')
		{
			maxIndex = 100;

			int f = 0;
			while (f < 1)
			{
				compSpot = cruiser.computerRandomIndex(maxIndex);
				if (cruiser.checkInvalidIndex(compSpot))
					if (board.checkForEmptySpot(compSpot))
						break;
					else
						continue;
				else
					continue;
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 4)
			{
				compSpotTemp = cruiser.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		for (int i = 1; i < 5; i++)
		{
			compSpot = cruiser.nextSpot(compSpot, orientation);
			if (compSpot == NULL)
				break;
			board.updateCompBoard(compSpot);
		}
		//board.displayCompBoard();
	}
	Sleep(3000);

	//First Destroyer start
	destroyer.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		orientation = destroyer.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = destroyer.computerRandomIndex(maxIndex);

			while (!board.checkForEmptySpot(compSpot))
			{
				compSpot = destroyer.computerRandomIndex(maxIndex);
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 3)
			{
				compSpotTemp = destroyer.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
		else if (orientation == 'H')
		{
			maxIndex = 100;

			int f = 0;
			while (f < 1)
			{
				compSpot = destroyer.computerRandomIndex(maxIndex);
				if (destroyer.checkInvalidIndex(compSpot))
					if (board.checkForEmptySpot(compSpot))
						break;
					else
						continue;
				else
					continue;
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 3)
			{
				compSpotTemp = destroyer.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		for (int i = 1; i < 5; i++)
		{
			compSpot = destroyer.nextSpot(compSpot, orientation);
			if (compSpot == NULL)
				break;
			board.updateCompBoard(compSpot);
		}
		//board.displayCompBoard();
	}
	Sleep(3000);

	//Second Destroyer start
	destroyer.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		orientation = destroyer.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = destroyer.computerRandomIndex(maxIndex);

			while (!board.checkForEmptySpot(compSpot))
			{
				compSpot = destroyer.computerRandomIndex(maxIndex);
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 3)
			{
				compSpotTemp = destroyer.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
		else if (orientation == 'H')
		{
			maxIndex = 100;

			int f = 0;
			while (f < 1)
			{
				compSpot = destroyer.computerRandomIndex(maxIndex);
				if (destroyer.checkInvalidIndex(compSpot))
					if (board.checkForEmptySpot(compSpot))
						break;
					else
						continue;
				else
					continue;
			}

			compSpotTemp = compSpot;
			counter = 1;

			while (counter != 3)
			{
				compSpotTemp = destroyer.nextSpot(compSpotTemp, orientation);
				if (compSpotTemp == NULL)
				{
					validPlacement = true;
					break;
				}
				if (board.checkForEmptySpot(compSpotTemp) == false)
				{
					validPlacement = false;
					break;
				}
			}
		}
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		for (int i = 1; i < 5; i++)
		{
			compSpot = destroyer.nextSpot(compSpot, orientation);
			if (compSpot == NULL)
				break;
			board.updateCompBoard(compSpot);
		}
		//board.displayCompBoard();
	}
	Sleep(3000);

	//Place first submarine
	submarine.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		maxIndex = 100;
		compSpot = submarine.computerRandomIndex(maxIndex);
		while (!board.checkForEmptySpot(compSpot))
		{
			compSpot = submarine.computerRandomIndex(100);
		}
		validPlacement = true;
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		//board.displayCompBoard();
	}
	Sleep(3000);

	//Place second submarine
	submarine.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		maxIndex = 100;
		compSpot = submarine.computerRandomIndex(maxIndex);
		while (!board.checkForEmptySpot(compSpot))
		{
			compSpot = submarine.computerRandomIndex(100);
		}
		validPlacement = true;
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
		//board.displayCompBoard();
	}
	board.displayCompBoard();

	std::cin.get();
	return 0;
}