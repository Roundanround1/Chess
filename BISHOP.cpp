#include <iostream>
#include <string>
#include "Display.h"


void Bishop() {
	bool Board::moveBishop(Square * thisBishop, Square * thatSpace) {
		int bishopX = thisBishop->getX();
		int bishopY = thisBishop->getY();
		int thatX = thatSpace->getX();
		int thatY = thatSpace->getY();
		bool invalid = false;
		Square* s;
		if (abs(bishopX - thatX) == abs(bishopY - thatY))
		{
			int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
			int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

			for (int i = 1; i < abs(bishopX - thatX); i++)
			{
				std::cout << "It got here somehow";
				if (square[bishopX + xIncrement * i][bishopY + yIncrement * i].getColor() != NONE)
					return false;

			}
		}
		else
			return false;

		if (invalid == false)
		{
			thatSpace->setSpace(thisBishop);
			thisBishop->setEmpty();
			return true;
		}
		else
		{
			return false;
		}
	}
}