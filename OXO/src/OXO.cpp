//============================================================================
// Name        : OXO.cpp
// Author      : J. M. Hinckley
// Version     : 1.0
// Copyright   : (c) 2018
// Description : Two-player tic tac toe game
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void DrawBoard(int bd[3][3])
{
	// Draw the game board, reflecting the current state of play.
	// Input is bd[3][3], the current game play model.
	// In this array, 0 signifies space, 1 signifies X, 2 signifies O.

	// Define the game sprites (space, X, O)
	string sprite[3][4] = {		// first index: type of sprite, second index: row
			"         ","         ","         ","         ",	// space
			"  XX XX  ","   XXX   ","   XXX   ","  XX XX  ",	// X
			"   O O   ","  O   O  ","  O   O  ","   O O   "};	// O


	// Top and bottom rows of board.
	string caprow = "           ||         ||           ";


	// Spaces at left and right sides.
	string sp = "  ";


	// Sections of the vertical bars.
	string vbar = "||";


	// Horizontal bar
	string hbar = "-----------------------------------";


	// Draw the board.

	// Scroll to clear the console window.
	for (int i = 0; i < 50; i++) cout << endl;


	// top row
	cout << caprow << endl;


	// Loop over game board rows
	for (int gamerow = 0; gamerow < 3; gamerow++)
	{

		// Loop over sprite row
		for (int r = 0; r < 4; r++)
		{
			cout << sp   << sprite[bd[gamerow][0]][r];
			cout << vbar << sprite[bd[gamerow][1]][r];
			cout << vbar << sprite[bd[gamerow][2]][r];
			cout << sp   << endl;
		}


		// After first two game rows, output the horizontal line
		if (gamerow < 2)
		{
			cout << hbar << endl;
		}
	}

	// bottom row
	cout << caprow << endl;
}

int main() {

	// game play model
	int board[3][3] = {0,0,0,0,0,0,0,0,0};

	// Test case
	board[0][0] = 1;
	board[0][1] = 2;
	board[0][2] = 0;
	board[1][0] = 0;
	board[1][1] = 2;
	board[1][2] = 0;
	board[2][0] = 1;
	board[2][1] = 2;
	board[2][2] = 1;

	DrawBoard(board);


	return 0;
}
