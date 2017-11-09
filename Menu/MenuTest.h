/// \author Tomas Rigaux
/// \date 8/11/2017
///
/// This is the testing class for Menu.
///

#ifndef MENUTEST_H
#define MENUTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Menu.h"
#include <map>

/// \class MenuTest MenuTest.h
/// \brief Test class for the Menu class.
class MenuTest : public CppUnit::TestFixture
{
   //CPP UNIT TESTS
   CPPUNIT_TEST_SUITE(MenuTest);
   CPPUNIT_TEST(testConstructors);
   CPPUNIT_TEST(testSetting);
   CPPUNIT_TEST(testBuilding);
   CPPUNIT_TEST_SUITE_END();

  public:
   /// Sets up the test variables for testing.
   void setUp();
   /// Deletes any pointers to prevent memory leak.
   void tearDown();
   /// Tests that the constructor is wokring in several varieties of construction.
   void testConstructors();
   /// Tests the setting of options.
   void testSetting();
   /// Tests that menu builds correctly.
   void testBuilding();

  private:
   Menu *menu = nullptr;
   Menu *menu2 = nullptr;
   std::map<int,string> options;
   
};

#endif
