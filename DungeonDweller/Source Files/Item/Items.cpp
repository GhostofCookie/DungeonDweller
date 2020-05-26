#include "MyConsumables.h"
#include "MyWeapons.h"
#include <vector>
#include <iostream>


int main() {
  Sword testSword;
  Bow testBow;
  Spell testSpell;
  Food testFood;
  HealthPotion testPotion;
  std::vector<Item*> inventory;
  inventory.push_back(new Sword());
  inventory.push_back(new Bow());
   std::cout<<testSword.Name()<<std::endl <<testBow.Name()<<std::endl<<testSpell.Name()<<std::endl<<testFood.Name()<<std::endl<<testPotion.Name()<<std::endl;

   std::cout<<"Inventory contains: "<<std::endl;
   for(auto it = inventory.begin(); it != inventory.end(); ++it)
     std::cout<<(*it)->Name()<<std::endl;
   return 0;
}
