#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

typedef struct _board board;

//char mode would take easy, medium, or hard
int parseArgs(int argc, char *argv[], char mode[]);

//frees board off heap at end of game
void deleteBoard(board * bd);

/* creates board filled with 0's.
 * mode will determine size and num bombs */
board * blankBoard(int mode);

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

/* Statics:
 * Get Result (when cell is called, test if bomb or not)
 *      Like getE
 * Print Result Message
 * 
 *Other Ideas:
 *Possibly 2 matrices for each board
 *      1 for true identity (numerical value) and one with 
 *      1/0 for hidden or visible if hidden corresponding element
 *      prints as ~
 *Or can we create a matrix of other objects where each object has 2 values
 *      Value, and 1/0 for hidden or visible.
 */
