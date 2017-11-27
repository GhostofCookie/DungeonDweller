/// \date 25/10/2017
/// \author Tomas Rigaux
///
/// Derived from GameMenu. This is the menu for the player to choose their
/// character.

#include "GameMenu.h"
#include <map>
using namespace std;

#ifndef CHARACTERMENU_H
#define CHARACTERMENU_H

/// \class ExploreMenu ExploreMenu.h
/// \brief This is the menu displayed when the player character is being chosen
/// before the game begins.
class CharacterMenu : public GameMenu
{
  public:
   /// This is the default constructor.
   CharacterMenu();
   /// This is the virtual destructor.
   virtual ~CharacterMenu();
   /// This function sets the specific options for the Menu type.
   /// \param[in] row The row to start setting the options.
   /// \param[in] col The column to start aetting options.
   /// \param[in] space the space in-between options.
   virtual void SetOptions(int row, int col, int space);
   /// This function handles the input for the menu options.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput(istream &is);
};

#endif
