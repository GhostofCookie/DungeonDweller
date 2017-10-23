CC = g++
CCFLAGS = -Wall -std=c++11 -g
OBJS = puzzleMain.o Menu.o hanoi.o 

## targets and prerequisites
.PHONY : all
all : puzzleMain

puzzleMain : $(OBJS)
	$(CC) $^ -o $@

# default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

## generate the prerequisites and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean:
	rm -f *.o
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
