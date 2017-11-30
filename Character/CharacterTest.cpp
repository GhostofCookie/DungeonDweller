#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "CharacterTest.h"
#include <iostream>


void CharacterTest:: setUp()
{
   cout << "setup" << endl;
   item = "Does not exist";
   I = new Bow;

}


void CharacterTest:: tearDown()
{
   cout << "teardown" << endl;
   delete I;
}


void CharacterTest:: TestFillInventory()
{
   cout << "fill" << endl;
   if(I == nullptr)
      cout << "nullptr" << endl;
   else
   C.FillInventory(I);
   int i = inv.size();
   cout << i << endl;
   CPPUNIT_ASSERT(inv[0] == I);
}

void CharacterTest:: TestGetInventoryItems()
{
   cout << "get" << endl;
   CPPUNIT_ASSERT(C.GetInventoryItems() == inv); 
}

void CharacterTest:: TestUseItem()
{
   cout << "use" << endl;
   II = C.UseItem(item);
   CPPUNIT_ASSERT(II == nullptr);  
}

void CharacterTest:: TestChangeGold()
{
   cout << "gold" << endl;
   C.ChangeGold(10);
   C.ChangeGold(-11);
   int g = C.GetGold();
   CPPUNIT_ASSERT(g == 0);
}

void CharacterTest:: TestChangeHealth()
{
   cout << "health" << endl;
   
   C.ChangeHealth(10);
   C.ChangeHealth(-11);
   int h = C.GetHealth();
   CPPUNIT_ASSERT(h == 0);
}

void CharacterTest:: TestChangeStamina()
{
   cout << "stamina" << endl;
   C.ChangeStamina(10);
   C.ChangeStamina(-11);
   int s = C.GetStamina();
   CPPUNIT_ASSERT(s == 0);
}
