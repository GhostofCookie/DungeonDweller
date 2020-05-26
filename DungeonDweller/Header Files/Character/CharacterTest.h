/// CharacterTest.h
///
/// @author Gates Kempenaar
/// \date 8/11/2017
///

#pragma once


#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Character.h"
#include "../Image/ImportImg.h"
#include "MyConsumables.h"
#include "Screen.h"
#include "../Image/ImportImg.h"
#include <algorithm>

class Item;
class Weapon;
/// class to test functionality of the Character class
class CharacterTest : public CppUnit::TestFixture
{
   //test cases
   CPPUNIT_TEST_SUITE(CharacterTest);
   CPPUNIT_TEST(TestFillInventory);
   CPPUNIT_TEST(TestGetInventoryItems);
   CPPUNIT_TEST(TestUseItem);
   CPPUNIT_TEST(TestChangeGold);
   CPPUNIT_TEST(TestChangeHealth);
   CPPUNIT_TEST(TestChangeStamina);
   CPPUNIT_TEST_SUITE_END();

  public:

   /// >override \c setUp to create variable
   void setUp();

   ///> test filling the characters inventory
   void TestFillInventory();

   ///> test geting the characters entire inventory
   void TestGetInventoryItems();

   ///> test returning and item to use in the characters inventory
   void TestUseItem();

   ///> test changing how much gold the character has
   void TestChangeGold();

   ///> test changing how much health the character has
   void TestChangeHealth();

   ///. test changing how much stamina the character has
   void TestChangeStamina();
   
  private:
   
   //values used for test cases
   std::string item;
   std::vector<Item*> inv;
   Character C;
};
