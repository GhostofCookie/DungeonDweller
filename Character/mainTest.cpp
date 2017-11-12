#include <cppunit/TextTestRunner.h>
#include "PlayerTest.h"

using namespace CppUnit;

///main test program
int main()
{
   TextTestRunner runner; //test runner
   runner.addTest(PlayerTest::suite());
   runner.run();
   
   return 0;
}
