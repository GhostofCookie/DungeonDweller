/**
 * MyWeapons Header File
 *
 * @author Rylan Bueckert
 * @date Oct 25, 2017
 */

#pragma once

#include "Weapon.h"

/** Subclass of Weapon to represent a sword in game */
class Sword: public Weapon
{
  public:
   /** Constructor */
   Sword();

   /** Defines what happens when the sword is used
    * @param[in] target The character that the sword is used on
    * @returns true if use was successfull
    */
   bool Use(Character *target);
};


/** Subclass of Weapon to represent a bow in game */
class Bow: public Weapon
{
  public:
   /** Constructor */
   Bow();

   /** Defines what happens when the spell is used
    * @param[in] target The character that the spell is used on
    * @returns true if use was successfull
    */
   bool Use(Character *target);

   /** Returns the accuracy of the bow (for reading only)
    * @returns Bow accuracy
    */
   int Accuracy() const;

   /** Returns the accuracy of the weapon (for writing)
    * @returns reference to hitPercent
    */
   int &Accuracy();

  protected:
   /** The bows accuracy as a percent
    * (accuracy less than 1 always miss) (accuracy greater than 99 always hit)
    */
   int hitPercent;
};


/** Subclass of Weapon to represent a spell in game */
class Spell: public Weapon
{
  public:
   /** Constructor */
   Spell();

   /** Defines what happens when the spell is used
    * @param[in] target The character that the spell is used on
    * @returns true if use was successfull
    */
   bool Use(Character *target);

};
