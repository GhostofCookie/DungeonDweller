CC = g++
<<<<<<< HEAD
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

=======
ARCHIVEDIR = ../ImageImporter ../Menu ../GameState ../Screen ../Image ../Room 
ARCHIVEDIR += ../RoomTree
CCFLAGS = -Wall -std=c++11 -I$(ARCHIVEDIR) -g 
COV = -fprofile-arcs -ftest-coverage #-lcppunit -ldl 
LIB = ./lib
LINKS = -L $(LIB) $(COV)
>>>>>>> 5e40a92571f36d49b522d99aa808708d1fdc319a

## targets and prerequisites
.PHONY : all
all : DungeonDweller

DungeonDweller : $(LIB)/DD_Lib.a
	$(CC) $^ -o $@ $(LINKS)

## default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c $@ $(CCFLAGS) $<

.PHONY : clean
clean:
	rm -f *.o
	rm -f *~ *# .#*
	rm -f *.gcno *.gcda

.PHONY : clean-all
clean-all : clean
	rm -f DungeonDweller
