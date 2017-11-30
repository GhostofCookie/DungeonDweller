CC=g++
CCFLAGS= -Wall -std=c++11 -g -lcppunit -ldl #-fprofile-arcs -ftest-coverage
OBJS= main.o Player.o Npc.o Character.o ../Item/MyConsumables.o ../Image/ImportImg.o ../Image/Image.o ../Screen/Screen.o ../Item/Item.o ../Item/Weapon.o ../Item/MyWeapons.o
OBJS2= mainTest.o PlayerTest.o CharacterTest.o Character.o Player.o Npc.o ../Item/MyConsumables.o ../Image/ImportImg.o ../Image/Image.o ../Screen/Screen.o ../Item/Item.o ../Item/Weapon.o ../Item/MyWeapons.o

.PHONY : all
all: main testHeaders

main : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@ 

testHeaders : $(OBJS2)
	$(CC) $(CCFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

.prereq : $(OBJS:.o=.cpp) $(OBJS2:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) $(OBJS2:.o=.cpp) >> ./.prereq

include .prereq

.PHONY : clean
clean:
	rm -rf *~ *.o *.gcda *.gcno

clean-all: clean
	rm -rf main testHeaders
