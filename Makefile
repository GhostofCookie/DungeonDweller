CC = g++
CCFLAGS = -Wall -std=c++11 -g
MENU = Menu/Menu.o
SCREEN = 
IMAGE = 
ROOM = 
ROOMTREE = RoomTree.o
GAMESTATE = 
PUZZLE =
ITEM = Item.o Weapon.o Consumable.o MyWeapons.o MyConsumables.o
CHARACTER = 
OBJS = $(MENU) $(SCREEN) $(IMAGE) $(ROOM) $(ROOMTREE) $(GAMESTATE) $(PUZZLE) $(ITEM) $(CHARACTER) DungeonDweller.o
## targets and prerequisites
.PHONY : all
all : DungeonDweller

main : $(OBJS)
	$(CC) -o $@ $(CCFLAGS) $^

# default rule for compiling .cc to .o
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

.PHONY : clean-all
clean-all : clean
	rm -f main
