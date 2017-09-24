// MyFirstProgram.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

int main()
{
	cout << "\nProgramming is\n";
	cout << "great fun\n\n";
	
	int number;
	
	number = 5;
	cout << "The value of the number is " << number << "\n\n";
	
	number = 7;
	cout << "The value of the number is now " << number << "\n\n";

	int apples;

	apples = 20;
	cout << "On Saturday, we sold " << apples << " bushels of apples. \n\n";

	apples = 15;
	cout << "On Monday, we sold " << apples << " bushels of apples. \n\n";

	char letter = 'c';
	char capletter;
	capletter = letter + 'A' - 'a';

	cout << capletter;

    return 0;
}

