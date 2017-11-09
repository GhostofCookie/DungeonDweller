//
// \author Reid Paulhus
// \date 2/11/2017
//
// This is a test class for the Screen class
//
//

#ifndef SCREENTEST_H
#define SCREENTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Screen.h"
#include "SlotScreen.h"
#include <stdexcept>

//************************************************************************
/// class to test functionality of the Screen class
//************************************************************************
class ScreenTest: public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ScreenTest);
	
	/// Tests searching for a large value
	CPPUNIT_TEST(testTooSmall);
	/// Tests searching for a small value
	CPPUNIT_TEST(testTooLarge);
	/// Tests searching for a negative
	CPPUNIT_TEST(testNegative);
	/// Tests to see if the screen is created
	CPPUNIT_TEST(testCreated);
	
	CPPUNIT_TEST_SUITE_END();
	
	
	
public:
	/// function to set up the variables
	void setUp();
	/// tests finding a large number
	void testTooLarge();
	/// tests finding a small number
	void testTooSmall();
	/// tests negative number
	void testNegative();
	/// tests if the screen exists
	void testCreated();
	
private:
	/// A screen
	Screen *screen = new Screen();
	int heightMin;
	int widthMin;
	int heightMax;
	int widthMax;
	int heightNegative;
	int widthNegative;
};

#endif
