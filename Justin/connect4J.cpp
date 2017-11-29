// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int num_col = 6;
const int num_row = 7;
int board[num_col][num_row];

void init_board()
{
	for (int c = 0; c < num_col; c++)
	{
		for (int r = 0; r < num_row; r++)
		{
			board[c][r] = -1;
		}
	}
}
 

int main()
{
	int player = 0;
	while (true)
	{
		cout << "Enter what column you want to play your Token in?";
		int column;
		cin >> column;
		cout << column << endl;
	}
	return 0;
}
