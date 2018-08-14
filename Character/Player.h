//
// Player.h
//
/// \author Gates Kempenaar
/// \date Oct 25, 2017
//


#pragma once

#include <stdio.h>
#include "Character.h"
#include "../Item/MyConsumables.h"
#include "../Item/Item.h"
#include "../Image/ImportImg.h"
#include <vector>
#include <string>

class Item;
class MyConsumable;
class Npc;

///Derived class from Character which provides Player attributes
class Player : public Character
{
  public:
   /// Player constructor
   /// \param[in] s, players stamina
   /// \param[in] k, players keys
   /// \param[in] n, players name
   /// \param[in] r, players race
   /// \param[in] g, players gold amount
   /// \param[in] h, playes health
   /// \param[in] img, image representing the player
   Player(int s = 0, int k = 0, std::string n = " ", std::string r = " ", int g = 0, int h = 0, ImportImg img = ImportImg("../DD_Art/Player/DD_Player.txt"));

   /// Player deconstructor
   ~Player();
   
   /// Const copy constructor
   Player(const Player&);

   /// Assignment operator overloader for copy constructor
   Player& operator = (const Player &p);

   ///Amount of keys the player has
   /// \param[in] keyMod, how the current amount of keys will be modified
   void ChangeKeys(int keyMod);

   ///Function to use a key
   /// \param[in] keys, uses a key if availible
   /// \return true if a key can be used
   bool UseKey(int &keys);

   /// Shows the amount of keys
   /// \return the number of keys the player has
   int GetKeys() const {return keys;};

   /// Shows players race
   /// \return the std::string representing the players race
   std::string GetRace() const {return race;};

   /// Shows players name
   /// \return the std::string representing the players name
   std::string GetName() const {return name;};
   
   /// Prints all player stats
   void Print();

   /// helper function for deconstructor
   void EmptyInventory();
   
  private: 
   ///Name of the player
   std::string name;
   
   ///Race of the player
   std::string race;
  
   ///Amount of keys player has
   int keys; 
};

