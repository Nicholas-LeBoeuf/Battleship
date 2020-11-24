#include <iostream>
#include <Windows.h>
#include "Board.h"

void Board::displayBoard()
{
	std::cout << "\t\t1 2 3 4 5 6 7 8 9 10" << std::endl;
	std::cout << "\t      A|" << spot[0] << "|" << spot[1] << "|" << spot[2] << "|" << spot[3] << "|" << spot[4] << "|" << spot[5] << "|" << spot[6] << "|" << spot[7] << "|" << spot[8] << "|" << spot[9] << "|" << std::endl;
	std::cout << "\t      B|" << spot[10] << "|" << spot[11] << "|" << spot[12] << "|" << spot[13] << "|" << spot[14] << "|" << spot[15] << "|" << spot[16] << "|" << spot[17] << "|" << spot[18] << "|" << spot[19] << "|" << std::endl;
	std::cout << "\t      C|" << spot[20] << "|" << spot[21] << "|" << spot[22] << "|" << spot[23] << "|" << spot[24] << "|" << spot[25] << "|" << spot[26] << "|" << spot[27] << "|" << spot[28] << "|" << spot[29] << "|" << std::endl;
	std::cout << "\t      D|" << spot[30] << "|" << spot[31] << "|" << spot[32] << "|" << spot[33] << "|" << spot[34] << "|" << spot[35] << "|" << spot[36] << "|" << spot[37] << "|" << spot[38] << "|" << spot[39] << "|" << std::endl;
	std::cout << "\t      E|" << spot[40] << "|" << spot[41] << "|" << spot[42] << "|" << spot[43] << "|" << spot[44] << "|" << spot[45] << "|" << spot[46] << "|" << spot[47] << "|" << spot[48] << "|" << spot[49] << "|" << std::endl;
	std::cout << "\t      F|" << spot[50] << "|" << spot[51] << "|" << spot[52] << "|" << spot[53] << "|" << spot[54] << "|" << spot[55] << "|" << spot[56] << "|" << spot[57] << "|" << spot[58] << "|" << spot[59] << "|" << std::endl;
	std::cout << "\t      G|" << spot[60] << "|" << spot[61] << "|" << spot[62] << "|" << spot[63] << "|" << spot[64] << "|" << spot[65] << "|" << spot[66] << "|" << spot[67] << "|" << spot[68] << "|" << spot[69] << "|" << std::endl;
	std::cout << "\t      H|" << spot[70] << "|" << spot[71] << "|" << spot[72] << "|" << spot[73] << "|" << spot[74] << "|" << spot[75] << "|" << spot[76] << "|" << spot[77] << "|" << spot[78] << "|" << spot[79] << "|" << std::endl;
	std::cout << "\t      I|" << spot[80] << "|" << spot[81] << "|" << spot[82] << "|" << spot[83] << "|" << spot[84] << "|" << spot[85] << "|" << spot[86] << "|" << spot[87] << "|" << spot[88] << "|" << spot[89] << "|" << std::endl;
	std::cout << "\t      J|" << spot[90] << "|" << spot[91] << "|" << spot[92] << "|" << spot[93] << "|" << spot[94] << "|" << spot[95] << "|" << spot[96] << "|" << spot[97] << "|" << spot[98] << "|" << spot[99] << "|" << std::endl;
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

void Board::updateBoard(int userSpot)
{
	spot[userSpot] = (char)254;
}

void Board::updateCompBoard(int computerSpot)
{
	compSpot[computerSpot] = (char)254;
}

void Board::setChar()
{
	for (int i = 0; i < 100; i++)
	{
		spot[i] = NULL;
	}
}

void Board::setCompChar()
{
	for (int i = 0; i < 100; i++)
	{
		compSpot[i] = NULL;
	}
}

bool Board::checkInput(std::string userInput)
{
	for (int i = 0; i < 100; i++)
	{
		if (userInput == validInputs[i])
			return true;
		else if (i == 99 && userInput != validInputs[i])
			return false;
	}
}

int Board::findArrayIndex(std::string userInput)
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

bool Board::checkForEmptySpot(int index)
{
	if (spot[index] == NULL)
		return true;
	else
		return false;
}