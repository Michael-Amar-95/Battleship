#include <iostream>
#include <stdlib.h>
#include "battleship_dec.h"
using namespace std;

int main()
{
	int numSteps;
	do
	{
		int board[MAX_SIZE][MAX_SIZE];
		int boardWidth = MAX_SIZE;
		int boardHeight = MAX_SIZE;
	    numSteps = 0;
	    initBoard(board, boardHeight, boardWidth);
		initBoats(board, boardWidth, boardHeight);
		playGame(board, boardWidth, boardHeight, numSteps);
	} while (restart(numSteps) == 1);
}


