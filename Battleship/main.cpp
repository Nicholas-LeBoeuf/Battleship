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

Board board;
Ship ship;
AircraftCarrier aircraftCarrier;
Battleship battleship;
Cruiser cruiser;
Destroyer destroyer;
Submarine submarine;

std::string userInput;
int userSpot, userSpotTemp, counter, maxIndex, compSpot, compSpotTemp, move;
char orientation;
bool validPlacement = true;
int turn = 0;
bool winner = false;
int game;

void player1PlaceShips();
void player2PlaceShips();
void computerPlaceShips();

int main()
{
	std::cout << "\t**********************************" << std::endl;
	std::cout << "\t\t    BATTLESHIP" << std::endl;
	std::cout << "\t**********************************\n\n" << std::endl;

	std::cout << "Which game would you like to play? (Input '1' or '2')" << std::endl;
	std::cout << "1.) Player vs. Computer" << std::endl;
	std::cout << "2.) Player vs. Player" << std::endl;
	std::cin >> game;

	while (game != 1 && game != 2)
	{
		std::cout << "Invalid input, please type either '1' or '2'" << std::endl;
		std::cin >> game;
	}

	if (game == 1) //Player vs. Computer
	{
		board.setP1Char();
		board.setP1HitsChar();
		board.displayPlayer1Board();
		board.displayPlayer1HitsBoard();

		player1PlaceShips(); 

		board.setCompChar();

		std::cout << "Computer will now place their ships..." << std::endl;

		computerPlaceShips();

		std::cout << "\n\n\n\nPlayer goes first!" << std::endl;
		turn = 0;
		do {
			if (turn == 0) //Players turn
			{
				board.displayPlayer1Board();
				board.displayPlayer1HitsBoard();
				std::cout << "Please input where you would like to make your move. (Example input: 'A1')." << std::endl;
				std::cin >> userInput;

				while (!board.checkInput(userInput))
				{
					std::cout << "Invalid input! Please type in letter and then number. (Example input: 'A1')." << std::endl;
					std::cin >> userInput;
				}

				move = board.findArrayIndex(userInput);

				while (!board.P1CheckForHitsEmptySpot(move))
				{
					std::cout << "You already made a move here! Please make another move." << std::endl;
					std::cin >> userInput;
					while (!board.checkInput(userInput))
					{
						std::cout << "Invalid input! Please type in letter and then number. (Example input: 'A1')." << std::endl;
						std::cin >> userInput;
					}
					move = board.findArrayIndex(userInput);
				}

				if (board.compareHitWithBoard(move, turn) == true)
				{
					char letter = 'X';
					board.updateP1HitBoard(move, letter);
					board.displayPlayer1Board();
					board.displayPlayer1HitsBoard();
					std::cout << "Hit!" << std::endl;
				}
				else if (board.compareHitWithBoard(move, turn) == false)
				{
					char letter = 'O';
					board.updateP1HitBoard(move, letter);
					board.displayPlayer1Board();
					board.displayPlayer1HitsBoard();
					std::cout << "Miss!" << std::endl;
				}

				if (board.checkForUserWin())
				{
					winner = true;
					break;
				}
				else
				{
					turn = 1;
				}
			}

			else if (turn == 1) //Computers turn
			{
				Sleep(1000);
				std::cout << "Computer is taking their turn..." << std::endl;
				Sleep(1000);
				std::cout << "..." << std::endl;
				Sleep(1000);
				std::cout << "..." << std::endl;
				Sleep(1000);
				std::cout << "..." << std::endl;
				Sleep(1000);

				maxIndex = 100;

				move = ship.computerRandomIndex(maxIndex);
				while (!board.compCheckP1Spot(move))
				{
					move = ship.computerRandomIndex(maxIndex);
				}

				if (board.P1CheckForEmptySpot(move) == true)
				{
					char letter = 'O';
					board.compUpdateP1Board(move, letter);
					board.displayPlayer1Board();
					std::cout << "The computer missed!" << std::endl;
				}
				else
				{
					char letter = 'H';
					board.compUpdateP1Board(move, letter);
					board.displayPlayer1Board();
					std::cout << "The computer has hit one of your ships!" << std::endl;
				}
				if (board.checkForCompWin())
				{
					winner = true;
					break;
				}
				else
				{
					turn = 0;
				}
			}


		} while (winner == false);

		if (winner == true)
		{
			std::cout << "\t**********************************" << std::endl;
			if (turn == 0)
				std::cout << "\t\t    PLAYER WINS!" << std::endl;
			else if (turn == 1)
				std::cout << "\t\t    COMPUTER WINS!" << std::endl;
			std::cout << "\t**********************************\n\n" << std::endl;
		}
	}

	else if (game == 2) //Player vs. Player
	{
		board.setP1Char();
		board.setP1HitsChar();
		board.setP2Char();
		board.setP2HitsChar();
		
		
		board.displayPlayer1Board();
		board.displayPlayer1HitsBoard();
		player1PlaceShips();

		board.displayPlayer2Board();
		board.displayPlayer2HitsBoard();
		player2PlaceShips();
		
		std::cout << "\n\n\n\nPlayer 1 goes first!" << std::endl;
		turn = 0;
		do {
			if (turn == 0) //Player 1 turn
			{
				board.displayPlayer1Board();
				board.displayPlayer1HitsBoard();
				std::cout << "[PLAYER 1]Please input where you would like to make your move. (Example input: 'A1')." << std::endl;
				std::cin >> userInput;

				while (!board.checkInput(userInput))
				{
					std::cout << "Invalid input! Please type in letter and then number. (Example input: 'A1')." << std::endl;
					std::cin >> userInput;
				}

				move = board.findArrayIndex(userInput);

				while (!board.P1CheckForHitsEmptySpot(move))
				{
					std::cout << "You already made a move here! Please make another move." << std::endl;
					std::cin >> userInput;
					while (!board.checkInput(userInput))
					{
						std::cout << "Invalid input! Please type in letter and then number. (Example input: 'A1')." << std::endl;
						std::cin >> userInput;
					}
					move = board.findArrayIndex(userInput);
				}
				if (board.compareHitWithBoardP1vP2(move, turn) == true)
				{
					char letter = 'X';
					board.updateP1HitBoard(move, letter);
					board.displayPlayer1Board();
					board.displayPlayer1HitsBoard();
					std::cout << "Hit!" << std::endl;
				}
				else if (board.compareHitWithBoardP1vP2(move, turn) == false)
				{
					char letter = 'O';
					board.updateP1HitBoard(move, letter);
					board.displayPlayer1Board();
					board.displayPlayer1HitsBoard();
					std::cout << "Miss!" << std::endl;
				}

				if (board.checkForP1Win())
				{
					winner = true;
					break;
				}
				else
				{
					std::cout << "Changing turns in..." << std::endl;
					for (int i = 5; i > 0; i--)
					{
						std::cout << i << std::endl;
						Sleep(1000);
					}
					turn = 1;
				}
			}


			if (turn == 1) //Player 2 turn
			{
				board.displayPlayer2Board();
				board.displayPlayer2HitsBoard();
				std::cout << "[PLAYER 2]Please input where you would like to make your move. (Example input: 'A1')." << std::endl;
				std::cin >> userInput;

				while (!board.checkInput(userInput))
				{
					std::cout << "Invalid input! Please type in letter and then number. (Example input: 'A1')." << std::endl;
					std::cin >> userInput;
				}

				move = board.findArrayIndex(userInput);

				while (!board.P2CheckForHitsEmptySpot(move))
				{
					std::cout << "You already made a move here! Please make another move." << std::endl;
					std::cin >> userInput;
					while (!board.checkInput(userInput))
					{
						std::cout << "Invalid input! Please type in letter and then number. (Example input: 'A1')." << std::endl;
						std::cin >> userInput;
					}
					move = board.findArrayIndex(userInput);
				}
				if (board.compareHitWithBoardP1vP2(move, turn) == true)
				{
					char letter = 'X';
					board.updateP2HitBoard(move, letter);
					board.displayPlayer2Board();
					board.displayPlayer2HitsBoard();
					std::cout << "Hit!" << std::endl;
				}
				else if (board.compareHitWithBoardP1vP2(move, turn) == false)
				{
					char letter = 'O';
					board.updateP2HitBoard(move, letter);
					board.displayPlayer2Board();
					board.displayPlayer2HitsBoard();
					std::cout << "Miss!" << std::endl;
				}

				if (board.checkForP2Win())
				{
					winner = true;
					break;
				}
				else
				{
					std::cout << "Changing turns in..." << std::endl;
					for (int i = 5; i > 0; i--)
					{
						std::cout << i << std::endl;
						Sleep(1000);
					}
					turn = 0;
				}
			}

		} while (winner == false);

		if (winner == true)
		{
			std::cout << "\t**********************************" << std::endl;
			if (turn == 0)
				std::cout << "\t\t    PLAYER 1 WINS!" << std::endl;
			else if (turn == 1)
				std::cout << "\t\t    PLAYER 2 WINS!" << std::endl;
			std::cout << "\t**********************************\n\n" << std::endl;
		}
	}

	std::cin.get();
	return 0;
}

void player1PlaceShips()
{
	//Place aircraft carrier start
	std::cout << "PLAYER 1" << std::endl;
	std::cout << "Specify where you want to place the edge of your Aircraft Carrier (5 spaces). (Example 'A1')" << std::endl;
	std::cin >> userInput;
	while (!board.checkInput(userInput))
	{
		std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
		std::cin >> userInput;
	}

	userSpot = board.findArrayIndex(userInput);

	while (!board.P1CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!aircraftCarrier.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 59)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 6)
	{
		userSpotTemp = aircraftCarrier.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P1CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP1Board(userSpot);
		for (int i = 1; i < 5; i++)
		{
			userSpot = aircraftCarrier.nextSpot(userSpot, orientation);
			board.updateP1Board(userSpot);
		}

		board.displayPlayer1Board();
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

	while (!board.P1CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!battleship.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 69)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 5)
	{
		userSpotTemp = battleship.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P1CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP1Board(userSpot);
		for (int i = 1; i < 4; i++)
		{
			userSpot = battleship.nextSpot(userSpot, orientation);
			board.updateP1Board(userSpot);
		}

		board.displayPlayer1Board();
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

	while (!board.P1CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!cruiser.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 79)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 4)
	{
		userSpotTemp = cruiser.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P1CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP1Board(userSpot);
		for (int i = 1; i < 3; i++)
		{
			userSpot = cruiser.nextSpot(userSpot, orientation);
			board.updateP1Board(userSpot);
		}

		board.displayPlayer1Board();
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

	while (!board.P1CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!destroyer.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 89)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 3)
	{
		userSpotTemp = destroyer.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P1CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP1Board(userSpot);
		for (int i = 1; i < 2; i++)
		{
			userSpot = destroyer.nextSpot(userSpot, orientation);
			board.updateP1Board(userSpot);
		}

		board.displayPlayer1Board();
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

	while (!board.P1CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!destroyer.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 89)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P1CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 3)
	{
		userSpotTemp = destroyer.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P1CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP1Board(userSpot);
		for (int i = 1; i < 2; i++)
		{
			userSpot = destroyer.nextSpot(userSpot, orientation);
			board.updateP1Board(userSpot);
		}

		board.displayPlayer1Board();
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

	while (!board.P1CheckForEmptySpot(userSpot))
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
		board.updateP1Board(userSpot);
		board.displayPlayer1Board();
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

	while (!board.P1CheckForEmptySpot(userSpot))
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
		board.updateP1Board(userSpot);
		board.displayPlayer1Board();
	}
	//End of placing second submarine
	board.storePlayer1Index();
}








void player2PlaceShips()
{
	//Place aircraft carrier start
	std::cout << "PLAYER 2" << std::endl;
	std::cout << "Specify where you want to place the edge of your Aircraft Carrier (5 spaces). (Example 'A1')" << std::endl;
	std::cin >> userInput;
	while (!board.checkInput(userInput))
	{
		std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
		std::cin >> userInput;
	}

	userSpot = board.findArrayIndex(userInput);

	while (!board.P2CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!aircraftCarrier.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 59)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 6)
	{
		userSpotTemp = aircraftCarrier.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P2CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP2Board(userSpot);
		for (int i = 1; i < 5; i++)
		{
			userSpot = aircraftCarrier.nextSpot(userSpot, orientation);
			board.updateP2Board(userSpot);
		}

		board.displayPlayer2Board();
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

	while (!board.P2CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!battleship.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 69)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 5)
	{
		userSpotTemp = battleship.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P2CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP2Board(userSpot);
		for (int i = 1; i < 4; i++)
		{
			userSpot = battleship.nextSpot(userSpot, orientation);
			board.updateP2Board(userSpot);
		}

		board.displayPlayer2Board();
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

	while (!board.P2CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!cruiser.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 79)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 4)
	{
		userSpotTemp = cruiser.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P2CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP2Board(userSpot);
		for (int i = 1; i < 3; i++)
		{
			userSpot = cruiser.nextSpot(userSpot, orientation);
			board.updateP2Board(userSpot);
		}

		board.displayPlayer2Board();
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

	while (!board.P2CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!destroyer.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 89)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 3)
	{
		userSpotTemp = destroyer.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P2CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP2Board(userSpot);
		for (int i = 1; i < 2; i++)
		{
			userSpot = destroyer.nextSpot(userSpot, orientation);
			board.updateP2Board(userSpot);
		}

		board.displayPlayer2Board();
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

	while (!board.P2CheckForEmptySpot(userSpot))
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

	if (orientation == 'H') {
		while (!destroyer.checkInvalidIndex(userSpot))
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	else if (orientation == 'V')
	{
		while (userSpot > 89)
		{
			std::cout << "Invalid input. Ship will run off the board. Try again." << std::endl;
			std::cin >> userInput;
			while (!board.checkInput(userInput))
			{
				std::cout << "Invalid input. Please use the format of letter and then number. (Example 'A1')" << std::endl;
				std::cin >> userInput;
			}
			userSpot = board.findArrayIndex(userInput);
			while (!board.P2CheckForEmptySpot(userSpot))
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
		}
	}

	userSpotTemp = userSpot;
	counter = 1;
	while (counter != 3)
	{
		userSpotTemp = destroyer.nextSpot(userSpotTemp, orientation);
		if (userSpotTemp == NULL)
			break;
		if (board.P2CheckForEmptySpot(userSpotTemp) == false)
		{
			std::cout << "Cannot place ship here because it will overlap another ship." << std::endl;
			validPlacement = false;
			break;
		}
		counter++;
	}

	if (validPlacement == true)
	{
		board.updateP2Board(userSpot);
		for (int i = 1; i < 2; i++)
		{
			userSpot = destroyer.nextSpot(userSpot, orientation);
			board.updateP2Board(userSpot);
		}

		board.displayPlayer2Board();
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

	while (!board.P2CheckForEmptySpot(userSpot))
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
		board.updateP2Board(userSpot);
		board.displayPlayer2Board();
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

	while (!board.P2CheckForEmptySpot(userSpot))
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
		board.updateP2Board(userSpot);
		board.displayPlayer2Board();
	}
	//End of placing second submarine
	board.storePlayer2Index();
}











void computerPlaceShips()
{
	Sleep(5000);
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

			while (!board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
					if (board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
	}

	std::cout << "Computer has placed their aircraft carrier..." << std::endl;
	Sleep(5000);

	battleship.resetCounter();
	//Battleship
	validPlacement = false;
	while (validPlacement == false) {
		orientation = battleship.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = battleship.computerRandomIndex(maxIndex);

			while (!board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
					if (board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
	}

	std::cout << "Computer has placed their battleship..." << std::endl;
	Sleep(5000);

	//Cruiser Start
	cruiser.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		orientation = cruiser.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = cruiser.computerRandomIndex(maxIndex);

			while (!board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
					if (board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
	}
	std::cout << "Computer has placed their cruiser..." << std::endl;
	Sleep(5000);

	//First Destroyer start
	destroyer.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		orientation = destroyer.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = destroyer.computerRandomIndex(maxIndex);

			while (!board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
					if (board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
	}

	std::cout << "Computer has placed their first destroyer..." << std::endl;
	Sleep(5000);

	//Second Destroyer start
	destroyer.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		orientation = destroyer.computerRandomOrientation();
		if (orientation == 'V')
		{
			maxIndex = 70;
			compSpot = destroyer.computerRandomIndex(maxIndex);

			while (!board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
					if (board.compCheckForEmptySpot(compSpot))
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
				if (board.compCheckForEmptySpot(compSpotTemp) == false)
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
	}

	std::cout << "Computer has placed their second destroyer..." << std::endl;
	Sleep(5000);

	//Place first submarine
	submarine.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		maxIndex = 100;
		compSpot = submarine.computerRandomIndex(maxIndex);
		while (!board.compCheckForEmptySpot(compSpot))
		{
			compSpot = submarine.computerRandomIndex(100);
		}
		validPlacement = true;
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
	}

	std::cout << "Computer has placed their first submarine..." << std::endl;
	Sleep(5000);

	//Place second submarine
	submarine.resetCounter();
	validPlacement = false;
	while (validPlacement == false) {
		maxIndex = 100;
		compSpot = submarine.computerRandomIndex(maxIndex);
		while (!board.compCheckForEmptySpot(compSpot))
		{
			compSpot = submarine.computerRandomIndex(100);
		}
		validPlacement = true;
	}

	if (validPlacement == true)
	{
		board.updateCompBoard(compSpot);
	}
	std::cout << "Computer has placed their second submarine and is ready!" << std::endl;
	board.storeComputerIndex();
	Sleep(2000);
}