#ifndef CHARACTERTEST_h
#define CHARACTERTEST_h

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Character.h"
#include "../Image/ImportImg.h"
#include "../Item/MyConsumables.h"
#include "../Screen/Screen.h"
#include "../Image/ImportImg.h"
#include <algorithm>

class Item;
/// class to test functionality of the IntVector class
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
   
   void setUp(); ///>override \c setUp to create variable
   void tearDown();
   void TestFillInventory();
   void TestGetInventoryItems();
   void TestUseItem();
   void TestChangeGold();
   void TestChangeHealth();
   void TestChangeStamina();
   
  private:
   
   //values used for test cases
   HealthPotion *I;
   string item;
   vector<Item*> inv;
   Character C;
   Item *II;
};

#endif