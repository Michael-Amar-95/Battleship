#Battleship - A Single-Player Tactical Game
##Introduction
Battleship is a classic board game that combines strategy and luck. Originally invented in 1931 as a pen-and-paper game, it was later commercialized by Milton Bradley (MB) in 1967 as a board game with plastic pieces.

In the standard version, two players compete, but this implementation is a single-player game, where the player must sink all submarines in the fewest possible moves. If the player hits a submarine, they get a free turn that does not count as a move.

##Game Rules
1. Submarine Placement

*Submarines are placed randomly on a 10x10 grid before the game starts.
*Submarines cannot be moved once the game begins.
*Placement rules:
**Submarines can be placed horizontally or vertically (not diagonally).
**Submarines cannot overlap or touch each other, even diagonally.

2. Submarine Types & Sizes
The game consists of five submarines of varying sizes:

*1 × Size 5
*1 × Size 2
*2 × Size 3
*1 × Size 4

##How the Game Works
The game board is represented by a 10×10 grid implemented as a 2D integer array.
The player selects a cell by choosing a column (letter) and a row (number).
The game responds with one of the following messages:
"Miss" (Water) – No submarine in the selected cell.
"Hit" (Submarine damaged) – A submarine was hit.
The game ends when all submarines are sunk.
After each turn, the program:
Prints the updated game board.
Updates and displays the move count (excluding extra turns from hits).
Checks if the game is over and, if so, prints the total number of moves taken.



