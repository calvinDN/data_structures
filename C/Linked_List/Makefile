CC       = gcc
CFLAGS   = -Wall -ansi -pedantic
INCLUDES = -Iinclude
BINDIR   = bin/
SRCDIR   = src/
OBJDIR 	 = obj/
PROGNAME = $(BINDIR)animal
OBJS     = $(OBJDIR)main.o $(OBJDIR)list.o $(OBJDIR)linkedList.o $(OBJDIR)animal.o

all: link

link: animal list linkedList main
	$(CC) -o $(PROGNAME) $(OBJS)

# MUSTDO: this should be replaced by one target and update appropriately
main: $(SRCDIR)main.c
	$(CC) $(CFLAGS) -c $(SRCDIR)main.c -o $(OBJDIR)main.o $(INCLUDES)

linkedList: $(SRCDIR)linkedList.c
	$(CC) $(CFLAGS) -c $(SRCDIR)linkedList.c -o $(OBJDIR)linkedList.o $(INCLUDES)

list: $(SRCDIR)list.c
	$(CC) $(CFLAGS) -c $(SRCDIR)list.c -o $(OBJDIR)list.o $(INCLUDES)

animal: $(SRCDIR)animal.c
	$(CC) $(CFLAGS) -c $(SRCDIR)animal.c -o $(OBJDIR)animal.o $(INCLUDES)

clean:
	@ rm -f $(OBJDIR)*.o
	@ rm -f $(BINDIR)list

run: all
	$(PROGNAME)