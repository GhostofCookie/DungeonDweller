/// PlayerTest.h
///
/// @author Gates Kempenaar
/// \date 8/11/2017
///

#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Player.h"
#include "../Image/ImportImg.h"
#include "MyConsumables.h"
#include "Item.h"
#include "Screen.h"
#include "../Image/ImportImg.h"
#include <algorithm>

/// class to test functionality of the IntVector class
class PlayerTest : public CppUnit::TestFixture
{
   //test cases
   CPPUNIT_TEST_SUITE(PlayerTest);
   CPPUNIT_TEST(TestKeys);
   CPPUNIT_TEST_SUITE_END();

  public:

   ///>override \c setUp to create variable
   void setUp();

   ///> test key functions of player
   void TestKeys(); 
   
  private:
   //values used for test cases
   int keyMod;
   Player T;
};
