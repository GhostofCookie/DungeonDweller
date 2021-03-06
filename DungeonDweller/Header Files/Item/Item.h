/** @author Rylan Bueckert
 * @date Oct 25, 2017
 */

#pragma once

#include <string>

class Character;

/** This class is an abstract base class to represent items in game */
class Item
{
  public:

   /** Virtual destructor */
   virtual ~Item() = default;

   /** Uses factory design pattern to create items
    * @param[in] itemType The type of item to be created
    * @returns Pointer to created item
    * @exception std::invalid_argument Thrown if type does not exist or is not allowed
    */
   Item *GetItem(std::string itemType);

   /** Pure Virtual funtion that forces all subclasses to define how to use themselves
    * @param[in] target The Character the item is being used on
    * @returns true if use was successful
    */
   virtual bool Use(Character *target) = 0;

   /** Allows access to the items name
    * @returns Reference to the name of the item
    */
   std::string &Name();

   /** Gives the name of the item without allowing chages
    * @returns Name of the item
    */
   std::string Name() const;

   /** Generates adjectives to add to Item names
    * @param[in] fileName the file that the names comme from
    * @returns Adjective generated and to be used
    * @exception std::runtime_error Thrown if source file has no names
    */
   std::string NameGenerator(std::string fileName);

  protected:
   /** Helper function to generate random positive numbers
    * @returns Random number between start and end
    */
   int Random(unsigned int start,unsigned int end);

   /** Name of the item */
   std::string itemName;
};
