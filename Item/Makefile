CC=g++
CCFLAGS=-Wall -std=c++11 -g
OBJS= Item.o Weapon.o MyWeapons.o MyConsumables.o

%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) $^ -o $@ -MM $(OBJS:.o=.cpp) >> ./.prereq

include .prereq

.PHONY : clean
clean:
	rm -rf *~ *.o *.gcda *.gcno

clean-all: clean
#	rm -rf mainTest
