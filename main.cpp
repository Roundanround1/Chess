#include <iostream>
#include <string>
#include "Display.h"
using namespace std;

class Chess {
    
    public:
    char piece;
    char team;
    int points;

};
    // can you make a 2d array of object make * have zero points and also associate its color 
int main()
{
    Display();
    int size = 32;
    Chess game[size];

    bool test;

    game[1].team = 'R';
    game[1].piece = 'R';

    for (int i = 0; i < size; i++)
    {
        if (game[i].team == 'R')
        {
            test = true;
            cout << test << "\n";
            cout << "\e[0;31m" << game[1].piece << "\n";
        }
    }

    
    return 0;
}
