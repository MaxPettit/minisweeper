#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "minesweeper.h"

int main(void){
  board *b;
  int mode = 1, err;

  b = newBoard(mode);
  err = printBoard(b); assert(!err);
  return 0;
}
