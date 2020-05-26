/**
 * Character.h
 *
 * @author Gates Kempenaar
 * @date Oct 25, 2017
 *
 */

#pragma once

#include <stdio.h>
#include <iostream>
#include "MyWeapons.h"
#include "Weapon.h"
#include "MyConsumables.h"
#include "Item.h"
#include "ImportImg.h"
#include <vector>

class Item;
class MyConsumable;
class Weapon;

/** @class Character Character.h
 * @brief Abstract base class of Npc's and Player's attributes
 */
class Character
{
  public:
   /** Character constructor */
   Character();
   
   /** Character deconstructor */
   virtual ~Character();

   /** Const copy constructor */
   Character(const Character&);
   
   /** Assignment operator overloader for copy constructor */
   Character& operator = (const Character &p);

   /** Function to fill the characters inventory
    * @param[in] item, a pointer to the item being added into inventory
    */
   virtual void FillInventory(Item *item);
   
   /** Shows a list of inventory items
    * @returns, a the std::vector of the inventory
    */
   virtual std::vector<Item*> GetInventoryItems();

   /** Chooses the item to be used
    * @param[in] item, the item name to be found in the inventory std::vector
    * @returns Item, a pointer to an item if its found in the inventory
    */
   virtual Item* UseItem(std::string item);

   /** Change the amount of gold a character has
    * @param[in] goldMod, how much the current gold will be changed by
    */
   virtual void ChangeGold(int goldMod);

   /** Changes the characters health
    * @param[in] hMod, how the current health will be modified
    */
   virtual void ChangeHealth(int hMod);

   /** Changes players stamina
    * @param[in] sMod, how the curent stamina will be modified
    */
   virtual void ChangeStamina(int sMod);

   /** @returns the stamina value of the character */
   virtual int GetStamina() const { return stamina; };
   
   /** @returns the gold value of the character * /
   virtual int GetGold() const { return gold; };
   
   /** /return the health value of the character */
   virtual int GetHealth() const { return health; };

   /** @returns the image representing the character */
   virtual ImportImg& Img() { return img; };

   /** Draw the player
    * @param[in] screen, a reference to the screen
    */
   virtual void Draw(Screen &screen);

   /** Helper function for the destructor to delete inventory items */
   void EmptyInventory();

protected:
    ImportImg img;

    /** Vector of items the character has */
    std::vector<Item*> inventory;

    /** Amount of gold player has */
    int gold;

    /** Characters health */
    int health;

    /** Characters stamina */
    int stamina;

}; 
