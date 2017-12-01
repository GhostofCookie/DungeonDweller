#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "CharacterTest.h"
#include "Player.h"
#include <iostream>
#include <stdexcept>


void CharacterTest:: setUp()
{
   item = "Does not exist";
}

void CharacterTest:: TestFillInventory()
{
   HealthPotion *I;
   I = new HealthPotion;
   C.FillInventory(I);	 
   inv = C.GetInventoryItems();
   CPPUNIT_ASSERT(inv[0] == I);
}

void CharacterTest:: TestGetInventoryItems()
{
   HealthPotion *III;
   III = new HealthPotion;
   inv.push_back(III);
   C.FillInventory(III);
   CPPUNIT_ASSERT(C.GetInventoryItems() == inv); 
}

void CharacterTest:: TestUseItem()
{
   HealthPotion *II;
   II = new HealthPotion;
   string name = II->Name();
   C.FillInventory(II);
   CPPUNIT_ASSERT(C.UseItem(item) == nullptr);
   CPPUNIT_ASSERT(C.UseItem(name) == II);
}

void CharacterTest:: TestChangeGold()
{
   C.ChangeGold(10);
   C.ChangeGold(-11);
   int g = C.GetGold();
   CPPUNIT_ASSERT(g == 0);
   C.ChangeGold(10);
   C.ChangeGold(-5);
   g = C.GetGold();
   CPPUNIT_ASSERT(g == 5);
}

void CharacterTest:: TestChangeHealth()
{
   C.ChangeHealth(10);
   C.ChangeHealth(-11);
   int h = C.GetHealth();
   CPPUNIT_ASSERT(h == 0);
   C.ChangeHealth(10);
   C.ChangeHealth(-5);
   h = C.GetHealth();
   CPPUNIT_ASSERT(h == 5);
}

void CharacterTest:: TestChangeStamina()
{
   C.ChangeStamina(10);
   C.ChangeStamina(-11);
   int s = C.GetStamina();
   CPPUNIT_ASSERT(s == 0);
   C.ChangeStamina(10);
   C.ChangeStamina(-5);
   s = C.GetStamina();
   CPPUNIT_ASSERT(s == 5);
}
