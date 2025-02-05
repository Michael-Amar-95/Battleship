#ifndef BATTLESHIP_H
#define BATTLESHIP_H


#define MAX_SIZE 10
#define NUM_BOATS 5
using namespace std;

enum { VERTICAL , HORIZONTAL };
enum { WATER_UNBOMBED = 0, WATER_BOMBED = 1, SHIP_UNBOMBED = 2, SHIP_BOMBED = 3 };
const char display[] = { 'X', '-', 'X', '*' };
const int boats[] = { 5,4,3,3,2 };//boats are placed from largest to smallest

//declaration of functions
void initBoard(int board[MAX_SIZE][MAX_SIZE], int boardHeight, int boardWidth);
void printBoard(const int board[MAX_SIZE][MAX_SIZE], int boardHeight, int boardWidth);
void initBoats(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight);
bool checkLocation(int board[MAX_SIZE][MAX_SIZE], int direction, int x_coord, int y_coord, int boatSize);
bool surroundedVertical(int board[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord, int size);
bool surroundedHorizontal(int board[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord, int size);
bool checkingcells(int board[MAX_SIZE][MAX_SIZE], int x_coord, int y_coord, int checkLines, int checkColumns);
void placeBoat(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int direction, int x_coord, int y_coord, int boats);
void playGame(int board[MAX_SIZE][MAX_SIZE], int boardWidth, int boardHeight, int &numSteps);
int coordinates(char letter, int number);
int convert(char letter);
void target(int board[MAX_SIZE][MAX_SIZE], int line, int column, int& numSteps);
int counter(int board[MAX_SIZE][MAX_SIZE]);
int restart(int& numSteps);
#endif //BATTLESHIP_H