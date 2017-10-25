/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is the menu class for the Connect Four minigame. It is a subclass of
/// MinigameMenu.
///

#include "MinigameMenu.h"
#include <map>
using namespace std;

#ifndef CONNECTFOURMENU_H
#define CONNECTFOURMENU_H

/// \class ConnectFourMenu ConnectFourMenu.h
/// \brief This is the menu class for the Connect Four minigame.
class ConnectFourMenu : public virtual MinigameMenu
{
  public:
   /// This is the default constructor.
   ConnectFourMenu();
   /// This is the virtual destructor.
   virtual ~ConnectFourMenu();
   /// This function sets the specific options for the Menu type.
   /// \param[in] OptionsList A map of all the options for the current
   /// menu. Each option has a unique key to make input easier.
   /// \param[in] type This denotes the type of menu to display.
   virtual void SetOptions(map<string> optionsList, string type);
   /// This function handles the input for the menu options.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput(istream &is);

};

#endif
