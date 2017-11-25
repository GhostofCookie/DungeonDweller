#ifndef PLAYERTEST_h
#define PLAYERTEST_h

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Player.h"
#include "../Image/ImportImg.h"
#include <algorithm>

/// class to test functionality of the IntVector class
class PlayerTest : public CppUnit::TestFixture
{
   //test cases
   CPPUNIT_TEST_SUITE(PlayerTest);
   CPPUNIT_TEST(TestStamina);
   CPPUNIT_TEST(TestKeys);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp(); ///>override \c setUp to create variable
   void TestKeys();
   void TestStamina();
   
  private:
   //values used for test cases
   int key, keyMod;
   int stamina, staminaMod;
   Player T;
};

#endif
