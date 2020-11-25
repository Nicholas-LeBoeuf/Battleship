#pragma once
#include <iostream>

class Board
{
public:
	void displayPlayer1Board();
	void displayPlayer1HitsBoard();
	void displayPlayer2Board();
	void displayPlayer2HitsBoard();
	void displayCompBoard();
	void updateP1Board(int userSpot);
	void updateP2Board(int userSpot);
	void compUpdateP1Board(int move, char letter);
	void updateP1HitBoard(int index, char letter);
	void updateP2HitBoard(int index, char letter);
	void updateCompBoard(int computerSpot);
	void setP1Char();
	void setP1HitsChar();
	void setP2Char();
	void setP2HitsChar();
	void setCompChar();
	bool checkInput(std::string userInput);
	int findArrayIndex(std::string userInput);
	bool P1CheckForEmptySpot(int index);
	bool P2CheckForEmptySpot(int index);
	bool P1CheckForHitsEmptySpot(int index);
	bool P2CheckForHitsEmptySpot(int index);
	bool compCheckForEmptySpot(int index);
	bool checkForUserWin();
	bool checkForP1Win();
	bool checkForP2Win();
	bool checkForCompWin();
	void storeComputerIndex();
	void storePlayer1Index();
	void storePlayer2Index();
	void outputStoredIndex();
	bool compareHitWithBoard(int index, int turn);
	bool compareHitWithBoardP1vP2(int index, int turn);
	bool compCheckP1Spot(int index);

private:
	char P1Spot[100];
	char P1Hits[100];
	int storeP1Index[18];
	char P2Spot[100];
	char P2Hits[100];
	int storeP2Index[18];
	char compSpot[100];
	int storeCompIndex[18];
	//Array of all valid inputs
	std::string validInputs[100] = { "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10" };
};

