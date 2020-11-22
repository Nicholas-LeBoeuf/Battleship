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

void Board::updateBoard(int userSpot)
{
	spot[userSpot] = (char)254;
}

void Board::setChar()
{
	for (int i = 0; i < 100; i++)
	{
		spot[i] = NULL;
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