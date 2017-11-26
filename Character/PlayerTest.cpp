#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "PlayerTest.h"

void PlayerTest:: setUp()
{
   keyMod = -1;
}

void PlayerTest:: TestKeys()
{
   T.ChangeKeys(keyMod);
}
