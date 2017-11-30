/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This is the state of the game when a player is exploring.
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
   ~ExploreState();
  //*******************************************************************************
   ExploreState(GameState &obj);
 
   ///Const copy constructor
   ///\param[in] state reference to an explore state
   ExploreState(const ExploreState &obj);
   //*******************************************************************************
   /// Default copy constructor
   /// \param[in] state reference to an 
   ExploreState(ExploreState &obj);

/// Sets the layout for the game menu and screen.
   void Set();
   /// Gets the layout for the game menu and screen.
   void Get();

   
  private:
   /// Helper function to set the current state of the game based on the current
   /// room type.
   /// \param[in] type Defines the type of room the player is in.
   void SetState(int type);
   /// Helper function to give input functionality
   ///\param[in] option The current option chosen by the player.
   void RunInput(char option);
   ImageImporter *import;
   Room *roomPtr;
};

#endif
