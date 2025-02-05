# Battleship - A Single-Player Tactical Game

## Introduction
**Battleship** is a classic board game that combines strategy and luck. Originally invented in 1931 as a pen-and-paper game, it was later commercialized by Milton Bradley (MB) in 1967 as a board game with plastic pieces. This implementation is a single-player version where the goal is to sink all submarines in the fewest possible moves. If the player hits a submarine, they receive a free turn that does not count as a move.

## Game Rules
* Submarines are placed randomly on a **10x10 grid** before the game starts.
* Submarines **cannot be moved** once placed.
* Submarines **must be placed vertically or horizontally**, not diagonally.
* Submarines **cannot overlap or touch** each other, even diagonally.
* The game consists of **five submarines**:
  * 1 submarine of size **five**
  * 1 submarine of size **two**
  * 2 submarines of size **three**
  * 1 submarine of size **four**

## Gameplay
* The player selects a cell by choosing a **column (letter) and a row (number)**.
* The program responds with one of the following:
  * **"Miss"** - The selected cell contains water (no submarine).
  * **"Hit"** - A submarine in the selected cell has been damaged.
* The game continues until **all submarines are sunk**.

## Board Representation
The game board is implemented as a **2D integer array**, where each cell can be in one of four states:
* **0** - Unchecked water (`UNBOMBED_WATER`)
* **1** - Checked water (missed shot) (`BOMBED_WATER`)
* **2** - Unchecked submarine (`UNBOMBED_SHIP`)
* **3** - Hit submarine (`BOMBED_SHIP`)

### Display Symbols
When printing the board, the following symbols are used:
* **'X'** - Undiscovered cell
* **'+'** - Hit submarine
* **'-'** - Checked water (missed shot)

## Game Progression
* After each move, the game **prints the updated board**.
* The game **updates the number of moves**, excluding extra turns gained from hits.
* If all submarines are sunk, the game **prints the total number of moves taken** to achieve victory.

