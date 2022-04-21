#include <iostream>
#include <string>
#include "Display.h"

void king() {

		bool gameBoard::moveKing(Square* thisKing, Square * thatSpace) {
			if (abs(thatSpace->getX() - thisKing->getX()) == 1)
				if (abs(thatSpace->getY() - thisKing->getY()) == 1)
				{
					thatSpace->setSpace(thisKing);
					thisKing->setEmpty();
					return true;
				}
				else return false;
			else return false;
		}
	}

