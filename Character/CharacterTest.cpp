#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "CharacterTest.h"


void CharacterTest:: setUp()
{
   item = "Does not exist";
}

void CharacterTest:: TestFillInventory()
{
   C.FillInventory(I);
   CPPUNIT_ASSERT(inv[0] == I);
}

void CharacterTest:: TestGetInventoryItems()
{
   CPPUNIT_ASSERT(C.GetInventoryItems() == inv); 
}

void CharacterTest:: TestUseItem()
{
   I = C.UseItem(item);
   CPPUNIT_ASSERT(I == nullptr);  
}

void CharacterTest:: TestChangeGold()
{
   C.ChangeGold(10);
   C.ChangeGold(-11);
   int g = C.GetGold();
   CPPUNIT_ASSERT(g == 0);
}

void CharacterTest:: TestChangeHealth()
{
   C.ChangeHealth(10);
   C.ChangeHealth(-11);
   int h = C.GetHealth();
   CPPUNIT_ASSERT(h == 0);
}

void CharacterTest:: TestChangeStamina()
{
   C.ChangeStamina(10);
   C.ChangeStamina(-11);
   int s = C.GetStamina();
   CPPUNIT_ASSERT(s == 0);
}
