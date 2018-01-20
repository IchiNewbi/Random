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
int board[MAXIMUM_COLS][MAXIMUM_ROWS];

void setup()//board is set to [7][6] which represents column and row
{
	for (int row = 0; row < MAXIMUM_ROWS; row++)//row is set to 0 and will repeat until row is greaterthan or equal to 6
	{
		for (int col = 0; col < MAXIMUM_COLS; col++) {//col is set to 0 and will repeat until col is greaterthan or equal to 7
			board[col][row] = 0;//blank board spaces will be printed as this
		}
	}
}

char get_disk(int col, int row) {
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

void draw_board()//the board is drawn from the board array
{
	cout << "=====================" << endl;
	for (int row = MAXIMUM_ROWS - 1; row >= 0; row--)//draws each row
	{
		for (int col = 0; col < MAXIMUM_COLS; col++)//draws each column peace in the row
		{
			char disk = get_disk(col, row);
			cout << "|" << disk << "|";//draws column peice
		}
		cout << endl;//breaks the line for each loop
	}
	cout << "=====================" << endl;//ends with a line break
}

int getBoardValue(int col, int row)
{
	return board[col][row];
}

bool isEmpty(int col, int row)
{
	return getBoardValue(col, row) == 0;
}

void drop(int c, int p)
{
	for (int i = 0; i < MAXIMUM_ROWS; i++) {
		bool o = isEmpty(c, i);
		if (o == true)
		{
			board[c][i] = (p + 1);
			break;
		}
	}
}

bool checkVertical(int p)
{
	for (int c = 0; c < MAXIMUM_COLS; c++)
	{
		int count = 0;
		for (int r = 0; r < MAXIMUM_ROWS; r++)
		{
			if (board[c][r] == (p + 1))
			{
				count++;
			}
			else
			{
				count = 0;
			}
			if (count == 4)
			{
				return true;
			}
		}
	}
	return false;
}

bool checkLeftDiagonal(int p)
{
	return 0;
}

bool checkRightDiagonal(int p)
{
	return 0;
}

bool checkHorizontal(int p)
{
	for (int r = 0; r < MAXIMUM_ROWS; r++)
	{
		int count = 0;
		for (int c = 0; c < MAXIMUM_COLS; c++)
		{
			if (board[c][r] == (p + 1))
			{
				count++;
			}
			else
			{
				count = 0;
			}
			if (count == 4)
			{
				return true;
			}
		}
	}
	return false;
}

bool checkWin(int p)
{
	if (checkVertical(p))
	{
		return true;
	}
	if (checkHorizontal(p))
	{
		return true;
	}
	if (checkLeftDiagonal(p))
	{
		return true;
	}
	if (checkRightDiagonal(p))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setup();//generates and fills empty spaces in the board
	int c = 0;
	int p = 1;//player that starts first
	int win = 0;//default is zero so the game loop runs
	
	do
	{
		bool v = 0;//presets the error return for the answer validation seen below to false
		do
		{
			system("cls");//clears the game screen for game rendering
			if (v == 1)
			{
				cout << "That column does not exist" << endl;
				v = 0;
			}
			else
			{

			}
			draw_board();//draws previous board for their reference
			cout << endl;//break
			cout << "What column do you, player " << p + 1 << ", want to place your piece?" << endl;//text for the choice
			cin >> c;//recieves users choice
			if (c > MAXIMUM_COLS || c < 1)//tests if answer is a valid column number
			{//bad
				v = 1;
			}
			else
			{//good
				v = 0;
			}
		} while (v == 1);//repeat if error
		drop(c - 1, p);//drop in column from player
		if (checkWin(p))
		{
			int e = 0;
			do
			{
				int r;
				system("cls");
				system("title Win = 1");
				cout << "Player, " << p << ", wins!" << endl;
				cout << "Restart? [1/2]" << endl;
				cin >> r;//recieves users choice
				if (r == 1)
				{
					setup();
				}
				else if (r == 2)
				{
					win = 1;
					break;
				}
				else
				{
					e = 1;
				}
			} while (e == 1);
		}
		else
		{
			system("title Win = 0");
			cout << "No body has one" << endl;
		}
		p = 1 - p;//flips the player variable
	} while (win == 0);//runs as long as nobody has won

	return 0;
}



