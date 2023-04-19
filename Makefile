PROG = programmet.exe
CFLAGS = -Wall -Werror -g
SOURCES = main.c calculator.c checkinputs.c gamecode.c gamemenu.c shapes.c systemfunctions.c
CC = gcc
DEBUG?=1
ifeq ($(DEBUG), 1)
	CFLAGS = -Wall -Werror -g
else
	CFLAGS = -Wall -Werror -g
endif
OUTPUTDIR = bin

OBJS = $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@del /q $(PROG)
	@del /q *.o

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

.PHONY: clean