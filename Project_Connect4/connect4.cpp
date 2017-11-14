// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

#define EMPTY_CELL_VALUE		' '//what the empty cell values are set to (default = ' ')
#define RED_CELL_VALUE          'x'//what the "red" teams disk looks like (default = 1)
#define BLUE_CELL_VALUE         'o'//what the "blue" teams disk looks like (default = 2)
#define MAXIMUM_ROWS			(6)//maximum rows (default = 6)
#define MAXIMUM_COLS			(7)//maximum columns (default = 7)

void setup(int board[7][6])//board is set to [7][6] which represents column and row
{
	for (int row = 0; row < MAXIMUM_ROWS; row++)//row is set to 0 and will repeat until row is greaterthan or equal to 6
	{
		for (int col = 0; col < MAXIMUM_COLS; col++) {//col is set to 0 and will repeat until col is greaterthan or equal to 7
			board[col][row] = 0;//blank board spaces will be printed as this
		}
	}
}

char get_disk(int col, int row, int board[MAXIMUM_COLS][MAXIMUM_ROWS]) {
	if (board[col][row] == 0) {
		return EMPTY_CELL_VALUE;
	}
	else if (board[col][row] == 1) {
		return RED_CELL_VALUE;
	}
	else if (board[col][row] == 2) {
		return BLUE_CELL_VALUE;
	}
	else {
		return 'v';
	}
}

void draw_board(int board[MAXIMUM_COLS][MAXIMUM_ROWS])//the board is drawn from the board array
{
	cout << "=====================" << endl;
	for (int row = MAXIMUM_ROWS - 1; row >= 0; row--)//draws each row
	{
		for (int col = 0; col < MAXIMUM_COLS; col++)//draws each column peace in the row
		{
			char disk = get_disk(col, row, board);
			cout << "|" << disk << "|";//draws column peice
		}
		cout << endl;//breaks the line for each loop
	}
	cout << "=====================" << endl;//ends with a line break
}

char getBoardValue(int board[MAXIMUM_COLS][MAXIMUM_ROWS], int row, int col)
{
	return board[col][row];
}

bool isEmpty(int board[MAXIMUM_COLS][MAXIMUM_ROWS], int row, int col)
{
	return getBoardValue(board, row, col) == EMPTY_CELL_VALUE;
}

bool isOccupied(int board[MAXIMUM_COLS][MAXIMUM_ROWS], int row, int col)
{
	return !isEmpty(board, row, col);
}

void drop(int c, int p)
{

}

int main()
{

	int board[MAXIMUM_COLS][MAXIMUM_ROWS];
	setup(board);//generates and fills empty spaces in the board
	int c = 0;
	int p = 1;//player that starts first
	int game_win = 0;//default is zero so the game loop runs

	while (game_win == 0)//runs as long as nobody has won
	{

		bool v = 0;//presets the error return for the answer validation seen below to false
		do
		{
			int c;//presets the choice variable (c=choice)
			system("cls");//clears the game screen for game rendering
			if (v == 1)
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
