#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ScreenTest.h"


//************************************************************************
/// Create some variables to test with
//************************************************************************
void ScreenTest::setUp()
{
	heightMax = heightMin = 200;
	heightMin = widthMin = 0;
	heightNegative = widthNegative = -10;
}

//************************************************************************
/// Tests for a large number
//************************************************************************
void ScreenTest::testCreated()
{
	CPPUNIT_ASSERT(screen);
}

//************************************************************************
/// Tests for a small number
//************************************************************************
void ScreenTest::testTooLarge()
{
}

//************************************************************************
/// Tests for a sorted Array
//************************************************************************
void ScreenTest::testTooSmall()
{
}

//************************************************************************
/// Tests for a negative number
//************************************************************************
void ScreenTest::testNegative()
{
}

