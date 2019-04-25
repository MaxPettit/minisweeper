#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "minesweeper.h"

int main(int argc, char *argv[]){
  board *b;
  int mode, err, newGame = 1, ret;
  mode = 1;
  sran(time(0));

  err = parseArgs(argc, argv, &mode);
  if(err) return -1;

  while(newGame == 1){
    newGame = 0;
    
    b = newBoard(mode);
    b = bombArrangement(b, mode);
    b = populateCells(b);
    err = printBoard(b); assert(!err);

    while(1){
      ret = scanf();
      col = (c - 'a')%26 +1;
      err = revealCell(b, r, col)
      if(err == 2) break;
    }
    //play again newGame = 1;
  };
  
  deleteBoard(b);
  return 0;
}
