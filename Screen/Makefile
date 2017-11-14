CC = g++
CCFLAGS = -Wall -std=c++11 -g -lcppunit -ldl -fprofile-arcs -ftest-coverage
OBJS = main.o ScreenTest.o Screen.o SlotScreen.o ../Image/Image.o ../Image/DefaultImg.o ../Image/ImportImg.o ../ImageImporter/ImageImporter.o ../Room/Room.o
<<<<<<< HEAD
=======

>>>>>>> 74469a9a672e68070281914f9a64049273a34c18
.PHONY : all
all : main

main : $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@ 

%.o : %.cpp
	$(CC) -c $(CCFLAGS) $<

<<<<<<< HEAD
## generate the prerequistes and append to the desired file
=======
# generate the prerequisites and append to the desired file
>>>>>>> 74469a9a672e68070281914f9a64049273a34c18
.prereq : $(OBJS:.o=.cpp) $(wildcard *.h) Makefile
	rm -f .prereq
	$(CC) $(CCFLAGS) -MM $(OBJS:.o=.cpp) >> ./.prereq

<<<<<<< HEAD
#include .prereq	

=======
<<<<<<< HEAD
## include the generated prerequisite file
include .prereq

.PHONY : clean
clean :
	rm -f *.o *~ #* .#*
=======
>>>>>>> e43e1c024f4cd13d6f8653db5772350b4c5d1f8e
# include the generated prerequisite file

.PHONY : clean
clean:
	rm -f *.o *.gcda *.gcno
	rm -f *~ *# .#*
>>>>>>> 74469a9a672e68070281914f9a64049273a34c18

.PHONY : clean-all
clean-all : clean
	rm -f main
