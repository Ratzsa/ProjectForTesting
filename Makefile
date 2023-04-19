PROG = programmet.exe
CFLAGS = -Wall -Werror -g
SOURCES = main.c calculator.c checkinputs.c gamecode.c gamemenu.c shapes.c systemfunctions.c
DEPS = calculator.h checkinputs.h gamecode.h gamemenu.h shapes.h systemfunctions.h
CC = gcc
DEBUG?=1
ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR = bin/debug
	PROG = programmet-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR = bin/release
endif

OBJS = $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@del /q $(PROG)
	@del /q "$(OUTPUTDIR)"

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

.PHONY: clean