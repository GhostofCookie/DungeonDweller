/// \date 24/10/2017
/// \author Tomas Rigaux
///
/// This is the menu class for the Connect Four minigame. It is a subclass of
/// MinigameMenu.
///

#pragma once

#include "MinigameMenu.h"
#include <map>

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
   /// \param[in] row Determines which row the options will start being set at.
   /// \param[in] col Determines which column the options will start from.
   /// \param[in] How mush space inbetween rows.
   virtual void SetOptions(int row, int col, int space);
   /// This function handles the input for the menu options.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput( std::istream &is);
   /// Returns the chosen column.
   int GetColumn() const {return column;}
 private:
   int column;

};
