PROG = programmet.exe
CFLAGS = -Wall -Werror -g
SOURCES = main.c calculator.c checkinputs.c gamecode.c gamemenu.c shapes.c systemfunctions.c
TESTSOURCES = shapes.c systemfunctions.c checkinputs.c calculator.c gamecode.c testshapes.cpp testcalculator.cpp testrps.cpp
DEPS = calculator.h checkinputs.h gamecode.h gamemenu.h shapes.h systemfunctions.h
CC = gcc
DEBUG?=1
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR = bin/debug
	PROG = programmet-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR = bin/release
endif


OBJS = $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))
TESTOBJS = $(addprefix $(OUTPUTDIR)/,$(TESTSOURCES:.c=.o) $(TESTSOURCES:.cpp=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(OUTPUTDIR)/%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	@del /q "$(PROG)"
	@del /q "$(OUTPUTDIR)"

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

check.exe: shapes.o systemfunctions.o checkinputs.o calculator.o gamecode.o testshapes.o testcalculator.o testrps.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTEST) $(LIBGTEST)

test: check.exe
	./check.exe

.PHONY: clean