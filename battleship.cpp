#include <iostream>
#include <stdlib.h>
#include "battleship_dec.h"

//this function initial the board by putting  zero in each cell 
void initBoard(int board[MAX_SIZE][MAX_SIZE], int boardHeight, int boardWidth)
{
	for (int boardHeight = 0; boardHeight < MAX_SIZE; boardHeight++)
	{
		for (int boardWidth = 0; boardWidth < MAX_SIZE; boardWidth++)
		{
			board[boardHeight][boardWidth] = WATER_UNBOMBED;
		}
	}
}

//this function print the board by char
void printBoard(const int board[MAX_SIZE][MAX_SIZE], int boardHeight, int boardWidth)
{
	for (int boardHeight = 0; boardHeight < MAX_SIZE; boardHeight++)
	{
		for (int boardWidth = 0; boardWidth < MAX_SIZE; boardWidth++)
		{
			cout << display[board[boardHeight][boardWidth]];
		}
		cout << endl;
	}
	cout << endl;
}

// this function check the location and put the boats in the board
void initBoats(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight)
{
	int boatNum; //number of boat
	boatNum = 0; 

	while (boatNum < NUM_BOATS)
	{
		//First choose vertical or horizontal
		int direction = rand() % 2;
		//random x-coordinate
		int x_coord = rand() % MAX_SIZE;
		//random y-coordinate
		int y_coord = rand() % MAX_SIZE;
		if (checkLocation(board, direction, x_coord, y_coord, boats[boatNum]))
		{
			placeBoat(board, boardWidth, boardHeight, direction, x_coord, y_coord, boats[boatNum]);
			boatNum++;
		}

	}
}
//check the direction of the boat
bool checkLocation(int board[MAX_SIZE][MAX_SIZE], int direction, int x_coord, int y_coord, int boats)
{
	if (direction == VERTICAL)
	{
		return surroundedVertical(board, x_coord, y_coord, boats);	 
	}
	else //(direction == HORIZONTAL)
	{
		return surroundedHorizontal(board, x_coord, y_coord, boats);
	}
}

/*check if the area is good to place the boat. check if the boats are in boundary
and if there are no boats surrounding the area. When the boat is horizontal*/
bool surroundedHorizontal(int board[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord, int boats)
{
	if ((y_coord + (boats - 1)) >= MAX_SIZE) //check if the boats are in the boundary of the board
	{
		return false;
	}

	int checkLines = 3; // scan lines
	int checkColums = (boats + 2); // scan columns

	if ((x_coord == 0) || (x_coord == 9)) // check if the boat placed in margin
	{
		if (x_coord ==0)
		{
	        x_coord ++;
		}
	  checkLines = 2;
	}
	if (y_coord == 0)
	{
		y_coord++;
		checkColums = checkColums - 1;
	}
		return checkingcells(board, x_coord, y_coord, checkLines, checkColums);
}

/*check if the area is good to place the boat. check if the boats are in boundary
and if there are no boats surrounding the area. When the boat is vertical*/
bool surroundedVertical(int board[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord, int boats)
{
	if ((x_coord + (boats - 1)) >= MAX_SIZE) //check if the boats are in the boundary of the board
	{
		return false;
	}

	int checkColumns = 3; // scan columns
	int checkLines = boats + 2; // scan lines
	
	if ((y_coord == 0) || (y_coord == 9)) // check if the boat placed in margin
	{
		if (y_coord == 0)
		{
		   y_coord ++;
		}
		checkColumns = 2;
	}
	if (x_coord == 0)
	{
		x_coord++;
		checkLines = checkLines - 1;
	}
	return checkingcells(board, x_coord, y_coord, checkLines, checkColumns);
}

//check if the boats Surrounded by empty cells
bool checkingcells(int board[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord, int checkLines, int checkColumns)
{
	int xcoord = (x_coord - 1); //start the scan one cell above
	for (int x = 0; x < checkLines; x++)
	{
		int ycoord = (y_coord - 1); //start the scan one cell left
		for (int y = 0; y < checkColumns; y++)
		{
			if (ycoord < 9) //make sure that the scan will stop in the margin if it will get to there
			{
				if (board[xcoord][ycoord] == 0)
				{
					ycoord++;
				}
				else
				{
					return false;
				}
			}
			else 
			{
				break;
			}
		}
		if (xcoord < 9) //make sure that the scan will stop in the margin if it will get to there
		{
			xcoord++;
		}
		else
		{
			break;
		}
	}
	return true;
}

//this function put the boats in the board
void placeBoat( int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int direction, int x_coord, int y_coord, int boats)
{
	if (direction == 1)
	{
		for (int i = 0; i < boats; i++)
		{
			board[x_coord][y_coord] = 2;
			y_coord++;
		}
	}
	if (direction == 0)
	{
		for (int i = 0; i < boats; i++)
		{
			board[x_coord][y_coord] = 2;
			x_coord++;
		}
	}
 }

//This function start the game
void playGame(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int& numSteps)
{
	int number; //line
	char letter; //column
	int column;
	printBoard(board, boardHeight, boardWidth); //print the board before the game start

	do
	{
		cout << "Please enter coordinates of target:\n";
		cin >> letter >> number;
		cout << endl;

		while (coordinates(letter, number) == 0) // if the input is incorrect he ask to send new input
		{
			cout << "Target does not exist. Please try again.\n";
			cout << "Please enter coordinates of target:\n";
			cin >> letter >> number;
			cout << "\n";
		}
		column = convert(letter); //conver the letter to number
		target(board, number, column, numSteps); //check the input in the board
	} while (counter(board) < 17);
}

//checking the coordinates
int coordinates(char letter, int number)
{
	if ((1 <= number) && (number <= 10))
	{
		if ((('a' <= int(letter)) && (int(letter) <= 'j')) || (('A' <= int(letter)) && (int(letter) <= 'J')))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

//convert letter to number
int convert(char letter)
{
	int x;
	if (('A' <= letter) && (letter < 'a'))
	{
		x = int(letter) - 'A';
	}
	else
	{
		x = int(letter) - 'a';
	}
	return x;
}


//checking the target
void target(int board[MAX_SIZE][MAX_SIZE], int line, int column, int& numSteps)
{
	switch (board[line - 1][column]) //split the the input to cases
	{
	case WATER_UNBOMBED: board[line - 1][column] = WATER_BOMBED; printBoard(board, 10, 10);
		numSteps++;
		cout << "You have missed the target.\n";
		cout << "Number of steps:" << numSteps << endl;
		break;
	case WATER_BOMBED: cout << endl << "Target has already been attacked. Please try again.\n";
		break;
	case SHIP_UNBOMBED: board[line - 1][column] = SHIP_BOMBED; printBoard(board, 10, 10);
		cout << "Hit!\n";
		cout << "Number of steps:" << numSteps << endl;
		break;
	case SHIP_BOMBED: cout << endl  << "Target has already been attacked. Please try again.\n";
		break;
	}
}

//counte the hits in the board
int counter(int board[MAX_SIZE][MAX_SIZE])
{
	int counter = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			if (board[i][j] == 3) //check if the cells have a boat that had boombed
			{
				counter++;
			}
		}
	}
	return counter;
}

//This function ask the user if he want to play again and do like he said
int restart(int& numSteps)
{
	int invalidAnswer;
	char answer;
	do {
		cout << "Game is over!\n";
		cout << "It took you " << numSteps << " turns to complete your mission. Do you want to play again? (y/n)\n";
		cout << endl;
		cin >> answer;
		switch (answer)
		{
		case 'Y':
		case 'y':
			cout << endl;
			return 1;
			break;
		case 'N':
		case 'n':
			return 0;
			break;
		default: cout << "your answer is invalid";
			invalidAnswer = 2;
		}
	} while (invalidAnswer == 2);
	return 0;
}
