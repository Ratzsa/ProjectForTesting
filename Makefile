PROG=main.exe
CC=gcc
CFLAGS=-g -Wall -Werror
DEPS = systemfunctions.h shapes.h checkinputs.h calculator.h gamecode.h
OBJ = main.o systemfunctions.o shapes.o checkinputs.o calculator.o gamecode.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)