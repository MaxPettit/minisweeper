#include <stdio.h>
#include <stdlib.h>

#include "minesweeper.h"

typedef struct _cell cell;

struct _cell {
  int val;
  int visiblity;
}

struct _board {
  int size;
  cell * data; //???
  int bombs;
  int cleanCells;
};
