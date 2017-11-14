CC = g++
CCFLAGS = -Wall -std=c++11 -g  
MENU = main.o Menu/Menu.o
## targets and prerequisites
.PHONY : all
all : main

main : $(MENU)
	$(CC) -o $@ $(CCFLAGS) $^

# default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c -o $@ $(CCFLAGS) $<

## generate the prerequisites and append to the desired file
.prereq : $(MENU:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(MENU:.o=.cpp) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean:
	rm -f *.o
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
