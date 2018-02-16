//#include <stdafx.h>
#include <iostream>

using namespace std;

#define EMPTY_CELL_VALUE '_'
#define RED_CELL_VALUE 'x'
#define BLUE_CELL_VALUE 'o'

#define max_rows (6)
#define max_col (7)

char board[max_col][max_rows];

int charsPlaced = 0;

void setup()
{
	charsPlaced = 0; //resets board to zero
		for (int row = 0; row < max_rows; row++) {
			for (int col = 0; col < max_col; col++) {
				board[col][row] = '0' ; //resets board to all empty values
			}
		}
}
void draw_board() {
	system("cls");
	cout << "----------------------" << endl;
	for (int row = 0; row < max_rows; row++) {
		for (int col = 0; col < max_col; col++) {
			cout << "|" << board[col][row] << "|";
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
}

int main()
{
	setup();
	draw_board();
	// name player variables
}
