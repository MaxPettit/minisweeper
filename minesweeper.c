#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  return bd->data[(col-1) * bd->side + row -1].val;
}

static int setVal(board *bd, int row, int col, int val){
}

static int getVis(board const *bd, int row, int col){
  return bd->data[(col-1) * bd->side + row -1].vis;
}

static int setVis(board *bd, int row, int col, int vis){
}

static void printWin(){
}

static void printLoss(){
}

void printUsage(){
    printf("\n please say 'easy', 'medium', or 'hard' with the name of program to use or type 'instructions' for instructions\n");
}

int parseArgs(int argc, char *argv[],board * b){
  int err;
  if(argc<2){
    printUsage;
    return -1;
  }
  else if(argc>2){
     printUsage;
     return -1;
  }else if((err=strcmp("easy",argv[1])==0){
      b=newBoard(1);
      if(!b) return -1;
      else return 0;
    }
    else if((err=strcmp("medium",argv[1])==0){
	b=newBoard(2);
	if(!b) return -1;
	else return 0;
      }
      else if((err=strcmp("hard",argv[1])==0){
	  if(!b) return -1;
	  else return 0;
	} else if((err=strcmp("instructions",argv[1])==0){
        printf("Type cell number to clear a space.Columns are letters and numbers are rows. If the space is not a bomb, then it will have a number saying how many bombs are near it. If you hit a bomb, you lose. You win by clearing every space that is not a bomb.\n");
        return 0;
	else if((err=strcmp("easy",argv[1])!=0){
	    printUsage;
	    return -1;
	  }
	  else if((err=strcmp("medium",argv[1])!=0){
	      printUsage;
	      return -1;
	    }
	    else if((err=strcmp("hard",argv[1])!=0){
		printUsage;
		return -1;
	      }
    else if((err=strcmp("instructions",argv[1]))!=0){
      printUsage;
      return -1;
     }
}

board * newBoard(int mode){
  int i, bombs, cleanC, len;
  board * b;
  //something that sets values len and bombs from mode

  cleanC = len * len - bombs;
  
  b = malloc(sizeof(board));
    return NULL;
  if(!b) return NULL;

  b->bombs = bombs;
  b->side = len;
  b->cleanCells = cleanC;

  b->data = malloc(len*len*sizeof(cell));
  if(!b->data){
    free(b);
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

int printBoard(board const * bd){
  int row, col;

  if(!bd) return -1;

  for(row = 1; row <= bd->side; row++){
    for(col = 1; col <= bd->side; col++){
       if(getVis(bd, row, col)) printf("%d", getVal(bd, row, col)); //mess with the "%d" and "~" to make it pretty
       else printf("~");
    }
    printf("\n");
  }
  return 0;
}

int revealCell(int row, int col){
}
