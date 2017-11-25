CC = g++
CCFLAGS = -Wall -std=c++11 -g #-fprofile-arcs -ftest-coverage #-lcppunit -ldl 
OBJS = testExplore.o ../Menu/Menu.o ../Menu/MainMenu.o ../Menu/ExploreMenu.o ../Menu/FightMenu.o ../Menu/TradeMenu.o ../Menu/DialogueMenu.o ../Menu/CharacterMenu.o ../Menu/HanoiMenu.o ../Menu/MemoryMenu.o ../Menu/RiddleMenu.o ../Menu/TicTacToeMenu.o ../Menu/ConnectFourMenu.o ../Screen/Screen.o ExploreState.o ../RoomTree/RoomTree.o ../Image/Image.o ../Image/DefaultImg.o ../Image/ImportImg.o ../ImageImporter/ImageImporter.o ../Room/Room.o ../Screen/SlotScreen.o ../Cutscene/Cutscene.o ../Puzzles/Hanoi.o ../Puzzles/TicTacToe.o PuzzleState.o ../Puzzles/Puzzle.o ../Puzzles/ConnectFour.o ../Puzzles/MemoryMatch.o ../Puzzles/CodeCracker.o

## targets and prerequisites
.PHONY : all
all : explore

explore : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

## generate the prerequisites and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(OBJS2:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) $(OBJS2:.o=.cpp) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean:
	rm -f *.o *.gcda *.gcno 
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f menuTest runTest
