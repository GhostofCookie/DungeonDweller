/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is exploring.
///

#include "GameState.h"
#include "../Menu/ExploreMenu.h"
#include "../Cutscene/Cutscene.h"
#include "../RoomTree/RoomTree.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
#include <iostream>
using namespace std;

#ifndef EXPLORESTATE_H
#define EXPLORESTATE_H

/// \class ExploreState ExploreState.h
/// \brief This is defines the state of the game when the player character is
/// exploring rooms. Derived from GameState.
class ExploreState : public GameState
{
  public:
   /// This is the the default constructor.
   ExploreState();
   /// This is the default destructor.
   ~ExploreState(){}
   /// Sets the layout for the game menu and screen.
   void Set();
   /// Gets the layout for the game menu and screen.
   void Get();
  private:
   void SwitchRooms();
   ImageImporter imageImport;
   Room *roomPtr;
   RoomTree *roomTree;
   Cutscene *anim;
   string masterFile;


};

#endif
