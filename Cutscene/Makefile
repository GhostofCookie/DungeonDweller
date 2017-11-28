CC = g++
CCFLAGS = -Wall -std=c++11 -g #-lcppunit -ldl #-fprofile-arcs -ftest-coverage
OBJS = main.o Cutscene.o ../ImageImporter/ImageImporter.o ../Screen/Screen.o ../Image/Image.o ../Image/DefaultImg.o ../Image/ImportImg.o ../Room/Room.o ../Character/Character.o ../Item/Item.o ../Item/MyConsumables.o ../Item/MyWeapons.o

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
	rm -f *.o *.gcda *.gcno
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
