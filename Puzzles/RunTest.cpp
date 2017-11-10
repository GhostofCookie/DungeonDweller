/// \author Tyler Siwy
/// \date 11/9/2017
/// RunTest.cpp-This file runs test cases for the Puzzle classes; Hanoi
#include <cppunit/TestTestRunner.h>
using namespace CppUnit;

#include "HanoiTest.h"

int main()
{
   TextTestRunner runner;
   runner.addTest(HanoiTest::suite());
   runner.run();

   return 0;
}
