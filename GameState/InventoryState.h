/// \date 25/11/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is checking inventory
///

#include "GameState.h"
#include "../Menu/ExploreMenu.h"
#include "../Cutscene/Cutscene.h"
#include "../Room/Room.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
#include <ctime>
#include <iostream>
using namespace std;

#ifndef INVENTORYSTATE_H
#define INVENTORYSTATE_H

/// \class ExploreState ExploreState.h
/// \brief This is defines the state of the game when the player character is
/// exploring rooms. Derived from GameState.
class InventoryState : public GameState
{
  public:
   /// This is the the default constructor.
   InventoryState();
   /// This is the default destructor.
   ~InventoryState();
   /// Sets the layout for the game menu and screen.
   void Set();
   /// Gets the layout for the game menu and screen.
   void Get();
