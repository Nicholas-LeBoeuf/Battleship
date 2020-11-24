#pragma once
#include <iostream>
#include "Board.h"
class Ship : public Board
{
public:
	char orientation();
	char computerRandomOrientation();
	int computerRandomIndex(int maxIndex);
};

