CC = g++
CCFLAGS = -Wall -std=c++11 -g -lcppunit -ldl -fprofile-arcs -ftest-coverage
OBJS = main.o ScreenTest.o Screen.o SlotScreen.o ../Image/Image.o ../Image/DefaultImg.o ../Image/ImportImg.o ../ImageImporter/ImageImporter.o ../Room/Room.o

.PHONY : all
all : main

main : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

# generate the prerequisites and append to the desired file
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

# include the generated prerequisite file

.PHONY : clean
clean:
	rm -f *.o *.gcda *.gcno
	rm -f *~ *# .#*

.PHONY : clean-all
clean-all : clean
	rm -f main
