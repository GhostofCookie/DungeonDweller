CC = g++
CCFLAGS = -Wall -std=c++11 -g -lcppunit -ldl -fprofile-arcs -ftest-coverage
OBJS = TicTacToe.o Hanoi.o ConnectFour.o CodeCracker.o PuzzleMain.o ../Menu/HanoiMenu.o ../Screen/Screen.o ../Image/DefaultImg.o ../Image/Image.o ../Menu/Menu.o ../Menu/Menu.o
.PHONY : all
all : main

main : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

## generate the prerequistes and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :
	rm -f *.o *~ #* .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
