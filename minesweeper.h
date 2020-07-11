#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

typedef struct _board board;

void printUssage();

//char mode would take easy, medium, or hard
int parseArgs(int argc, char *argv[], int *mode);

//frees board off heap at end of game
void deleteBoard(board * bd);

/* creates board filled with 0's.
 * mode will determine size and num bombs */
board * newBoard(int mode);

//randomly arranges bombs
void bombArrangement(board * bd);

//fills in nums
void populateCells(board * bd); 

/* Prints current board
 * Returns -1 if error
 * 0 if else
 */
int printBoard(board const * startB);

/* Prints board with called cell revealed
 * Checks vis value for each cell
 * Returns -1 if error
 * 0 if else
 */
int revealCell(board *bd, int row, int col);

/* Reads user input cell
 * Calls reveal cell if input is valid
 * Returns next mode to play again or zero to quit
 */
int readCell(board *bd);

#endif

