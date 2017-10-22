#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item
{
  public:
   virtual ~Item();
   Item* getItem(string itemType);
   void use(Charater *target);
   string name();
   string name() const;

  private:
   string n;
};
#endif
