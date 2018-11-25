//============================================================================
// Name        : OXOb.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int board[3][3] = {
			1,2,0,
			0,2,0,
			1,2,1};

	// Top and bottom rows of the board.
	string caprow = "           ||         ||           ";

	// Side buffer
	string sp = "  ";

	// Sections of vertical bars
	string vbar = "||";

	// Horizontal bar
	string hbar = "  -------------------------------  ";

	// Definition of game sprites (space, X, O)
	string sprite[3][4] = {
			"         ","         ","         ","         ",
			"  xx xx  ","   xxx   ","   xxx   ","  xx xx  ",
			"   o o   ","  o   o  ","  o   o  ","   o o   "};



	cout << caprow << endl;	// o/p top row

	// top row of TTT board
	for (int i = 0; i < 4; i++)	// looping over rows in sprites
	{
		cout << sp;
		cout << sprite[board[0][0]][i];
		cout << vbar;
		cout << sprite[board[0][1]][i];
		cout << vbar;
		cout << sprite[board[0][2]][i];
		cout << sp;
		cout << endl;
	}

	cout << hbar << endl;

	// middle row of TTT board
	for (int i = 0; i < 4; i++)	// looping over rows in sprites
	{
		cout << sp;
		cout << sprite[board[1][0]][i];
		cout << vbar;
		cout << sprite[board[1][1]][i];
		cout << vbar;
		cout << sprite[board[1][2]][i];
		cout << sp;
		cout << endl;
	}

	cout << hbar << endl;

	// bottom row of TTT board
	for (int i = 0; i < 4; i++)	// looping over rows in sprites
	{
		cout << sp;
		cout << sprite[board[2][0]][i];
		cout << vbar;
		cout << sprite[board[2][1]][i];
		cout << vbar;
		cout << sprite[board[2][2]][i];
		cout << sp;
		cout << endl;
	}

	cout << caprow << endl;	// o/p bottom row


	return 0;
}
