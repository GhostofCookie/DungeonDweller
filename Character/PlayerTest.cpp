#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PlayerTest.h"

void PlayerTest:: setUp()
{
   key = 0;
   keyMod = -1;
   stamina = 10;
   staminaMod = -11;
}

void PlayerTest:: TestKeys()
{
   T.ChangeKeys(keyMod);
}

void PlayerTest:: TestStamina()
{
   T.ChangeStamina(staminaMod);
}
