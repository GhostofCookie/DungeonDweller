CC = g++
CCFLAGS = -Wall -std=c++11 -g
OBJS = main.o Menu.o Screen.o 

## targets and prerequisites
.PHONY : all
all : main

main : $(OBJS)
	$(CC) $^ -o $@

# default rule for compiling .cc to .o
%.o : %.cc
	$(CC) -c $(CCFLAGS) $<

## generate the prerequisites and append to the desired file
.prereq : $(OBJS:.o=.cc) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cc) >> ./.prereq

## include the generated prerequisite file
include .prereq

.PHONY : clean
clean:
	rm -f *.o
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
