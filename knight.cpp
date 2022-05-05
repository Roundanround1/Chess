#include <iostream>
#include <string>
#include "Display.h"

void knight() {
	bool Board::moveKnight(Square * thisKnight, Square * thatSpace)
	{
		int knightX = thisKnight->getX();
		int knightY = thisKnight->getY();
		int thatX = thatSpace->getX();
		int thatY = thatSpace->getY();

		if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
		{
			thatSpace->setSpace(thisKnight);
			thisKnight->setEmpty();
			return true;
		}
		else
		{
			return false;
		}
	}
}
