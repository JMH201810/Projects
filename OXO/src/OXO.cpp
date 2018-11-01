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



// Check whether a player has won.
bool CheckWin(int bd[3][3], int player)
{
	bool playerWins = false;

	// Check rows
	for (int r = 0; r < 3; r++)
	{
		if (bd[0][r] == player && bd[1][r] == player && bd[2][r] == player)
		{
			playerWins = true;
			break;
		}
	}

	if (!playerWins)
	{
		// Check columns
		for (int c = 0; c < 3; c++)
		{
			if (bd[c][0] == player && bd[c][1] == player && bd[c][2] == player)
			{
				playerWins = true;
				break;
			}
		}
	}

	if (!playerWins)
	{
		// Check NW - SE
		if (bd[0][0] == player && bd[1][1] == player && bd[2][2] == player)
		{
			playerWins = true;
		}
	}

	if (!playerWins)
	{
		// Check NE - SW
		if (bd[2][0] == player && bd[1][1] == player && bd[0][2] == player)
		{
			playerWins = true;
		}
	}

	return playerWins;
}

int main() {

	// winner flags
	bool xWins = false, oWins = false;


	// game play model
	int board[3][3] = {0,0,0,0,0,0,0,0,0};

//	// Test case
//	board[0][0] = 1;
//	board[0][1] = 2;
//	board[0][2] = 0;
//	board[1][0] = 0;
//	board[1][1] = 2;
//	board[1][2] = 0;
//	board[2][0] = 1;
//	board[2][1] = 2;
//	board[2][2] = 1;

	DrawBoard(board);


	// Main game play loop
	for (int turn = 0; turn < 9; turn++)	// Maximum of 9 turns in a game.
	{
		int rowChoice, colChoice;	// Player's choice.


		// Even turns: X, odd turns: O
		if (turn % 2 == 0)
		{
			// X's turn

			// Ask for a move and verify that the choice is available.
			do {
				cout << "Enter row, col for X's move: (0-2) (0-2)";
				cin >> rowChoice >> colChoice;
			} while (rowChoice < 0 || rowChoice > 2 || colChoice < 0 || colChoice > 2 || board[rowChoice][colChoice] != 0);


			// Update model
			board[rowChoice][colChoice] = 1;	// X has chosen this location.

			// Redraw the board
			DrawBoard(board);

			// Check whether X has won.
			xWins = CheckWin(board, 1);

			// If X wins, announce it and break out of loop.
			if (xWins)
			{
				cout << "X wins." << endl;
				break;
			}
		}
		else
		{
			// O's turn

			// Ask for a move and verify that the choice is available.
			do {
				cout << "Enter row, col for O's move: (0-2) (0-2)";
				cin >> rowChoice >> colChoice;
			} while (rowChoice < 0 || rowChoice > 2 || colChoice < 0 || colChoice > 2 || board[rowChoice][colChoice] != 0);


			// Update model
			board[rowChoice][colChoice] = 2;	// O has chosen this location.

			// Redraw the board
			DrawBoard(board);

			// Check whether O has won.
			oWins = CheckWin(board, 2);

			// If O wins, announce it and break out of loop.
			if (oWins)
			{
				cout << "O wins." << endl;
				break;
			}
		}

	}


	// If neither X nor O wins, then announce a draw.
	if (!xWins && !oWins)
	{
		cout << "Draw" << endl;
	}

	return 0;
}
