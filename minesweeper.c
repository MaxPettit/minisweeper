#include <stdio.h>
#include <stdlib.h>

#include "minesweeper.h"

typedef struct _cell cell;

struct _cell {
  int val;
  int visiblity;
};

struct _board {
  int size;
  cell * data; //???
  int bombs;
  int cleanCells;
};

static int getVal(board const *bd, int row, int col){
}

static int setVal(board *vd, int row, int col, int val){
}

static int getVis(board const *bd, int row, int col){
}

static int setVis(board *vd, int row, int col, int vis){
}

static void printWin(){
}

static void printLoss(){
}

void printUssage(){
}

int parseArgs(int argc, char *argv[], char mode[]){
}

board * newBoard(int mode){
}

board * bombArrangement(board * blank_board){
}

board * populateCells(board * bomb_board){
}

int printBoard(board * startB){
}

int revealCell(int row, int col){
}
