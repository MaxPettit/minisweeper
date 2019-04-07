#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

typedef struct _board board;

//char mode would take easy, medium, or hard
int parseArgs(int argc, char *argv[], char mode[]);

//frees board off heap at end of game
void deleteBoard(board * bd);

//randomly arranges bombs
board * bombArrangement(board * blank_board);

//fills in nums
board * populateCells(board * bomb_board); 

/* Prints a board full of ~
 * Returns -1 if error
 * 0 if else
 */
int printNewBoard(board * startB);

/* Prints new board with called cell revealed
 * Returns -1 if error
 * 0 if else
 */
int revealCell(int row, int col);

#endif
