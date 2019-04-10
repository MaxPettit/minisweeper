#include <stdio.h>
#include <stdlib.h>

#include "minesweeper.h"

typedef struct _cell cell;

struct _cell {
  int val;
  int vis;
};

struct _board {
  int side;
  cell * data; 
  int bombs;
  int cleanCells;
};

static int getVal(board const *bd, int row, int col){
}

static int setVal(board *bd, int row, int col, int val){
}

static int getVis(board const *bd, int row, int col){
}

static int setVis(board *bd, int row, int col, int vis){
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
  int i, bombs, cleanC, len;
  board * b;
  //something that sets values len and bombs from mode

  cleanC = len * len - bombs;
  
  b = malloc(sizeof(board));
  if(!b) return NULL;

  b->bombs = bombs;
  b->side = len;
  b->cleanCells = cleanC;

  b->data = malloc(len*len*sizeof(cell));
  if(!b->data){
    free(b);
    return NULL;
  }
  //set values to 0 and vis to something
  for(i = 0; i < len*len; i++){
    b->data[i].val = 0; //???
    b->data[i].vis = 0; //???
  }
}

board * bombArrangement(board * blank_bd){
}

board * populateCells(board * bomb_bd){
}

int printBoard(board * startB){
}

int revealCell(int row, int col){
}
