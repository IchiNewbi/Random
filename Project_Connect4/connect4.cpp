
#include "stdafx.h"
#include <iostream>

using namespace std;

#define EMPTY_CELL_VALUE		' '//what the empty cell values are set to
#define MAXIMUM_ROWS			(6)//maximum rows
#define MAXIMUM_COLS			(7)//maximum columns

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
	cout << "====================="<<endl;
	for (int row = 5; row >= 0; row--)//draws each row
	{
		for (int col = 0; col < 7; col++)//draws each column peace in the row
		{
			cout <<"|"<<board[col][row]<<"|";//draws column peice
		}
		cout <<endl;//breaks the line for each loop
	}
	cout << "=====================" << endl;//ends with a line break
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

void drop(int c, int p)
{

}

int main()
{

	char board[7][6];
	setup(board);//generates and fills empty spaces in the board

	int p = 1;//player that starts first
	int game_win = 0;//default is zero so the game loop runs

	while (game_win == 0)//runs as long as nobody has won
	{

		bool v = 0;//presets the error return for the answer validation seen below to false
		do
		{
			int c;//presets the choice variable (c=choice)
			system("cls");//clears the game screen for game rendering
			if (bool == 1)
			{
				cout << "That column does not exist" << endl;
			}
			else
			{

			}
			draw_board(board);//draws previous board for their reference
			cout << endl;//break
			cout << "What column do you, player " << p << ", want to place your piece?" << endl;//text for the choice
			cin >> c;//recieves users choice
			if (c > 7)//tests if answer is a valid column number
			{//bad
				v = 1;
			}
			else
			{//good
				v = 0;
			}
		} while (v == 1);//repeat if error
		drop(c, p);//drop in column from player
		p = 1 - p;//flips the player variable
	}

    return 0;
}

