CC=gcc
target=JGAME_bin

SRSC=main.c\
	 JGame.cpp

OBJ=$(SRSC:.c=.o)

$(target):$(OBJ)
	$(CC) -o $(target) $(OBJ)

.PHONY:clean
clean:
