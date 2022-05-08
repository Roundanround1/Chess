#include <iostream>
#include <string>
#include "FinalChess.h"
using namespace std;

int main()
{
    int size = 8;
    Chess game[size][size]; //x,y format
    Chess base[1][1]; //used to change a piece back to * abd white
    base[0][0].piece = '*';
    base[0][0].team = 'W'; // Changed team to neutral

    //Populates board with all astericks
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            game[i][j].piece = '*';
            game[i][j].team = 'W';
        }
    }

// ------------------------------------------------------------------------------------------------------------------------

    //populate pawns
    for (int i = 0; i < 8; i++)
    {
        game[1][i].piece = 'P';
        game[6][i].piece = 'P';
    }
    
    //populate special pieces
    //Rooks
    game[0][0].piece = 'R';
    game[0][7].piece = 'R';
    game[7][0].piece = 'R';
    game[7][7].piece = 'R';

    //Knights
    game[0][1].piece = 'N';
    game[0][6].piece = 'N';
    game[7][1].piece = 'N';
    game[7][6].piece = 'R';

    //Bishops
    game[0][2].piece = 'B';
    game[0][5].piece = 'B';
    game[7][2].piece = 'B';
    game[7][5].piece = 'B';

    //King and Queen
    game[0][3].piece = 'Q';
    game[7][4].piece = 'K';
    game[0][4].piece = 'K';
    game[7][3].piece = 'Q';

    //Populate teams
    for (int i = 0; i < 8; i++)
    {
        game[0][i].team = 'R';
        game[1][i].team = 'R';

        game[6][i].team = 'W';
        game[7][i].team = 'W';
    }

// ------------------------------------------------------------------------------------------------------------------------
//This section referred to as Whole Display

    //Display begins here 
    char temp[] = "12345678"; //top row of numbers

    // lines up top row of numbers and displays them 
    cout << endl;
    cout << " " << " "; 
    
    for (int i = 0; i < 8; i++)
    {
        cout << temp[i] << ' ';
    }
    cout << endl;
    
    // Displays left column of number and then displays the game board
    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << ' '; 
        for(int j = 0; j < size; j++)
        {
            if (game[i][j].team == 'R')
            {
                cout << "\e[0;31m" << game[i][j].piece << "\e[0m" << ' ';
            }
            else if (game[i][j].team == 'W')
            {
                cout << "\e[0m" << game[i][j].piece << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
    //Display ends here 

// ------------------------------------------------------------------------------------------------------------------------

    //Game Start

    bool GameOver = false;
    bool Valid = false;
    char holder; //Holds the piece to be used in the switch case
    int x1, y1, x2, y2;
    string move1;
    string move2;
    bool turn = true;
    bool CanMove = false;


    while(GameOver == false)
    {
        if (turn == true) //Prints for player one (White)
        {
            while (CanMove == false)
            {
                cout << "Player one (White) please enter the piece you'd like to move xy: ";
                cin >> move1;
                x1 = move1[0] - 49; //Because 11 is really 00
                y1 = move1[1] - 49;
                if (game[x1][y1].team == 'W' && game[x1][y1].piece != '*') 
                {
                    CanMove = true;
                }
                else
                {
                    cout << "\e[0;33mThis is not your piece try again.\e[0m" << endl << endl;
                }
            }
            CanMove = false;
            cout << "Enter where you would like to move xy: ";
            cin >> move2;
            x2 = move2[0] - 49; //Because 11 is really 00
            y2 = move2[1] - 49;
        }
        else if (turn == false) //Prints for player two (Red)
        {
            while (CanMove == false)
            {
                cout << "Player two (Red) please enter the piece you'd like to move xy: ";
                cin >> move1;
                x1 = move1[0] - 49; //Because 11 is really 00
                y1 = move1[1] - 49;
                if (game[x1][y1].team == 'R' && game[x1][y1].piece != '*') 
                {
                    CanMove = true;
                }
                else
                {
                    cout << "\e[0;33mThis is not your piece try again.\e[0m" << endl << endl;
                }  
            }
            CanMove = false;
            cout << "Enter where you would like to move xy: ";
            cin >> move2;
            x2 = move2[0] - 49; //Because 11 is really 00
            y2 = move2[1] - 49;
        }
        
        Valid = false;

        while (Valid == false)
        {
            holder = game[x1][y1].piece;

            switch(holder)
            {
                case 'P':
//This allows for the pawn to move two spaces on it's first turn 
// ------------------------------------------------------------------------------------------------------------------------

                if (game[x1][y1].team == 'R' && x1 == 1)
                {
                    if ((x2 == x1 + 1 || x2 == x1 + 2) && y2 == y1)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                    }
                }
                //This will not allow a pawn to move forward two spaces if they have moved once
                //Allow takes here
                else if (game[x1][y1].team == 'R' && x1 != 1)
                {
                    if (x2 == x1 + 1  && y2 == y1 && game[x2][y2].piece == '*')
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    //new
                    else if (x2 == x1 + 1  && (y2 == y1 -1 || y2 == y1 + 1) && (game[x2][y2].piece != '*' && game[x2][y2].team != 'W'))
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                    }
                }
                //This is the code that allows a pawn to move two spaces on it's first turn
                else if (game[x1][y1].team == 'W' && x1 == 6)
                {
                    if ((x2 == x1 - 1 || x2 == x1 - 2) && y2 == y1)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                    }

                }
                //This will not allow a pawn to move forward two spaces if they have moved once
                //Allow takes here
                else if (game[x1][y1].team == 'W' && x1 != 6)
                {
                    if (x2 == x1 - 1  && y2 == y1 && game[x2][y2].piece == '*')
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if (x2 == x1 - 1  && (y2 == y1 -1 || y2 == y1 + 1) && (game[x2][y2].piece != '*' && game[x2][y2].team != 'W'))
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                    }
                }
                break;

                case 'N':
//Start function for knight
// ------------------------------------------------------------------------------------------------------------------------
                if (game[x1][y1].team == 'R' && (x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1 - 2 || x2 == x1 + 2) && 
                (y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1 + 2 || y2 == y1 - 2) && 
                (game[x2][y2].piece == '*' || game[x2][y2].team == 'W'))
                {
                    Valid = true;
                    turn = turn - 1;
                    game[x2][y2] = game[x1][y1];
                    game[x1][y1] = base[0][0];
                }
                else if (game[x1][y1].team == 'W' && (x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1 - 2 || x2 == x1 + 2) && 
                (y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1 + 2 || y2 == y1 - 2) && 
                (game[x2][y2].piece == '*' || game[x2][y2].team == 'R'))
                {
                    Valid = true;
                    turn = turn - 1;
                    game[x2][y2] = game[x1][y1];
                    game[x1][y1] = base[0][0];
                }
                else
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
                break;
                
                case 'K':
//Stat function for king
// ------------------------------------------------------------------------------------------------------------------------
                if (game[x1][y1].team == 'R' && (x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1) &&
                    (y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1) &&
                    (game[x2][y2].piece == '*' || game[x2][y2].team == 'W'))
                {
                    Valid = true;
                    turn = turn - 1;
                    game[x2][y2] = game[x1][y1];
                    game[x1][y1] = base[0][0];
                }
                else if (game[x1][y1].team == 'W' && (x2 == x1 + 1 || x2 == x1 - 1 || x2 == x1) &&
                    (y2 == y1 + 1 || y2 == y1 - 1 || y2 == y1) &&
                    (game[x2][y2].piece == '*' || game[x2][y2].team == 'R'))
                {
                    Valid = true;
                    turn = turn - 1;
                    game[x2][y2] = game[x1][y1];
                    game[x1][y1] = base[0][0];
                }
                else
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
                break;
                
                case 'Q':
//Start function for Queen
// ------------------------------------------------------------------------------------------------------------------------
                if(game[x1][y1].team == 'R' && (x2 <= 8 && y2 <= 8) && (game[x2][y2].piece == '*' || game[x2][y2].team == 'W'))
                {
                    bool Qcollision = false;
                    Qcollision = false;
                    if(x2 < x1)
                    {
                        for (int i = x1; i > x2; i--)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'R')
                            {
                                Qcollision = true;
                            }
                        }

                    }
                    else if (x2 > x1)
                    {
                        for (int i = x1+1; i < x2; i++)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'R')
                            {   
                                Qcollision = true;
                            }
                        }
                    }
                    else if (y2 > y1)
                    {
                        for (int j = y1+1; j < y2; j++)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'R')
                            {
                                Qcollision = true;
                            }
                        }
                    }
                    else if (y2 < y1)
                    {
                        for (int j = y1; j > y2; j--)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'R')
                            {
                                Qcollision = true;
                            }
                        }
                    }
                    
                    if(Qcollision == false)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if(Qcollision == true)
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                        Qcollision = false;
                    }
                }
                else if (game[x1][y1].team == 'R')
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    cout << "No way" << endl;
                    Valid = true;
                }
//White player
                if(game[x1][y1].team == 'W' && (x2 <= 8 && y2 <= 8) && (game[x2][y2].piece == '*' || game[x2][y2].team == 'R'))
                {
                    bool QCollision = false;
                    QCollision = false;
                    if(x2 < x1)
                    {
                        for (int i = x1; i > x2; i--)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'W')
                            {
                                QCollision = true;
                            }
                        }

                    }
                    else if (x2 > x1)
                    {
                        for (int i = x1+1; i < x2; i++)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'W')
                            {
                                
                                QCollision = true;
                            }
                        }
                    }
                    else if (y2 > y1)
                    {
                        for (int j = y1+1; j < y2; j++)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'W')
                            {
                               
                                QCollision = true;
                            }
                        }
                    }
                    else if (y2 < y1)
                    {
                        for (int j = y1; j > y2; j--)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'W')
                            {
                                QCollision = true;
                            }
                        }
                    }
                    
                    if(QCollision == false)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if(QCollision == true)
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                        QCollision = false;
                    }
                }
                else if (game[x1][y1].team == 'W')
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
                break;
//Start function for Rook
// ------------------------------------------------------------------------------------------------------------------------
                case 'R':
                if(game[x1][y1].team == 'R' && (x2 <= 8 && y2 <= 8) && (game[x2][y2].piece == '*' || game[x2][y2].team == 'W') &&
                  (x2 < x1 && y2 == y1) || (x2 == x1 && y2 < y1) || (x2 > x1 && y2 == y1) || (x2 == x1 && y2 > y1))
                {
                    bool Rcollision = false;
                    Rcollision = false;
                    if(x2 < x1)
                    {
                        for (int i = x1 - 1; i > x2; i--)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'R')
                            {
                                Rcollision = true;
                            }
                        }

                    }
                    else if (x2 > x1)
                    {
                        for (int i = x1 + 1; i < x2; i++)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'R')
                            {
                                
                                Rcollision = true;
                            }
                        }
                    }
                    else if (y2 > y1)
                    {
                        for (int j = y1 + 1; j < y2; j++)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'R')
                            {
                                Rcollision = true;
                            }
                        }
                    }
                    else if (y2 < y1)
                    {
                        for (int j = y1 - 1; j > y2; j--)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'R')
                            {
                                Rcollision = true;
                            }
                        }
                    }
                    
                    if(Rcollision == false)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if(Rcollision == true)
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                        Rcollision = false;
                    }
                }
                else if (game[x1][y1].team == 'R')
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
//White player
                if(game[x1][y1].team == 'W' && (x2 <= 8 && y2 <= 8) && (game[x2][y2].piece == '*' || game[x2][y2].team == 'R') &&
                  (x2 < x1 && y2 == y1) || (x2 == x1 && y2 < y1) || (x2 > x1 && y2 == y1) || (x2 == x1 && y2 > y1))
                {
                    bool RCollision = false;
                    RCollision = false;
                    if(x2 < x1)
                    {
                        for (int i = x1 - 1; i > x2; i--)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'W')
                            {
                                RCollision = true;
                            }
                        }

                    }
                    else if (x2 > x1)
                    {
                        for (int i = x1 + 1; i < x2; i++)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'W')
                            {
                                
                                RCollision = true;
                            }
                        }
                    }
                    else if (y2 > y1)
                    {
                        for (int j = y1 + 1; j < y2; j++)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'W')
                            {
                                RCollision = true;
                            }
                        }
                    }
                    else if (y2 < y1)
                    {
                        for (int j = y1 - 1; j > y2; j--)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'W')
                            {
                                RCollision = true;
                            }
                        }
                    }
                    
                    if(RCollision == false)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if(RCollision == true)
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                        RCollision = false;
                    }
                }
                else if (game[x1][y1].team == 'W')
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
                break;
//Start function for bishop
// ------------------------------------------------------------------------------------------------------------------------
                case 'B':
                if(game[x1][y1].team == 'R' && (x2 <= 8 && y2 <= 8) && (game[x2][y2].piece == '*' || game[x2][y2].team == 'W') &&
                  (x2 < x1 && y2 < y1) || (x2 < x1 && y2 > y1) || (x2 > x1 && y2 < y1) || (x2 > x1 && y2 > y1))
                {
                    bool Bcollision = false;
                    Bcollision = false;
                    if(x2 < x1)
                    {
                        for (int i = x1 - 1; i > x2; i--)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'R')
                            {
                                Bcollision = true;
                            }
                        }

                    }
                    else if (x2 > x1)
                    {
                        for (int i = x1 + 1; i < x2; i++)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'R')
                            {
                                
                                Bcollision = true;
                            }
                        }
                    }
                    else if (y2 > y1)
                    {
                        for (int j = y1 + 1; j < y2; j++)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'R')
                            {
                                Bcollision = true;
                            }
                        }
                    }
                    else if (y2 < y1)
                    {
                        for (int j = y1 - 1; j > y2; j--)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'R')
                            {
                                Bcollision = true;
                            }
                        }
                    }
                    
                    if(Bcollision == false)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if(Bcollision == true)
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        Valid = true;
                        Bcollision = false;
                    }
                }
                else if (game[x1][y1].team == 'R')
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
//White player
                if(game[x1][y1].team == 'W' && (x2 <= 8 && y2 <= 8) && (game[x2][y2].piece == '*' || game[x2][y2].team == 'R') &&
                  (x2 < x1 && y2 < y1) || (x2 < x1 && y2 > y1) || (x2 > x1 && y2 < y1) || (x2 > x1 && y2 > y1))
                {
                    bool BCollision = false;
                    BCollision = false;
                    if(x2 < x1)
                    {
                        for (int i = x1 - 1; i > x2; i--)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'W')
                            {
                                BCollision = true;
                            }
                        }

                    }
                    else if (x2 > x1)
                    {
                        for (int i = x1 + 1; i < x2; i++)
                        {
                            if(game[i][y2].piece != '*' && game[i][y2].team == 'W')
                            {
                                
                                BCollision = true;
                            }
                        }
                    }
                    else if (y2 > y1)
                    {
                        for (int j = y1 + 1; j < y2; j++)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'W')
                            {
                                BCollision = true;
                            }
                        }
                    }
                    else if (y2 < y1)
                    {
                        for (int j = y1 - 1; j > y2; j--)
                        {
                            if(game[x2][j].piece != '*' && game[x2][j].team == 'W')
                            {
                                BCollision = true;
                            }
                        }
                    }
                    
                    if(BCollision == false)
                    {
                        Valid = true;
                        turn = turn - 1;
                        game[x2][y2] = game[x1][y1];
                        game[x1][y1] = base[0][0];
                    }
                    else if(BCollision == true)
                    {
                        cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                        cout << "invalid here" << endl;
                        Valid = true;
                        BCollision = false;
                    }
                }
                else if (game[x1][y1].team == 'W')
                {
                    cout << "\e[0;33mInvalid move please try again.\e[0m" << endl << endl;
                    Valid = true;
                }
                break;

            }
            
            //Everything below this is just Whole Display copied and pasted
            cout << endl;
            cout << " " << " ";
    
            for (int i = 0; i < 8; i++)
            {
                cout << temp[i] << ' ';
            }
    
            cout << endl;
    
            for(int i = 0; i < size; i++)
            {
                cout << i + 1 << ' ';
                for(int j = 0; j < size; j++)
                {
                    if (game[i][j].team == 'R')
                    {
                      cout << "\e[0;31m" << game[i][j].piece << "\e[0m" << ' ';
                    }
                    else if (game[i][j].team == 'W')
                    {
                        cout << "\e[0m" << game[i][j].piece << ' ';
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
    }   
    return 0;
}