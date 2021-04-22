// GoL.cpp : John Conway's Game of Life
// CSCI 222
// 3.24.2021
// Cody McKinney

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Global Variables
const int HEIGHT = 8;
const int WIDTH = 10;
const char LIVE = 'o';
const char DEAD = '.';
char new_board[HEIGHT][WIDTH];

/*
* init_board() - initializes the game board by taking user input for each character of the board
* 8 rows of 10 columns
* '.' for dead / 'o' for alive
*/
void init_board(char game[HEIGHT][WIDTH])
{
    cout << "Configure games initial shape." << endl;
    cout << "8 x 10 grid: Enter 10 characters ('.' for empty cell, 'o' for alive cell). " << endl << "Hit enter after each line (10 characters)." << endl << endl;

    cout << "0123456789" << endl;
    cout << "==========" << endl;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {     
            cin >> game[i][j];
        }
    }
    cout << endl << endl;
}

/*
* print_board() - takes the 2D game array and displays the board in its format to the console
*/
void print_board(char game[HEIGHT][WIDTH])
{
    cout << "0123456789" << endl;
    cout << "==========" << endl;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << game[i][j];
        }
        cout << endl;
    }
    cout << "==========" << endl;
    cout << "0123456789" << endl << endl;
}

/*
* generation() - is where the game rules take place
* on method call, generation() looks thru each cell at its coordinate and checks neighbors
* neighbors is counted up and then following the rules, produces a new_board[][] based on the output of the last
*/
void generation(char game[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        { 
            int neighbors = 0;
            if (i != 0 && j != 0)
            {
                if (game[(i - 1)][(j - 1)] == LIVE) // 1 top left
                {
                    neighbors++;
                }
            }
            
            if (i != 0)
            {
                if (game[(i - 1)][j] == LIVE) // 2 top
                {
                    neighbors++;
                }
            }

            if (i != 0 && j != WIDTH)
            {
                if (game[(i - 1)][(j + 1)] == LIVE) // 3 top right
                {
                    neighbors++;
                }
            }
            
            if (j != 0)
            {
                if (game[i][(j - 1)] == LIVE) // 4 right
                {
                    neighbors++;
                }
            }

            if (j != WIDTH)
            {
                if (game[i][(j + 1)] == LIVE) // 5 left
                {
                    neighbors++;
                }
            }

            if (i != HEIGHT && j != 0)
            {
                if (game[(i + 1)][(j - 1)] == LIVE) // 6 bottom left
                {
                    neighbors++;
                }
            }

            if (i != HEIGHT)
            {
                if (game[(i + 1)][j] == LIVE) // 7 bottom
                {
                    neighbors++;
                }
            }

            if (i != HEIGHT && j != WIDTH)
            {
                if (game[(i + 1)][(j + 1)] == LIVE) // 8 bottom right
                {
                    neighbors++;
                }
            }

            /*
            *  Rules:
            *   1.	live cell with < 2 neighbors dies: lonliness
            *   2.	live cell with two or three neighbours lives
            *   3.	live cell with > three neighbours dies: overcrowding.
            *   4.	live cell is born on empty cell if surrounded by exactly 3 neighbors
            */

            new_board[i][j] = DEAD;

            if (game[i][j] == LIVE && neighbors < 2)  // rule 1
            {
                new_board[i][j] = DEAD;
            }
            else if (game[i][j] == LIVE && (neighbors == 2 || neighbors == 3)) // rule 2
            {
                new_board[i][j] = LIVE;
            }
            else if (game[i][j] == LIVE && neighbors > 3) // rule 3
            {
                new_board[i][j] = DEAD;
            }
            else if (game[i][j] == DEAD && neighbors == 3) // rule 4
            {
                new_board[i][j] = LIVE;
            }
        }
    }
}

/*
* switch_board() - replaces the game[][] array with the new_board[][] array 
* so on next print method call we are printing the contents of the next generation
*/
void switch_board(char game[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            game[i][j] = new_board[i][j];
        }
    }
}


int main()
{
    char game[HEIGHT][WIDTH];
    init_board(game);
    cout << "GENERATING NEW CELLS from User Input" << endl << endl;
    cout << "++++++++++++ User Input" << endl << endl;
    print_board(game);
    for (int i = 1; i < 200; i++)
    {
        generation(game);
        switch_board(game);
        cout << "++++++++++++ #" << i << " generation" << endl << endl;
        print_board(game);
    }

    return 0;
}

