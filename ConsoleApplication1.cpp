// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>

using namespace std;

#define EMPTY_CELL_VALUE		'_'
#define MAXIMUM_ROWS			(6)
#define MAXIMUM_COLS			(7)


char board[MAXIMUM_COLS][MAXIMUM_ROWS];
int charsPlaced = 0;

void setup()//board is set to [7][6] which represents column and row
{
	charsPlaced = 0;
	for (int row = 0; row < MAXIMUM_ROWS; row++)//row is set to 0 and will repeat until row is greaterthan or equal to 6
	{
		for (int col = 0; col < MAXIMUM_COLS; col++) {//col is set to 0 and will repeat until col is greaterthan or equal to 7
			board[col][row] = EMPTY_CELL_VALUE;//blank board spaces will be printed as this
		}
	}
}

void draw_board()   //the board is drawn from the board array
{
	system("cls");
	cout << "---------------------" << endl;
	for (int row = 0; row < MAXIMUM_ROWS; row++)
	{
		for (int col = 0; col < MAXIMUM_COLS; col++)
		{
			cout << "|" << board[col][row] << "|";//draws each character in each row
		}
		cout << endl;//breaks the line each row down
	}
	cout << "---------------------" << endl;
}

char getBoardValue(int col, int row)
{
	return board[col][row];
}

bool isEmpty(int col, int row)
{
	return getBoardValue(col, row) == EMPTY_CELL_VALUE;
}

bool isOccupied(int col, int row)
{
	return !isEmpty(col, row);
}

void drop(int c, int p)
{
	for (int r = MAXIMUM_ROWS - 1; r >= 0; r--) {
		if (board[c][r] == '_') {
			if (p == 0) {
				board[c][r] = 'X';
			}
			else {
				board[c][r] = 'O';
			}
			break;
		}
	}
}

bool checkWinHorizontal(int p) {
	char token;
	if (p == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	//char token = (p == 0) ? 'X' : 'O';
	for (int r = 0; r < MAXIMUM_ROWS; r++) {
		int tokenCount = 0;
		for (int c = 0; c < MAXIMUM_COLS; c++) {
			if (board[c][r] == token) {
				tokenCount++;
			}
			else {
				tokenCount = 0;
			}
			if (tokenCount == 4) {
				return true;
			}
		}
	}
	return false;
}
bool checkWinVertical(int p) {
	char token;
	if (p == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	//char token = (p == 0) ? 'X' : 'O';
	for (int c = 0; c < MAXIMUM_COLS; c++) {
		int tokenCount = 0;
		for (int r = 0; r < MAXIMUM_ROWS; r++) {
			if (board[c][r] == token) {
				tokenCount++;
			}
			else {
				tokenCount = 0;
			}
			if (tokenCount == 4) {
				return true;
			}
		}
	}
	return false;
}

bool checkWinDiagonalRightUp(int p) {
		char token;
		if (p == 0) {
			token = 'X';
		}
		else {
			token = 'O';
		}
		//char token = (p == 0) ? 'X' : 'O';
		for (int r = 0; r < MAXIMUM_ROWS; r++) {
			int tokenCount = 0;
			for (int c = 0, r2 = r; c < MAXIMUM_COLS && r2 >= 0; c++, r2--) {
				
				if (board[c][r2] == token) {
					tokenCount++;
				}
				else {
					tokenCount = 0;
				}
				if (tokenCount == 4) {
					return true;
				}
			}
		}
		for (int c = 0; c < MAXIMUM_COLS; c++) {
			int tokenCount = 0;
			for (int c2 = c, r = MAXIMUM_ROWS-1; c2 < MAXIMUM_COLS && r >= 0; c2++, r--) {

				if (board[c2][r] == token) {
					tokenCount++;
				}
				else {
					tokenCount = 0;
				}
				if (tokenCount == 4) {
					return true;
				}
			}
		}
		return false;
}

bool checkWinDiagonalRightDown(int p) {
	char token;
	if (p == 0) {
		token = 'X';
	}
	else {
		token = 'O';
	}
	//char token = (p == 0) ? 'X' : 'O';
	for (int r = 0; r < MAXIMUM_ROWS; r++) {
		int tokenCount = 0;
		for (int c = 0, r2 = r; c < MAXIMUM_COLS && r2 < MAXIMUM_ROWS; c++, r2++) {

			if (board[c][r2] == token) {
				tokenCount++;
			}
			else {
				tokenCount = 0;
			}
			if (tokenCount == 4) {
				return true;
			}
		}
	}
	for (int c = 0; c < MAXIMUM_COLS; c++) {
		int tokenCount = 0;
		for (int c2 = c, r = 0; c2 < MAXIMUM_COLS && r < MAXIMUM_ROWS; c2++, r++) {

			if (board[c2][r] == token) {
				tokenCount++;
			}
			else {
				tokenCount = 0;
			}
			if (tokenCount == 4) {
				return true;
			}
		}
	}
	return false;
}

bool checkWin(int p) {
	if (checkWinHorizontal(p)) {
		return true;
	}
	if (checkWinVertical(p)) {
		return true;
	}
	if (checkWinDiagonalRightUp(p)) {
		return true;
	}
	if (checkWinDiagonalRightDown(p)) {
		return true;
	}
	return false;
}

int main()
{
	setup();

	int p = 0;
	int c;
	bool gameOver = false;
	

	while (!gameOver)
	{
		if (charsPlaced == MAXIMUM_COLS * MAXIMUM_ROWS) {
			gameOver = true;
			cout << "Tie game" << endl;
			system("pause");
		}
		draw_board();
		cout << endl;
		cout << "Player " << p << ", which column do you want to place your piece in?" << endl;
		cin >> c;
		if (c >= 0 && c <= MAXIMUM_ROWS) {
			drop(c, p);
			charsPlaced++;
			if (checkWin(p)) {
				draw_board();
				cout << "Player " << p << " Wins!" << endl;
				system("pause");
				//gameOver = true;
				setup();
				draw_board();


				continue;
			}
			p = 1 - p;
		}
		else {
			cout << "Pick column 0-" << MAXIMUM_ROWS << endl;
			system("pause");
		}

	}

	return 0;
}
