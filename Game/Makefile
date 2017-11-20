CC = g++
CCFLAGS = -Wall -std=c++11 -g -lcppunit -ldl -fprofile-arcs -ftest-coverage
MENU = ../Menu/CharacterMenu.o ../Menu/ConnectFourMenu.o ../Menu/DialogueMenu.o ../Menu/ExploreMenu.o ../Menu/FightMenu.o ../Menu/HanoiMenu.o ../Menu/MainMenu.o ../Menu/MemoryMenu.o ../Menu/Menu.o ../Menu/RiddleMenu.o ../Menu/TicTacToeMenu.o ../Menu/TradeMenu.o
SCREEN = ../Screen/Screen.o ../Screen/SlotScreen.o
IMAGE = ../Image/Image.o ../Image/ImportImg.o ../Image/DefaultImg.o ../ImageImporter/ImageImporter.o
ROOM =  ../Room/Room.o
ROOMTREE = ../RoomTree/RoomTree.o
PUZZLE = ##../Puzzles/CodeCracker.o ../Puzzles/ConnectFour.o ../Puzzles/Hanoi.o ../Puzzles/MemoryMatch.o ../Puzzles/TicTacToe.o
ITEM = ##../Item/Item.o ../Item/Weapon.o ../Item/MyWeapons.o ../Item/MyConsumables.o
CHARACTER = ## ../Character/Npc.o ../Character/Player.o
OBJS = DungeonDweller.o $(MENU) $(SCREEN) $(IMAGE) $(ROOM) $(ROOMTREE) $(GAMESTATE) $(PUZZLE) $(ITEM) $(CHARACTER)


## targets and prerequisites
.PHONY : all
all : DungeonDweller

DungeonDweller : $(OBJS)
	$(CC) -o $@ $(CCFLAGS) $^

## default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c -o $@ $(CCFLAGS) $<



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
	rm -f *.gcno *.gcda

.PHONY : clean-all
clean-all : clean
	rm -f DungeonDweller
