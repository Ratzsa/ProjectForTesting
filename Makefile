PROG = programmet.exe
TESTPROG = check.exe
CFLAGS = -Wall -Werror -g
SOURCES = main.c calculator.c checkinputs.c gamecode.c gamemenu.c shapes.c systemfunctions.c
# TESTCSOURCES = shapes.c systemfunctions.c checkinputs.c calculator.c gamecode.c
# TESTCPPSOURCES = testshapes.cpp testcalculator.cpp testrps.cpp
DEPS = calculator.h checkinputs.h gamecode.h gamemenu.h shapes.h systemfunctions.h
CC = gcc
DEBUG?=1
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG),1)
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

$(OUTPUTDIR)/%.o: %.cpp $(DEPS)
	g++ -o $@ -c $< -I $(GTEST)

clean:
	@echo Error messages regarding not finding certain files can be safely ignored.
	@del /q "$(PROG)"
	@del /q "$(OUTPUTDIR)"
	@del /q "$(TESTPROG)"

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

$(TESTPROG): $(OUTPUTDIR)/shapes.o $(OUTPUTDIR)/systemfunctions.o $(OUTPUTDIR)/checkinputs.o $(OUTPUTDIR)/calculator.o $(OUTPUTDIR)/gamecode.o $(OUTPUTDIR)/testshapes.o $(OUTPUTDIR)/testcalculator.o $(OUTPUTDIR)/testrps.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTEST) $(LIBGTEST)

test: $(TESTPROG)
	./$(TESTPROG) --gtest_color=yes

.PHONY: clean