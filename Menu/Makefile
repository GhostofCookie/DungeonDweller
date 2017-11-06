CC = g++
CCFLAGS = -Wall -std=c++11
OBJS = menuTest.o Menu.o MainMenu.o ExploreMenu.o FightMenu.o TradeMenu.o DialogueMenu.o CharacterMenu.o HanoiMenu.o MemoryMenu.o RiddleMenu.o TicTacToeMenu.o ConnectFourMenu.o

## targets and prerequisites
.PHONY : all
all : menuTest

menuTest : $(OBJS)
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
