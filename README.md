# minisweeper
Minesweeper Project ECEN 1310

Minisweeper is a single player game of minesweeper written in C.
The computer will start by randomly arranging “bombs” on a square board (this arrangement will not be visible the player) and the player will attempt to reveal squares not occupied by a bomb. These cells will reveal the number of bombs that touch that cell, including diagonally, and will be a number between 0 and, at most, 8. The player wins if he/she opens all the cells not occupied by bombs and the computer wins if the player opens a location occupied by a bomb. 
