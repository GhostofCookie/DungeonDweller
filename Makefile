CC = g++
CCFLAGS = -Wall -std=c++11 -g  
OBJS = main.o Menu.o Hanoi.o TicTacToe.o MemoryMatch.o ConnectFour.o 
SRC := $(shell find $(SOURCEDIR) -name '*.cpp')

## targets and prerequisites
.PHONY : all
all : main

main : $(OBJS)
	$(CC) $^ -o $(CCFLAGS) $<

# default rule for compiling .cc to .o
$%.o : $(SRC)
	$(CC) -c $(CCFLAGS) $<

# generate the prerequisites and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

# include the generated prerequisite file
include .prereq

.PHONY : clean
clean:
	rm -f *.o
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
