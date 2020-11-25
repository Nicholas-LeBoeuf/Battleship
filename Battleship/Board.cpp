#include <iostream>
#include <Windows.h>
#include "Board.h"

void Board::displayPlayer1Board()
{
	std::cout << "Your board:" << std::endl;
	std::cout << "\t\t1 2 3 4 5 6 7 8 9 10" << std::endl;
	std::cout << "\t      A|" << P1Spot[0] << "|" << P1Spot[1] << "|" << P1Spot[2] << "|" << P1Spot[3] << "|" << P1Spot[4] << "|" << P1Spot[5] << "|" << P1Spot[6] << "|" << P1Spot[7] << "|" << P1Spot[8] << "|" << P1Spot[9] << "|" << std::endl;
	std::cout << "\t      B|" << P1Spot[10] << "|" << P1Spot[11] << "|" << P1Spot[12] << "|" << P1Spot[13] << "|" << P1Spot[14] << "|" << P1Spot[15] << "|" << P1Spot[16] << "|" << P1Spot[17] << "|" << P1Spot[18] << "|" << P1Spot[19] << "|" << std::endl;
	std::cout << "\t      C|" << P1Spot[20] << "|" << P1Spot[21] << "|" << P1Spot[22] << "|" << P1Spot[23] << "|" << P1Spot[24] << "|" << P1Spot[25] << "|" << P1Spot[26] << "|" << P1Spot[27] << "|" << P1Spot[28] << "|" << P1Spot[29] << "|" << std::endl;
	std::cout << "\t      D|" << P1Spot[30] << "|" << P1Spot[31] << "|" << P1Spot[32] << "|" << P1Spot[33] << "|" << P1Spot[34] << "|" << P1Spot[35] << "|" << P1Spot[36] << "|" << P1Spot[37] << "|" << P1Spot[38] << "|" << P1Spot[39] << "|" << std::endl;
	std::cout << "\t      E|" << P1Spot[40] << "|" << P1Spot[41] << "|" << P1Spot[42] << "|" << P1Spot[43] << "|" << P1Spot[44] << "|" << P1Spot[45] << "|" << P1Spot[46] << "|" << P1Spot[47] << "|" << P1Spot[48] << "|" << P1Spot[49] << "|" << std::endl;
	std::cout << "\t      F|" << P1Spot[50] << "|" << P1Spot[51] << "|" << P1Spot[52] << "|" << P1Spot[53] << "|" << P1Spot[54] << "|" << P1Spot[55] << "|" << P1Spot[56] << "|" << P1Spot[57] << "|" << P1Spot[58] << "|" << P1Spot[59] << "|" << std::endl;
	std::cout << "\t      G|" << P1Spot[60] << "|" << P1Spot[61] << "|" << P1Spot[62] << "|" << P1Spot[63] << "|" << P1Spot[64] << "|" << P1Spot[65] << "|" << P1Spot[66] << "|" << P1Spot[67] << "|" << P1Spot[68] << "|" << P1Spot[69] << "|" << std::endl;
	std::cout << "\t      H|" << P1Spot[70] << "|" << P1Spot[71] << "|" << P1Spot[72] << "|" << P1Spot[73] << "|" << P1Spot[74] << "|" << P1Spot[75] << "|" << P1Spot[76] << "|" << P1Spot[77] << "|" << P1Spot[78] << "|" << P1Spot[79] << "|" << std::endl;
	std::cout << "\t      I|" << P1Spot[80] << "|" << P1Spot[81] << "|" << P1Spot[82] << "|" << P1Spot[83] << "|" << P1Spot[84] << "|" << P1Spot[85] << "|" << P1Spot[86] << "|" << P1Spot[87] << "|" << P1Spot[88] << "|" << P1Spot[89] << "|" << std::endl;
	std::cout << "\t      J|" << P1Spot[90] << "|" << P1Spot[91] << "|" << P1Spot[92] << "|" << P1Spot[93] << "|" << P1Spot[94] << "|" << P1Spot[95] << "|" << P1Spot[96] << "|" << P1Spot[97] << "|" << P1Spot[98] << "|" << P1Spot[99] << "|\n" << std::endl;
}

void Board::displayPlayer1HitsBoard()
{
	std::cout << "Hits board:" << std::endl;
	std::cout << "\t\t1 2 3 4 5 6 7 8 9 10" << std::endl;
	std::cout << "\t      A|" << P1Hits[0] << "|" << P1Hits[1] << "|" << P1Hits[2] << "|" << P1Hits[3] << "|" << P1Hits[4] << "|" << P1Hits[5] << "|" << P1Hits[6] << "|" << P1Hits[7] << "|" << P1Hits[8] << "|" << P1Hits[9] << "|" << std::endl;
	std::cout << "\t      B|" << P1Hits[10] << "|" << P1Hits[11] << "|" << P1Hits[12] << "|" << P1Hits[13] << "|" << P1Hits[14] << "|" << P1Hits[15] << "|" << P1Hits[16] << "|" << P1Hits[17] << "|" << P1Hits[18] << "|" << P1Hits[19] << "|" << std::endl;
	std::cout << "\t      C|" << P1Hits[20] << "|" << P1Hits[21] << "|" << P1Hits[22] << "|" << P1Hits[23] << "|" << P1Hits[24] << "|" << P1Hits[25] << "|" << P1Hits[26] << "|" << P1Hits[27] << "|" << P1Hits[28] << "|" << P1Hits[29] << "|" << std::endl;
	std::cout << "\t      D|" << P1Hits[30] << "|" << P1Hits[31] << "|" << P1Hits[32] << "|" << P1Hits[33] << "|" << P1Hits[34] << "|" << P1Hits[35] << "|" << P1Hits[36] << "|" << P1Hits[37] << "|" << P1Hits[38] << "|" << P1Hits[39] << "|" << std::endl;
	std::cout << "\t      E|" << P1Hits[40] << "|" << P1Hits[41] << "|" << P1Hits[42] << "|" << P1Hits[43] << "|" << P1Hits[44] << "|" << P1Hits[45] << "|" << P1Hits[46] << "|" << P1Hits[47] << "|" << P1Hits[48] << "|" << P1Hits[49] << "|" << std::endl;
	std::cout << "\t      F|" << P1Hits[50] << "|" << P1Hits[51] << "|" << P1Hits[52] << "|" << P1Hits[53] << "|" << P1Hits[54] << "|" << P1Hits[55] << "|" << P1Hits[56] << "|" << P1Hits[57] << "|" << P1Hits[58] << "|" << P1Hits[59] << "|" << std::endl;
	std::cout << "\t      G|" << P1Hits[60] << "|" << P1Hits[61] << "|" << P1Hits[62] << "|" << P1Hits[63] << "|" << P1Hits[64] << "|" << P1Hits[65] << "|" << P1Hits[66] << "|" << P1Hits[67] << "|" << P1Hits[68] << "|" << P1Hits[69] << "|" << std::endl;
	std::cout << "\t      H|" << P1Hits[70] << "|" << P1Hits[71] << "|" << P1Hits[72] << "|" << P1Hits[73] << "|" << P1Hits[74] << "|" << P1Hits[75] << "|" << P1Hits[76] << "|" << P1Hits[77] << "|" << P1Hits[78] << "|" << P1Hits[79] << "|" << std::endl;
	std::cout << "\t      I|" << P1Hits[80] << "|" << P1Hits[81] << "|" << P1Hits[82] << "|" << P1Hits[83] << "|" << P1Hits[84] << "|" << P1Hits[85] << "|" << P1Hits[86] << "|" << P1Hits[87] << "|" << P1Hits[88] << "|" << P1Hits[89] << "|" << std::endl;
	std::cout << "\t      J|" << P1Hits[90] << "|" << P1Hits[91] << "|" << P1Hits[92] << "|" << P1Hits[93] << "|" << P1Hits[94] << "|" << P1Hits[95] << "|" << P1Hits[96] << "|" << P1Hits[97] << "|" << P1Hits[98] << "|" << P1Hits[99] << "|\n" << std::endl;
}

void Board::displayPlayer2Board()
{
	std::cout << "Your board:" << std::endl;
	std::cout << "\t\t1 2 3 4 5 6 7 8 9 10" << std::endl;
	std::cout << "\t      A|" << P2Spot[0] << "|" << P2Spot[1] << "|" << P2Spot[2] << "|" << P2Spot[3] << "|" << P2Spot[4] << "|" << P2Spot[5] << "|" << P2Spot[6] << "|" << P2Spot[7] << "|" << P2Spot[8] << "|" << P2Spot[9] << "|" << std::endl;
	std::cout << "\t      B|" << P2Spot[10] << "|" << P2Spot[11] << "|" << P2Spot[12] << "|" << P2Spot[13] << "|" << P2Spot[14] << "|" << P2Spot[15] << "|" << P2Spot[16] << "|" << P2Spot[17] << "|" << P2Spot[18] << "|" << P2Spot[19] << "|" << std::endl;
	std::cout << "\t      C|" << P2Spot[20] << "|" << P2Spot[21] << "|" << P2Spot[22] << "|" << P2Spot[23] << "|" << P2Spot[24] << "|" << P2Spot[25] << "|" << P2Spot[26] << "|" << P2Spot[27] << "|" << P2Spot[28] << "|" << P2Spot[29] << "|" << std::endl;
	std::cout << "\t      D|" << P2Spot[30] << "|" << P2Spot[31] << "|" << P2Spot[32] << "|" << P2Spot[33] << "|" << P2Spot[34] << "|" << P2Spot[35] << "|" << P2Spot[36] << "|" << P2Spot[37] << "|" << P2Spot[38] << "|" << P2Spot[39] << "|" << std::endl;
	std::cout << "\t      E|" << P2Spot[40] << "|" << P2Spot[41] << "|" << P2Spot[42] << "|" << P2Spot[43] << "|" << P2Spot[44] << "|" << P2Spot[45] << "|" << P2Spot[46] << "|" << P2Spot[47] << "|" << P2Spot[48] << "|" << P2Spot[49] << "|" << std::endl;
	std::cout << "\t      F|" << P2Spot[50] << "|" << P2Spot[51] << "|" << P2Spot[52] << "|" << P2Spot[53] << "|" << P2Spot[54] << "|" << P2Spot[55] << "|" << P2Spot[56] << "|" << P2Spot[57] << "|" << P2Spot[58] << "|" << P2Spot[59] << "|" << std::endl;
	std::cout << "\t      G|" << P2Spot[60] << "|" << P2Spot[61] << "|" << P2Spot[62] << "|" << P2Spot[63] << "|" << P2Spot[64] << "|" << P2Spot[65] << "|" << P2Spot[66] << "|" << P2Spot[67] << "|" << P2Spot[68] << "|" << P2Spot[69] << "|" << std::endl;
	std::cout << "\t      H|" << P2Spot[70] << "|" << P2Spot[71] << "|" << P2Spot[72] << "|" << P2Spot[73] << "|" << P2Spot[74] << "|" << P2Spot[75] << "|" << P2Spot[76] << "|" << P2Spot[77] << "|" << P2Spot[78] << "|" << P2Spot[79] << "|" << std::endl;
	std::cout << "\t      I|" << P2Spot[80] << "|" << P2Spot[81] << "|" << P2Spot[82] << "|" << P2Spot[83] << "|" << P2Spot[84] << "|" << P2Spot[85] << "|" << P2Spot[86] << "|" << P2Spot[87] << "|" << P2Spot[88] << "|" << P2Spot[89] << "|" << std::endl;
	std::cout << "\t      J|" << P2Spot[90] << "|" << P2Spot[91] << "|" << P2Spot[92] << "|" << P2Spot[93] << "|" << P2Spot[94] << "|" << P2Spot[95] << "|" << P2Spot[96] << "|" << P2Spot[97] << "|" << P2Spot[98] << "|" << P2Spot[99] << "|\n" << std::endl;
}

void Board::displayPlayer2HitsBoard()
{
	std::cout << "Hits board:" << std::endl;
	std::cout << "\t\t1 2 3 4 5 6 7 8 9 10" << std::endl;
	std::cout << "\t      A|" << P2Hits[0] << "|" << P2Hits[1] << "|" << P2Hits[2] << "|" << P2Hits[3] << "|" << P2Hits[4] << "|" << P2Hits[5] << "|" << P2Hits[6] << "|" << P2Hits[7] << "|" << P2Hits[8] << "|" << P2Hits[9] << "|" << std::endl;
	std::cout << "\t      B|" << P2Hits[10] << "|" << P2Hits[11] << "|" << P2Hits[12] << "|" << P2Hits[13] << "|" << P2Hits[14] << "|" << P2Hits[15] << "|" << P2Hits[16] << "|" << P2Hits[17] << "|" << P2Hits[18] << "|" << P2Hits[19] << "|" << std::endl;
	std::cout << "\t      C|" << P2Hits[20] << "|" << P2Hits[21] << "|" << P2Hits[22] << "|" << P2Hits[23] << "|" << P2Hits[24] << "|" << P2Hits[25] << "|" << P2Hits[26] << "|" << P2Hits[27] << "|" << P2Hits[28] << "|" << P2Hits[29] << "|" << std::endl;
	std::cout << "\t      D|" << P2Hits[30] << "|" << P2Hits[31] << "|" << P2Hits[32] << "|" << P2Hits[33] << "|" << P2Hits[34] << "|" << P2Hits[35] << "|" << P2Hits[36] << "|" << P2Hits[37] << "|" << P2Hits[38] << "|" << P2Hits[39] << "|" << std::endl;
	std::cout << "\t      E|" << P2Hits[40] << "|" << P2Hits[41] << "|" << P2Hits[42] << "|" << P2Hits[43] << "|" << P2Hits[44] << "|" << P2Hits[45] << "|" << P2Hits[46] << "|" << P2Hits[47] << "|" << P2Hits[48] << "|" << P2Hits[49] << "|" << std::endl;
	std::cout << "\t      F|" << P2Hits[50] << "|" << P2Hits[51] << "|" << P2Hits[52] << "|" << P2Hits[53] << "|" << P2Hits[54] << "|" << P2Hits[55] << "|" << P2Hits[56] << "|" << P2Hits[57] << "|" << P2Hits[58] << "|" << P2Hits[59] << "|" << std::endl;
	std::cout << "\t      G|" << P2Hits[60] << "|" << P2Hits[61] << "|" << P2Hits[62] << "|" << P2Hits[63] << "|" << P2Hits[64] << "|" << P2Hits[65] << "|" << P2Hits[66] << "|" << P2Hits[67] << "|" << P2Hits[68] << "|" << P2Hits[69] << "|" << std::endl;
	std::cout << "\t      H|" << P2Hits[70] << "|" << P2Hits[71] << "|" << P2Hits[72] << "|" << P2Hits[73] << "|" << P2Hits[74] << "|" << P2Hits[75] << "|" << P2Hits[76] << "|" << P2Hits[77] << "|" << P2Hits[78] << "|" << P2Hits[79] << "|" << std::endl;
	std::cout << "\t      I|" << P2Hits[80] << "|" << P2Hits[81] << "|" << P2Hits[82] << "|" << P2Hits[83] << "|" << P2Hits[84] << "|" << P2Hits[85] << "|" << P2Hits[86] << "|" << P2Hits[87] << "|" << P2Hits[88] << "|" << P2Hits[89] << "|" << std::endl;
	std::cout << "\t      J|" << P2Hits[90] << "|" << P2Hits[91] << "|" << P2Hits[92] << "|" << P2Hits[93] << "|" << P2Hits[94] << "|" << P2Hits[95] << "|" << P2Hits[96] << "|" << P2Hits[97] << "|" << P2Hits[98] << "|" << P2Hits[99] << "|\n" << std::endl;
}



void Board::displayCompBoard()
{
	std::cout << "\t\t1 2 3 4 5 6 7 8 9 10" << std::endl;
	std::cout << "\t      A|" << compSpot[0] << "|" << compSpot[1] << "|" << compSpot[2] << "|" << compSpot[3] << "|" << compSpot[4] << "|" << compSpot[5] << "|" << compSpot[6] << "|" << compSpot[7] << "|" << compSpot[8] << "|" << compSpot[9] << "|" << std::endl;
	std::cout << "\t      B|" << compSpot[10] << "|" << compSpot[11] << "|" << compSpot[12] << "|" << compSpot[13] << "|" << compSpot[14] << "|" << compSpot[15] << "|" << compSpot[16] << "|" << compSpot[17] << "|" << compSpot[18] << "|" << compSpot[19] << "|" << std::endl;
	std::cout << "\t      C|" << compSpot[20] << "|" << compSpot[21] << "|" << compSpot[22] << "|" << compSpot[23] << "|" << compSpot[24] << "|" << compSpot[25] << "|" << compSpot[26] << "|" << compSpot[27] << "|" << compSpot[28] << "|" << compSpot[29] << "|" << std::endl;
	std::cout << "\t      D|" << compSpot[30] << "|" << compSpot[31] << "|" << compSpot[32] << "|" << compSpot[33] << "|" << compSpot[34] << "|" << compSpot[35] << "|" << compSpot[36] << "|" << compSpot[37] << "|" << compSpot[38] << "|" << compSpot[39] << "|" << std::endl;
	std::cout << "\t      E|" << compSpot[40] << "|" << compSpot[41] << "|" << compSpot[42] << "|" << compSpot[43] << "|" << compSpot[44] << "|" << compSpot[45] << "|" << compSpot[46] << "|" << compSpot[47] << "|" << compSpot[48] << "|" << compSpot[49] << "|" << std::endl;
	std::cout << "\t      F|" << compSpot[50] << "|" << compSpot[51] << "|" << compSpot[52] << "|" << compSpot[53] << "|" << compSpot[54] << "|" << compSpot[55] << "|" << compSpot[56] << "|" << compSpot[57] << "|" << compSpot[58] << "|" << compSpot[59] << "|" << std::endl;
	std::cout << "\t      G|" << compSpot[60] << "|" << compSpot[61] << "|" << compSpot[62] << "|" << compSpot[63] << "|" << compSpot[64] << "|" << compSpot[65] << "|" << compSpot[66] << "|" << compSpot[67] << "|" << compSpot[68] << "|" << compSpot[69] << "|" << std::endl;
	std::cout << "\t      H|" << compSpot[70] << "|" << compSpot[71] << "|" << compSpot[72] << "|" << compSpot[73] << "|" << compSpot[74] << "|" << compSpot[75] << "|" << compSpot[76] << "|" << compSpot[77] << "|" << compSpot[78] << "|" << compSpot[79] << "|" << std::endl;
	std::cout << "\t      I|" << compSpot[80] << "|" << compSpot[81] << "|" << compSpot[82] << "|" << compSpot[83] << "|" << compSpot[84] << "|" << compSpot[85] << "|" << compSpot[86] << "|" << compSpot[87] << "|" << compSpot[88] << "|" << compSpot[89] << "|" << std::endl;
	std::cout << "\t      J|" << compSpot[90] << "|" << compSpot[91] << "|" << compSpot[92] << "|" << compSpot[93] << "|" << compSpot[94] << "|" << compSpot[95] << "|" << compSpot[96] << "|" << compSpot[97] << "|" << compSpot[98] << "|" << compSpot[99] << "|" << std::endl;
}

void Board::updateP1Board(int userSpot)
{
	P1Spot[userSpot] = (char)254; //(char)254 just displays the box
}

void Board::updateP2Board(int userSpot)
{
	P2Spot[userSpot] = (char)254;
}

void Board::compUpdateP1Board(int move, char letter)
{
	P1Spot[move] = letter; //Whatever letter is passed through the function (X or O), will be set at that spot
}

void Board::updateP1HitBoard(int index, char letter)
{
	P1Hits[index] = letter;
}

void Board::updateP2HitBoard(int index, char letter)
{
	P2Hits[index] = letter;
}

void Board::updateCompBoard(int computerSpot)
{
	compSpot[computerSpot] = (char)254;
}

void Board::setP1Char() //Sets all the boards to null
{
	for (int i = 0; i < 100; i++)
	{
		P1Spot[i] = NULL;
	}
}

void Board::setP1HitsChar()
{
	for (int i = 0; i < 100; i++)
	{
		P1Hits[i] = NULL;
	}
}

void Board::setP2Char()
{
	for (int i = 0; i < 100; i++)
	{
		P2Spot[i] = NULL;
	}
}

void Board::setP2HitsChar()
{
	for (int i = 0; i < 100; i++)
	{
		P2Hits[i] = NULL;
	}
}

void Board::setCompChar()
{
	for (int i = 0; i < 100; i++)
	{
		compSpot[i] = NULL;
	}
}

bool Board::checkInput(std::string userInput) //Goes through the array of valid inputs and compares it to the users input
{
	for (int i = 0; i < 100; i++)
	{
		if (userInput == validInputs[i])
			return true; //found matching input
		else if (i == 99 && userInput != validInputs[i])
			return false; //If it couldn't find a matching input, it will return false
	}
}

int Board::findArrayIndex(std::string userInput) //Converts the users input (example 'A1') to the correct index in the array
{
	int n = sizeof(validInputs);
	int i = 0;

	while (i < n)
	{
		if (validInputs[i] == userInput)
			break;
		i++;
	}

	return i;
}

bool Board::P1CheckForEmptySpot(int index) //Check for null spot to place ship
{
	if (P1Spot[index] == NULL)
		return true;
	else
		return false;
}

bool Board::P2CheckForEmptySpot(int index)
{
	if (P2Spot[index] == NULL)
		return true;
	else
		return false;
}

bool Board::P1CheckForHitsEmptySpot(int index) //Check for null spot to make hit
{
	if (P1Hits[index] == NULL)
		return true;
	else
		return false;
}

bool Board::P2CheckForHitsEmptySpot(int index)
{
	if (P2Hits[index] == NULL)
		return true;
	else
		return false;
}

bool Board::compCheckForEmptySpot(int index)
{
	if (compSpot[index] == NULL)
		return true;
	else
		return false;
}

bool Board::checkForUserWin() //If all ships are marked as 'X', the person wins
{
	for (int i = 0; i < 18; i++)
	{
		int check = storeCompIndex[i];

		if (P1Hits[check] == 'X')
			continue;
		else
			return false;

	}
	return true;
}

bool Board::checkForP1Win()
{
	for (int i = 0; i < 18; i++)
	{
		int check = storeP2Index[i];

		if (P1Hits[check] == 'X')
			continue;
		else
			return false;

	}
	return true;
}

bool Board::checkForP2Win()
{
	for (int i = 0; i < 18; i++)
	{
		int check = storeP1Index[i];

		if (P1Hits[check] == 'X')
			continue;
		else
			return false;

	}
	return true;
}

bool Board::checkForCompWin()
{
	for (int i = 0; i < 18; i++)
	{
		int check = storeP1Index[i];
		if (P1Spot[check] == 'H')
			continue;
		else
			return false;
	}
	return true;
}

void Board::storeComputerIndex() //Stores all the ships indexes, used for the win validation
{
	int counter = 0;
	for (int i = 0; i < 100; i++)
	{
		if (compSpot[i] == char(254))
		{
			storeCompIndex[counter] = i;
			counter++;
		}
	}
}

void Board::storePlayer1Index()
{
	int counter = 0;
	for (int i = 0; i < 100; i++)
	{
		if (P1Spot[i] == char(254))
		{
			storeP1Index[counter] = i;
			counter++;
		}
	}
}

void Board::storePlayer2Index()
{
	int counter = 0;
	for (int i = 0; i < 100; i++)
	{
		if (P2Spot[i] == char(254))
		{
			storeP2Index[counter] = i;
			counter++;
		}
	}
}

void Board::outputStoredIndex() //JUST TEST CODE, NOT IMPLEMENTED IN PROGRAM
{
	std::cout << "Player 1:" << std::endl;
	for (int i = 0; i < 18; i++)
	{
		std::cout << storeP1Index[i] << std::endl;
	}

	std::cout << "Computer:" << std::endl;
	for (int j = 0; j < 18; j++)
	{
		std::cout << storeCompIndex[j] << std::endl;
	}
}

bool Board::compareHitWithBoard(int index, int turn) //If the user hits one of their ships, it will return true. if not it will return false
{
	if (turn == 0)
	{
		for (int i = 0; i < 18; i++)
		{
			if (index == storeCompIndex[i])
				return true;
		}
		return false;
	}

	else if (turn == 1)
	{
		for (int i = 0; i < 18; i++)
		{
			if (index == storeP1Index[i])
				return true;
		}
		return false;
	}
}

bool Board::compareHitWithBoardP1vP2(int index, int turn)
{
	if (turn == 0)
	{
		for (int i = 0; i < 18; i++)
		{
			if (index == storeP2Index[i])
				return true;
		}
		return false;
	}

	else if (turn == 1)
	{
		for (int i = 0; i < 18; i++)
		{
			if (index == storeP1Index[i])
				return true;
		}
		return false;
	}
}

bool Board::compCheckP1Spot(int index)
{
	if (P1Spot[index] == NULL)
		return true;
	else if (P1Spot[index] == (char)254)
		return true;
	else
		return false;
}

