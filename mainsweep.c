#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "minesweeper.h"

int main(int argc, char *argv[]){
  board *b;
  char c;
  int mode, err, newGame = 1, ret,col, r;
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

    while(1){
      ret=0;
      ret = scanf("%c",&c);
      if(ret==1){ 
      col = (c - 'a')%26 +1;
      ret= scanf("%d",&r);
      if(ret==1){
      if(r <= 0 || col < 1 || r > mode + 5|| col > mode + 5){
	printf("Try again\n");
      }
      err = revealCell(b, r, col);
      if(err == 2) break;
      }
      }
    }
    //play again newGame = 1;
  }
  
  deleteBoard(b);
  return 0;
}
