/// \date 25/10/2017
/// \author Tomas Rigaux
///
/// Derived from GameMenu. This is the menu for the player character to use when
/// they are interacting in dialogue with NPCs in the game.

#include "GameMenu.h"
#include <map>
using namespace std;

#ifndef DIALOGUEMENU_H
#define DIALOGUEMENU_H

/// \class ExploreMenu ExploreMenu.h
/// \brief This is the menu displayed when the player character is engaging in
/// dialogue with an NPC.
class DialogueMenu : public GameMenu
{
  public:
   /// This is the default constructor.
   DialogueMenu();
   /// This is the virtual destructor.
   virtual ~DialogueMenu();
   /// This function sets the specific options for the Menu type.
   /// \param[in] OptionsList A map of all the options for the current menu.
   /// Each option has a unique key to make input easier.
   /// \param[in] type This denotes the type of menu to display.
   virtual void SetOptions(map<int,string> optionsList, int row, int col);
   /// This function handles the input for the menu options.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput(istream &is);
};

#endif