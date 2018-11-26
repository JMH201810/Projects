//============================================================================
// Name        : OXOb.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void DrawBoard(int bd[3][3])
{
	// Draw the board, using the input game model bd.
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
		cout << sprite[bd[0][0]][i];
		cout << vbar;
		cout << sprite[bd[0][1]][i];
		cout << vbar;
		cout << sprite[bd[0][2]][i];
		cout << sp;
		cout << endl;
	}

	cout << hbar << endl;

	// middle row of TTT board
	for (int i = 0; i < 4; i++)	// looping over rows in sprites
	{
		cout << sp;
		cout << sprite[bd[1][0]][i];
		cout << vbar;
		cout << sprite[bd[1][1]][i];
		cout << vbar;
		cout << sprite[bd[1][2]][i];
		cout << sp;
		cout << endl;
	}

	cout << hbar << endl;

	// bottom row of TTT board
	for (int i = 0; i < 4; i++)	// looping over rows in sprites
	{
		cout << sp;
		cout << sprite[bd[2][0]][i];
		cout << vbar;
		cout << sprite[bd[2][1]][i];
		cout << vbar;
		cout << sprite[bd[2][2]][i];
		cout << sp;
		cout << endl;
	}

	cout << caprow << endl;	// o/p bottom row

}



bool CheckWin(int bd[3][3], int player)
{
	bool playerWins = false;

	// Check the rows for three occurrences of player
	// If found, set playerWins = true
	for (int row = 0; row < 3; row++)
	{
		if (bd[row][0]==player && bd[row][1]==player && bd[row][2]==player)
		{
			playerWins = true;
			break;
		}
	}


	// If playerWins == false, then check the columns for three
	// occurrences of player.
	// If found, set playerWins = true
	if (!playerWins)
	{
		// add code here...
	}



	// If playerWins == false, then check the NW-SE diagonal for
	// three occurrences of player.
	// If found, set playerWins = true
	if (!playerWins)
	{
		// add code here...
	}



	// If playerWins == false, then check the NE-SW diagonal for
	// three occurrences of player.
	// If found, set playerWins = true
	if (!playerWins)
	{
		// add code here...
	}


	return playerWins;
}



int main() {
	bool xWins = false, oWins = false;


	// initialize the game model
	int board[3][3] = {
			0,0,0,
			0,0,0,
			0,0,0};

	// draw the board
	DrawBoard(board);

	for (int turn = 0; turn < 9; turn++)
	{
		if (turn % 2 == 0)
		{
			// X's turn

			// Ask for row, column positions for X's move
			// Keep asking while row < 0 or row > 2 or column < 0 or column > 2 or
			// board[row][column] != 0.
			// Use a do-while loop for this.
			// Add code here...



			// Update the model.
			// board[row][column] = 1
			// Add code here...


			// Redraw the board with the new move.
			DrawBoard(board);


			// Check whether X won.
			xWins = CheckWin(board, 1);


			// if X wins, announce it and leave the loop
			if (xWins)
			{
				cout << "X wins" << endl;
				break;
			}
		}
		else
		{
			// O's turn

			// Add code here...
		}
	}


	if (!xWins && !oWins)
	{
		cout << "Draw" << endl;
	}


	return 0;
}
