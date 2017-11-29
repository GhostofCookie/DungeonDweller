#include "MyConsumables.h"
#include "MyWeapons.h"
#include <vector>
using namespace std;

int main() {
  Sword testSword;
  Bow testBow;
  Spell testSpell;
  Food testFood;
  HealthPotion testPotion;
  vector<Item*> inventory;
  inventory.push_back(new Sword());
  inventory.push_back(new Bow());
   cout<<testSword.Name()<<endl <<testBow.Name()<<endl<<testSpell.Name()<<endl<<testFood.Name()<<endl<<testPotion.Name()<<endl;

   cout<<"Inventory contains: "<<endl;
   for(auto it = inventory.begin(); it != inventory.end(); ++it)
     cout<<(*it)->Name()<<endl;
   return 0;
}
