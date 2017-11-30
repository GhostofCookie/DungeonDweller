CC = g++
CCFLAGS = -Wall -std=c++11 -g -lcppunit -ldl
OBJS = RoomTreeTester.o RoomTreeTest.o RoomTree.o ../Room/Room.o ../Screen/Screen.o ../Image/Image.o ../Image/ImportImg.o ../Character/Character.o ../Item/Item.o ../Item/MyConsumables.o ../Item/MyWeapons.o
OBJS2 = main.o RoomTreeTest.o RoomTree.o ../Room/Room.o ../Screen/Screen.o ../Image/Image.o ../Image/ImportImg.o ../Character/Character.o ../Item/Item.o ../Item/MyConsumables.o ../Item/MyWeapons.o
.PHONY : all
all : testHeaders main

testHeaders : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

main : $(OBJS2)
	$(CC) $(CCFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

## generate the prerequistes and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(OBJS2:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) $(OBJS2:.o=.cpp) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :
	rm -f *.o *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main testHeaders
