#include <cppunit/TextTestRunner.h>
#include "ScreenTest.h"
using namespace CppUnit;


int main()
{
   TextTestRunner runner;
   runner.addTest(ScreenTest::suite());
   runner.run();

   return 0;
}
   
