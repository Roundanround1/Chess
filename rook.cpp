#include <iostream>
#include <string>
#include "Display.h"

void rook() {
	bool Board::moveRook(Square * thisRook, Square * thatSpace)
	{

		int rookX = thisRook->getX();
		int rookY = thisRook->getY();
		int thatX = thatSpace->getX();
		int thatY = thatSpace->getY();
		bool invalid = false;
		if (rookX != thatX || rookY != thatY)
		{

			if (rookX == thatX)
			{
				int yIncrement = (thatY - rookY) / (abs(thatY - rookY));
				for (int i = rookY + yIncrement; i != thatY; i += yIncrement)
				{

					if (square[thatX][i].getColor() != NONE)
						return false;

				}
			}
			else
				if (rookY == thatY)
				{

					int xIncrement = (thatX - rookX) / (abs(thatX - rookX));
					for (int i = rookX + xIncrement; i != thatX; i += xIncrement)
					{
						if (square[i][thatY].getColor() != NONE)
							return false;
					}
				}
				else
					return false;
		}
		if (invalid == false)
		{
			thatSpace->setSpace(thisRook);
			thisRook->setEmpty();
			return true;
		}
		else
		{
			std::cout << "invalid move for rook";
			return false;
		}
	}
}
