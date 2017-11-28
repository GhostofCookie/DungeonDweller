#include "MyConsumables.h"
#include "MyWeapons.h"
using namespace std;

int main() {
  Sword testSword;
  Bow testBow;
  Spell testSpell;
  Food testFood;
  HealthPotion testPotion;
   cout<<testSword.Name()<<endl <<testBow.Name()<<endl<<testSpell.Name()<<endl<<testFood.Name()<<endl<<testPotion.Name()<<endl;
   return 0;
}
