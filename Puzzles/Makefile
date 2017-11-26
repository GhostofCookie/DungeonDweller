CC = g++
CCFLAGS = -Wall -std=c++11 -g #-fprofile-arcs -ftest-coverage
OBJS = Puzzle.o TicTacToe.o Hanoi.o ConnectFour.o CodeCracker.o ../Menu/RiddleMenu.o PuzzleMain.o MemoryMatch.o ../Menu/HanoiMenu.o ../Menu/ConnectFourMenu.o ../Menu/TicTacToeMenu.o ../Menu/MemoryMenu.o ../Screen/Screen.o ../Image/DefaultImg.o ../Image/Image.o ../Menu/Menu.o ../Menu/Menu.o
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
	rm -f *.o *~ .#* *# *.gcno *.gcda

.PHONY : clean-all
clean-all : clean
	rm -f main
