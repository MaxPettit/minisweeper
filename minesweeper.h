#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

typedef struct _board board;

void printUsage();

//char mode would take easy, medium, or hard
int parseArgs(int argc, char *argv[], int * mode);

//frees board off heap at end of game
void deleteBoard(board * bd);

/* creates board filled with 0's.
 * mode will determine size and num bombs */
board * newBoard(int mode);

//randomly arranges bombs
board * bombArrangement(board * blank_bd,int mode);

//fills in nums
board * populateCells(board * bomb_bd); 

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
int revealCell(board * bd, int row, int col);

#endif

/* Statics:
 * GetVal SetVal GetVis SetVis
 * Get Result (when cell is called, test if bomb or not)
 * Print Result Message
 * 
 *Idea:
 *Create a matrix of other objects where each object has 2 values
 *      Value, and 1/0 for hidden or visible. Like "point" from quiz
 */
#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

typedef struct _board board;

void printUssage();

//char mode would take easy, medium, or hard
int parseArgs(int argc, char *argv[], char mode[]);

//frees board off heap at end of game
void deleteBoard(board * bd);

/* creates board filled with 0's.
 * mode will determine size and num bombs */
board * newBoard(int mode);

//randomly arranges bombs
board * bombArrangement(board * blank_bd, int mode);

//fills in nums
board * populateCells(board * bomb_bd); 

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

#endif

/* Statics:
 * GetVal SetVal GetVis SetVis
 * Get Result (when cell is called, test if bomb or not)
 * Print Result Message
 * 
 *Idea:
 *Create a matrix of other objects where each object has 2 values
 *      Value, and 1/0 for hidden or visible. Like "point" from quiz
 */
