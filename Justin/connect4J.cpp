
// ConsoleApplication6.cpp: Defines the entry point for the console application. 


#include "stdafx.h"

#include <iostream>



using namespace std;

#define	empty_v	'_'

#define	max_r	(6)

#define max_c	(7)



char board[max_c][max_r];



int chars_p = 0;



void setup()

{

	for (int c = 0; c < max_c; c++)

	{

		for (int r = 0; r < max_r; r++)

		{

			board[c][r] = empty_v;

		}

	}

}

void drawboard()

{

	system("cls");

	cout << "---------------------" << endl;

	for (int r = 0; r < max_r; r++)

	{

		for (int c = 0; c < max_c; c++)

		{

			cout << "|" << board[c][r] << "|";

		}

		cout << endl;

	}

	cout << "---------------------" << endl;

}

char get_board_val(int c, int r)

{

	return board[c][r];

}

bool isEmpty(int c, int r)

{

	return get_board_val(c, r) == empty_v;

}

bool is_oc(int c, int r)

{

	return !isEmpty(c, r);

}

void drop(int col, int p)
{
	for (int row = max_r-1; row >= 0; row--)
	{
		if (board[col][row] == '_')
		{
			if (p == 0)
			{
				board[col][row] = 'X';
			} else
			{
				board[col][row] = 'O';
			}
			break;
		}
	}
}

int main()

{

	setup();

	drawboard();

	int player = 0;

	while (true)

	{

		cout << "Enter what column you want to play your token in?" << endl ;

		int column;

		cin >> column;
		if (column <= max_c - 1 && column >= 0)
		{
			drop(column, player);
			player = 1 - player;
			drawboard();
		}
		else
		{
			cout << "That number is not valid!!!!!!!!!!!!! (use 0-"<<max_c-1<<")" << endl;
		}
		

	}

	return 0;

}
