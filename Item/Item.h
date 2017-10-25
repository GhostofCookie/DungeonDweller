//
// Item Class Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

/// This class is an abstract base class to represent items in game
class Item
{
  public:

   /// Virtual destructor
   virtual ~Item();

   /// Uses factory design pattern to create items
   /// \param[in] itemType The type of item to be created
   /// \return Pointer to created item
   Item* getItem(string itemType);

   /// Pure Virtual funtion that forces all subclasses to define how to use themselves
   /// \param[in] target The Character the item is being used on
   virtual void use(Charater *target)=0;

   /// Allows access to the items name
   /// \return Reference to the name of the item
   string &name();

   /// Gives the name of the item without allowing chages
   /// \return Name of the item
   string name() const;

  private:
   
   /// Name of the item
   string n;
};
#endif
