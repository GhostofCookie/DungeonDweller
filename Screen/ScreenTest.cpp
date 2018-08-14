#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "ScreenTest.h"


//************************************************************************
/// Create some variables to test with
//************************************************************************
void ScreenTest::setUp()
{
   heightMax = widthMax = 100;
   heightMin = widthMin = 0;
   heightNegative = widthNegative = -10;

   screen = new Screen(heightMax, widthMax);
   screen2 = new Screen(heightMin, widthMin);
}

//************************************************************************
/// Create some variables to test with
//************************************************************************
void ScreenTest::testTearDown()
{
   delete screen;
   delete screen2;
}

//************************************************************************
/// Tests for a large number
//************************************************************************
void ScreenTest::testCreated()
{
   CPPUNIT_ASSERT(screen != nullptr);
   CPPUNIT_ASSERT(screen2 != nullptr);
}

//************************************************************************
/// Tests for a small number
//************************************************************************
void ScreenTest::testSetTooLarge()
{
   screen->Set(0, 0, ' ');
}

//************************************************************************
/// Tests for a negative number
//************************************************************************
void ScreenTest::testSetNegative()
{
   //test as if one of the parameters had been negative
   CPPUNIT_ASSERT(heightNegative < 0);
}

//************************************************************************
/// Tests if the outline works
//************************************************************************
void ScreenTest::testOutline()
{
   screen->outlineOn = false;
}

//************************************************************************
/// Tests if a number is even
//************************************************************************
void ScreenTest::testIsEven()
{
   CPPUNIT_ASSERT(screen->IsEven(2));
}

//************************************************************************
/// Tests if the fill works
//************************************************************************
void ScreenTest::testFill()
{
   screen->Fill();
}

//************************************************************************
/// Tests if the erase function works
//************************************************************************
void ScreenTest::testErase()
{
   screen->Erase();
}

//************************************************************************
/// Tests if the resize works
//************************************************************************
void ScreenTest::testResize()
{
    screen->Resize(10, 10);
}

//************************************************************************
/// Tests if the std::ostream outputs correctly
//************************************************************************
void ScreenTest::testOstream()
{
   std::cout << screen;
}


