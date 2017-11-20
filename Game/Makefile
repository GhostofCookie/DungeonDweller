CC = g++
ARCHIVEDIR = ../ImageImporter ../Menu ../GameState ../Screen ../Image ../Room 
ARCHIVEDIR += ../RoomTree
CCFLAGS = -Wall -std=c++11 -I$(ARCHIVEDIR) -g 
COV = -fprofile-arcs -ftest-coverage #-lcppunit -ldl 
LIB = ./lib
LINKS = -L $(LIB) $(COV)

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
