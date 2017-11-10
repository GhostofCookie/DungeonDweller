#include <cppunit/TextTestRunner.h>
#include "ScreenTest.h"
using namespace CppUnit;


//************************************************************************
/// The simple main function to run the test suites
//************************************************************************
int main()
{
   TextTestRunner runner;
   runner.addTest(ScreenTest::suite());
   runner.run();
	
   return 0;
}

