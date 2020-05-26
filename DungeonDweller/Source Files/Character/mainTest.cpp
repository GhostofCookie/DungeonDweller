#include <cppunit/TextTestRunner.h>
#include "PlayerTest.h"
#include "CharacterTest.h"

using namespace CppUnit;

///main test program
int main()
{
   TextTestRunner runner; //test runner
   runner.addTest(PlayerTest::suite());
   runner.run();
   runner.addTest(CharacterTest::suite());
   runner.run();
   
   return 0;
}
