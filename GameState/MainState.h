/// \date 21/10/2017
/// \author Tomas Rigaux
///
/// This class is derived from the GameState abstract class. It sets the state
/// of the game.
///

#include "GameState.h"
#include "../Cutscene/Cutscene.h"
#include "../Menu/MainMenu.h"

#pragma once

/// \class MainState MainState.h
/// \brief This is the state of the game when the game is either not yet started or the game has ended.
/// Derived from GameState.
class MainState : public GameState
{
  public:
   /// Default constructor
   MainState();
   /// Default destructor
   ~MainState();
   /// Sets the layout of the game.
   void Set();
   /// Outputs the set layout.
   void Get();

};
