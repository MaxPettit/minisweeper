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

static void setVal(board *bd, int row, int col, int val){
	bd->data[(col-1)*bd->side+row-1].val=val;
}

static int getVis(board const *bd, int row, int col){
  return bd->data[(col-1) * bd->side + row -1].vis;
}

static void setVis(board *bd, int row, int col, int vis){
	bd->data[(col-1) * bd->side + row -1].vis=vis;
}

static void endWin(){
// 	final submission
}

static void endLoss(){
// 	final submission
}

static void revealZero(board *bd, int row, int col){
  int i, j, t, rSt, rEnd, cSt, cEnd;
  
  rSt = row-1;
  cSt = col-1;
  rEnd = row + 1;
  cEnd = col + 1;
  
  setVis(bd, row, col, 1);
  bd->cleanCells--;
  
  if(row == 1) rSt = row;
  if(col == 1) cSt = col;
  if(row == bd->side) rEnd = row;
  if(col == bd->side) cEnd = col;
  
  for(i = rSt; i <= rEnd; i++){
    for(j = cSt; j <= cEnd; j++){
      if(!getVis(bd, i, j)){
	t = getVal(bd, i, j);
	if(t == 0) revealZero(bd, i, j);
	else{
	  setVis(bd, i, j, 1);
	  bd->cleanCells--;
	}
      }
    }
  }
}

void printUsage(){
    printf("\n please say 'easy', 'medium', or 'hard' with the name of program to use or type 'instructions' for instructions\n");
}

int parseArgs(int argc, char *argv[],board * b,int *mode){
  int parseArgs(int argc, char *argv[], int *mode){
  int err;
  if(argc != 2){
    printUsage();
    return -1;
  }
  else if((err = strcmp("easy", argv[1]) == 0)){
    *mode = 1;
    return 0;
  }
  else if((err = strcmp("medium", argv[1]) == 0)){
    *mode = 2;
    return 0;
  }
  else if((err = strcmp("hard",argv[1]) == 0)){
    *mode = 3;
    return 0;
  }
  else if((err = strcmp("instructions", argv[1]) == 0)){
    printf("Type cell number to clear a space.Columns are letters and numbers are rows. If the space is not a bomb, then it will have a number saying how many bombs are near it. If you hit a bomb, you lose. You win by clearing every space that is not a bomb.\n");
    return 0;
  }
  else{
    printUsage();
    return -1;
  }
}
 
void deleteBoard(board *bd){
	if(bd){
		free(bd->data);
		free(bd);
	}
}
		    
board * newBoard(int mode){
  int i, bombs, cleanC, len;
  board * b;
	
  if(mode == 1){ //all of these #'s are just placeholders
    len = 6;
    bombs = 6;
  } else if(mode == 2){
    len = 7;
    bombs = 12;
  } else if(mode == 3){
    len = 8;
    bombs = 18;
  }

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
	
  for(i = 0; i < len*len; i++){
    b->data[i].val = 0; 
    b->data[i].vis = 0; 
  }
  return b;
}

board * bombArrangement(board * blank_bd, int mode){
	if(!blank_bd) return NULL;
	int numBombs, i;
	srand(time(0));
	if(mode==1)numBombs=5;
	if(mode == 2) numBombs = 6;
	if(mode == 3) numBombs = 7;
	for(i=0;i<numBombs;i++){
		int row=(rand()%(blank_bd->side)+1);
		int col=(rand()%(blank_bd->side)+1);
		if(getVal(blank_bd,row,col)==-1) i=i-1; 
		else setVal(blank_bd,row,col,-1);
	}
	return blank_bd;
}

board * populateCells(board * bomb_bd){
  int row,col,cnt;
  cnt=0;
  for(row=1;row<=bomb_bd->side;row++){
    for(col=1;row<=bomb_bd->side;col++){
      cnt=0;
      if(row==bomb_bd->side){
	if(getVal(bomb_bd,row,col+1)==-1) //if this fails because there is no check for 
	  cnt++;
	if(getVal(bomb_bd,row-1,col)==-1)
	  cnt++;
	if(getVal(bomb_bd,row,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col+1)==-1)
	  cnt++;
      }else if(col==bomb_bd->side){
	if(getVal(bomb_bd,row+1,col)==-1) //checks if bombs are anywhere around spot
	  cnt++;
	if(getVal(bomb_bd,row-1,col)==-1)
	  cnt++;
	if(getVal(bomb_bd,row,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row+1,col-1)==-1)
	  cnt++;
      }else if(col==1&&row==1){
	if(getVal(bomb_bd,row,col+1)==-1) //if this fails because there is no check for 
	  cnt++;
	if(getVal(bomb_bd,row+1,col)==-1) //checks if bombs are anywhere around spot
	  cnt++;
	if(getVal(bomb_bd,row+1,col+1)==-1)
	  cnt++;
      }else if(col==bomb_bd->side&&row==1){
	if(getVal(bomb_bd,row+1,col)==-1) //checks if bombs are anywhere around spot
	  cnt++;
	if(getVal(bomb_bd,row,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row+1,col-1)==-1)
	  cnt++;
      }else if(col==bomb_bd->side&&row==bomb_bd->side){
	if(getVal(bomb_bd,row-1,col)==-1)
	  cnt++;
	if(getVal(bomb_bd,row,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col-1)==-1)
	  cnt++;
      }else if(col==1&&row==bomb_bd->side){
	if(getVal(bomb_bd,row,col+1)==-1) //if this fails because there is no check for 
	  cnt++;
	if(getVal(bomb_bd,row-1,col)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col+1)==-1)
	  cnt++;
      }else if(row==1){
	if(getVal(bomb_bd,row,col+1)==-1) //if this fails because there is no check for 
	  cnt++;
	if(getVal(bomb_bd,row+1,col)==-1) //checks if bombs are anywhere around spot
	  cnt++;
	if(getVal(bomb_bd,row+1,col+1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row+1,col-1)==-1)
	  cnt++;
      }else if(col==1){
	if(getVal(bomb_bd,row,col+1)==-1) //if this fails because there is no check for 
	  cnt++;
	if(getVal(bomb_bd,row+1,col)==-1) //checks if bombs are anywhere around spot
	  cnt++;
	if(getVal(bomb_bd,row+1,col+1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col+1)==-1)
	  cnt++;
      }else {
	if(getVal(bomb_bd,row,col+1)==-1) //if this fails because there is no check for 
	  cnt++;
	if(getVal(bomb_bd,row+1,col)==-1) //checks if bombs are anywhere around spot
	  cnt++;
	if(getVal(bomb_bd,row+1,col+1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col)==-1)
	  cnt++;
	if(getVal(bomb_bd,row,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col-1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row-1,col+1)==-1)
	  cnt++;
	if(getVal(bomb_bd,row+1,col-1)==-1)
	  cnt++;
      }
	if(getVal(bomb_bd,row,col)!=-1)
      setVal(bomb_bd,row,col,cnt);
    }
  }
  return bomb_bd;
}

int printBoard(board const * bd){
  int row, col, t;

  if(!bd) return -1;
  for(int i = 1; i <= bd->side; i++)
    printf("%3c", (i%26+'a'-1));
  printf("\n");
  for(row = 1; row <= bd->side; row++){
    for(col = 1; col <= bd->side; col++){
      if(getVis(bd, row, col)){
	t = getVal(bd, row, col);
	if(t >= 0) printf("%3d", t);
	else printf("  X");
      }
       else printf("  ~");
    }
    printf("%3d\n", row);
  }
  return 0;
}

int revealCell(board *bd, int row, int col){
  if(!bd) return -1;
  if(row < 0 || col < 0 || row > bd->side || col > bd->side) return -1;
  int t, err = 0;
  
  setVis(bd, row, col, 1);
  t = getVal(bd, row, col);
  printf("\n");
  if(t < 0) endLoss();
  else if(t > 0) bd->cleanCells--;
  else revealZero(bd, row, col);
  
  if(bd->cleanCells == 0) endWin();
  
  err = printBoard(bd);

  return err;
}
