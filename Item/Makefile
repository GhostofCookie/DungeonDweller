## definitions

CC = g++ -std=c++11
CCFLAGS = -Wall -g
OBJS1 = MyConsumables.o Item.o MyWeapons.o Weapon.o ../Character/Character.h Items.o
## targets and prerequisites
.PHONY : all
all : Items

Items : $(OBJS1)
	$(CC) $(CCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cpp                               ## next line must begin with a TAB
	$(CC) -c $(CCFLAGS) $< 

## generate the prerequistes and append to the desired file
.prereq : $(OBJS1:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS1:.o=.cpp) >> ./.prereq 

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :                 ## next lines must begin with a TAB
	rm -f *.o
	rm -f *~ *# .#* *.gcno *.gcda

.PHONY : clean-all
clean-all : clean      ## next line must begin with a TAB
	rm -f Items
