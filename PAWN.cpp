#include <iostream>
#include <string>
#include "Display.h"


void Pawn() {
	bool Board::movePawn(Square * thisPawn, Square * thatSpace) {
		//off board inputs should be handled elsewhere (before this)
		//squares with same color should be handled elsewhere (before this)
		using namespace std;
		bool invalid = false;
		int pawnX = thisPawn->getX();
		int pawnY = thisPawn->getY();
		int thatX = thatSpace->getX();
		int thatY = thatSpace->getY();


		if (thisPawn->getColor() == WHITE)
		{

			if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY && thatSpace->getColor() == BLACK)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					return false;
		}
		else
			if (thisPawn->getColor() == BLACK)
			{
				if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY && thatSpace->getColor() == WHITE)
					{
						thatSpace->setSpace(thisPawn);
						thisPawn->setEmpty();
						return true;
					}
					else
						return false;
			}
			else
				return false;
	}
}