//
// Item Class Header File
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "../Character/Character.h"
#include "../Character/Player.h"
using namespace std;

/// This class is an abstract base class to represent items in game
class Item
{
<<<<<<< HEAD
  public:

   /// Virtual destructor
   virtual ~Item();

   /// Uses factory design pattern to create items
   /// \param[in] itemType The type of item to be created
   /// \return Pointer to created item
   Item* getItem(string itemType);

   /// Pure Virtual funtion that forces all subclasses to define how to use themselves
   /// \param[in] target The Character the item is being used on
   virtual void use(Character *target)=0;

   /// Allows access to the items name
   /// \return Reference to the name of the item
   string &name();

   /// Gives the name of the item without allowing chages
   /// \return Name of the item
   string name() const;

  private:
   
   /// Name of the item
   string n;
=======
public:

	/// Virtual destructor
	virtual ~Item();

	/// Uses factory design pattern to create items
	/// \param[in] itemType The type of item to be created
	/// \return Pointer to created item
	/// \exception invalid_argument Thrown if type does not exist or is not allowed
	Item *getItem(string itemType);

	/// Pure Virtual funtion that forces all subclasses to define how to use themselves
	/// \param[in] target The Character the item is being used on
	/// \return true if use was successfull
	virtual bool use(Character *target)=0;

	/// Allows access to the items name
	/// \return Reference to the name of the item
	string &name();

	/// Gives the name of the item without allowing chages
	/// \return Name of the item
	string name() const;

	/// Generates adjectives to add to Item names
	/// \param[in] fileName the file that the names comme from
	/// \returns Adjective generated and to be used
	/// \exception runtime_error Thrown if source file has no names
	string nameGenerator(string fileName);

protected:
	/// Helper function to generate random positive numbers
	/// \return Random number between start and end
	int random(unsigned int start,unsigned int end);

	///Name of the item
	string itemName;
>>>>>>> 353212ca8cb715576b9af5978df364572b6e1267
};
#endif
