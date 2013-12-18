CC=gcc
CFLAGS=-Iinclude
OBJDIR=./obj
OBJ = main.o list.o linkedList.o pokemon.o

vpath %.c src
vpath %.h include

%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

run: main
	@ ./main

clean:
	@ rm -f *.o main