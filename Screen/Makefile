CC = g++
CCFLAGS = -Wall -std=c++11 -g -lcppunit -ldl -fprofile-arcs -ftest-coverage
<<<<<<< HEAD
OBJS = main.o ScreenTest.o Screen.o SlotScreen.o ../Image/Image.o ../Image/DefaultImg.o ../Image/ImportImg.o ../ImageImporter/ImageImporter.o ../Room/Room.o

## targets and prerequisites
=======
OBJS = main.o ScreenTest.o Screen.o SlotScreen.o ../Image/Image.o ../Image/ImportImg.o ../Image/DefaultImg.o ../Room/Room.o ../ImageImporter/ImageImporter.o
>>>>>>> cb9ab3cde212bd0f90f7af236223edd22f10ed51
.PHONY : all
all : main

main : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

## generate the prerequisites and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

## include the generated prerequisite file
include	.prereq

.PHONY : clean
clean:
	rm -f *.o *.gcda *.gcno 
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
