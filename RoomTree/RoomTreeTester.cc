///
/// \author Rylan Bueckert
/// \date Nov 8, 2017
///
/// Main tester for RoomTree
///

#include <cppunit/TextTestRunner.h>
using namespace CppUnit;

#include "RoomTreeTest.h"

int main()
{
   TextTestRunner runner;
   runner.addTest(RoomTreeTest::suite());
   runner.run();
   return 0;
}
