 * @author Tomas Rigaux
 * @date 8/11/2017
 *
 * This file runs the test cases from MenuTest.
 *

#include <cppunit/TextTestRunner.h>
using namespace CppUnit;

#include "MenuTest.h"

int main()
{
   TextTestRunner runner;
   runner.addTest(MenuTest::suite());
   runner.run();
   
   return 0;
}
