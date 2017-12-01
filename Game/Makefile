CC = g++
ARCHIVEDIR = ../ImageImporter:../Menu:../GameState:../Screen:../Image:../Room:../RoomTree:../Puzzles:../Cutscene
MENU = ../Menu/CharacterMenu.o ../Menu/ConnectFourMenu.o ../Menu/DialogueMenu.o ../Menu/ExploreMenu.o ../Menu/FightMenu.o ../Menu/HanoiMenu.o ../Menu/MainMenu.o ../Menu/MemoryMenu.o ../Menu/Menu.o ../Menu/RiddleMenu.o ../Menu/TicTacToeMenu.o ../Menu/TradeMenu.o
STATE = ../GameState/ExploreState.o ../GameState/TradeState.o ../GameState/FightState.o ../GameState/MainState.o ../GameState/PuzzleState.o  ../GameState/InventoryState.o
SCREEN = ../Screen/Screen.o
IMAGE = ../Image/Image.o ../Image/ImportImg.o ../Image/DefaultImg.o ../ImageImporter/ImageImporter.o
ROOM =  ../Room/Room.o
ROOMTREE = ../RoomTree/RoomTree.o
CUTSCENE = ../Cutscene/Cutscene.o
PUZZLE = ../Puzzles/CodeCracker.o ../Puzzles/ConnectFour.o ../Puzzles/Hanoi.o ../Puzzles/MemoryMatch.o ../Puzzles/TicTacToe.o ../Puzzles/Puzzle.o
ITEM = ../Item/Item.o ../Item/Weapon.o ../Item/MyWeapons.o ../Item/MyConsumables.o
CHARACTER =  ../Character/Npc.o ../Character/Player.o ../Character/Character.o
OBJS = DungeonDweller.o $(MENU) $(SCREEN) $(IMAGE) $(ROOM) $(ROOMTREE) $(CUTSCENE) $(PUZZLE) $(ITEM) $(STATE) $(CHARACTER)
COV = -lcppunit -ldl 
CCFLAGS = -Wall -std=c++11 $(COV) #-I$(ARCHIVEDIR) -g 

LIB = ./lib
LINKS = -L $(LIB) $(COV)

## targets and prerequisites
.PHONY : all
all : DungeonDweller

DungeonDweller : $(OBJS) #$(LIB)/DD_Lib.a
	$(CC) $^ -o $@ $(CCFLAGS) #$(LINKS)

## default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c -o $@ $(CCFLAGS) $<

.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

include .prereq

.PHONY : clean
clean:
	rm -f *.o
	rm -f *~ *# .#*
	rm -f *.gcno *.gcda

.PHONY : clean-all
clean-all : clean
	rm -f DungeonDweller
