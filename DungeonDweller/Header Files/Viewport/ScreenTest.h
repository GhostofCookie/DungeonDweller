 *
 * @author Reid Paulhus
 * @date 2/11/2017
 *
 * This is a test class for the Screen class
 *
 *

#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Screen.h"
#include <stdexcept>

//************************************************************************
 * class to test functionality of the Screen class
//************************************************************************
class ScreenTest: public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(ScreenTest);
   
   CPPUNIT_TEST(testCreated);
   CPPUNIT_TEST(testIsEven);
   CPPUNIT_TEST(testFill);
   CPPUNIT_TEST(testSetTooLarge);
   CPPUNIT_TEST(testSetNegative);
   CPPUNIT_TEST(testOutline);
   CPPUNIT_TEST(testResize);
   CPPUNIT_TEST(testTearDown);
	
   CPPUNIT_TEST_SUITE_END();
	
	
	
  public:
    * function to set up the variables
   void setUp();
    * tests finding a large number
   void testSetTooLarge();
    * tests negative number
   void testSetNegative();
    * tests if the screen exists
   void testCreated();
    * tests if the outline is on
   void testOutline();
    * tests if a value is even correctly
   void testIsEven();
    * tests if the fill works
   void testFill();
    * tests if the screen can erase the contents
   void testErase();
    * tests if the screen can print
   void testOstream();
    * tests the resize function
   void testResize();
    * Delete the screens
   void testTearDown();
	
  private:
    * Screens
   Screen *screen;
   Screen *screen2;
   
    * smallest height bound
   int heightMin;
    * smallest width bound
   int widthMin;
    * a positive height bound
   int heightMax;
    * a positive width bound
   int widthMax;
    * a negative height bound
   int heightNegative;
    * a negative width bound
   int widthNegative;
};
