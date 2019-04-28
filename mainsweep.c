#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

#include "minesweeper.h"

int main(int argc, char *argv[]){
  board *b;
  int mode, err, newGame = 1;
  mode = 1;
  srand(time(0));

  err = parseArgs(argc, argv, &mode);
  if(err) return -1;

  while(newGame == 1){
    newGame = 0;
    
    b = newBoard(mode);
    b = bombArrangement(b,mode);
    b = populateCells(b);
    err = printBoard(b); assert(!err);
    mode = readCell(b);
    if(mode) newGame = 1;
  }
  
  deleteBoard(b);
  return 0;
}
