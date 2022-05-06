#include <iostream>
#include <string>
#include "chessED.h"

using namespace std;





int main()
{
	Board b;
	string s;
	bool newgame = true;
	system("color 1e");
	cout << " The Chess Game " << endl;

	cout << "Enter any key to continue" << endl;
	cin >> s;
	
	while (newgame) {
		b.setBoard();
		while (b.playGame());
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> s;
		if (s != "y")
			newgame = false;
	}
	system("color 1e");

	return 0;
}