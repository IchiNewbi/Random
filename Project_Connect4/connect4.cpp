
#include "stdafx.h"
#include <iostream>

using namespace std;

#define EMPTY_CELL_VALUE		'_'
#define MAXIMUM_ROWS			(6)
#define MAXIMUM_COLS			(7)

void setup(char board[7][6])//board is set to [7][6] which represents column and row
{
	for (int row = 0; row < MAXIMUM_ROWS ; row++)//row is set to 0 and will repeat until row is greaterthan or equal to 6
	{
		for (int col = 0; col < MAXIMUM_COLS ; col++) {//col is set to 0 and will repeat until col is greaterthan or equal to 7
			board[col][row] = EMPTY_CELL_VALUE ;//blank board spaces will be printed as this
		}
	}
}

void draw_board(char board[7][6])//the board is drawn from the board array
{
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			cout <<" "<<board[col][row]<<" ";//draws each character in each row
		}
		cout << endl;//breaks the line each row down
	}
}

char getBoardValue(char board[7][6], int row, int col)
{
	return board[col][row];
}

bool isEmpty(char board[7][6], int row, int col)
{
	return getBoardValue(board, row, col) == EMPTY_CELL_VALUE;
}

bool isOccupied(char board[7][6], int row, int col)
{
	return !isEmpty(board, row, col);
}

void drop(int col)
{
	for (int col = 0; col < 7; col++)
	{
		for (int row = 0; row < 6; row++)
		{
			
		}
	}
}
int main()
{
	char board[7][6];
	setup(board);
	draw_board(board);
	int player = 1;
	cout << "What column do you, player "<<player<<", want to place your piece?"<<endl;//IMPORTANT STUFF DO THIS PLZ!!!!!!!!!!!!!!!!!!!!!
	cin >> int choice;
    return 0;
}

