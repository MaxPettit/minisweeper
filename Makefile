# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
PROG = mainsweep
SRC = $(PROG).c minesweeper.c
HDR = minesweeper.h
OBJ = $(SRC:.c=.o)

# Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)
