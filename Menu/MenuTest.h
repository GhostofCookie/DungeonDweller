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
#include "ExploreMenu.h"
#include "TradeMenu.h"
#include "FightMenu.h"
#include "DialogueMenu.h"
#include "RiddleMenu.h"
#include "MemoryMenu.h"
#include "ConnectFourMenu.h"
#include "TicTacToeMenu.h"
#include "HanoiMenu.h"
#include <map>

/// \class MenuTest MenuTest.h
/// \brief Test class for the Menu class.
class MenuTest : public CppUnit::TestFixture
{
   //CPP UNIT TESTS
   CPPUNIT_TEST_SUITE(MenuTest);
   CPPUNIT_TEST(TestConstructors);
   CPPUNIT_TEST(TestSetting);
   CPPUNIT_TEST(TestBuilding);
   CPPUNIT_TEST_SUITE_END();

  public:
   /// Sets up the test variables for testing.
   void setUp();
   /// Deletes any pointers to prevent memory leak.
   void tearDown();
   /// Tests that the constructor is wokring in several varieties of construction.
   void TestConstructors();
   /// Tests the setting of options.
   void TestSetting();
   /// Tests that menu builds correctly.
   void TestBuilding();

  private:
   Menu *menu = nullptr;
   Menu *menu2 = nullptr;
   Menu *menu3 = nullptr;
   Menu *menu4 = nullptr;
   Menu *menu5 = nullptr;
   Menu *menu6 = nullptr;
   Menu *menu7 = nullptr;
   Menu *menu8 = nullptr;
   Menu *menu9 = nullptr;
   std::map < int,string > options;
};

#endif
