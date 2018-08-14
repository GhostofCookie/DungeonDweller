/// \author Tomas Rigaux
/// \date 21/10/2017
///
/// This is the Menu class. It handles the complicated inner workings of all
/// menus.
///

#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>


#ifndef MENU_H
#define MENU_H

/// \class Menu Menu.h
/// \brief This is the base class for all menus for the main game.
class Menu 
{
 private:
  /// \var menu_Array This is the multi-dimensional array to display the menu
  char **menu_Array;
 protected:
 /// \var currOption This is the current option chosen.
  char currOption;
  /// \var indexMap This is the std::map used to display the options on the screen
  std::map < int,std::string > indexMap;
  /// \var menuHeight This is the height of the menu.
  int menuHeight;
  /// \var menuWidth This is the width of the menu.
  int menuWidth;

 public:
  /// This is the constructor. It initializes a multi-dimensional array
  /// to dimensions height*width.
  /// \param[in] height This is the height of the menu.
  /// \param[in] width This is the width of the menu.
  Menu(int height = 10, int width = 101);

  /// This is the destructor for the class. It is virtual.
  virtual ~Menu();

  /// Adds an option with a character for the user to call, a name to 
  /// display, and function to run.
  /// \param[in] command The character for the user to input.
  /// \param[in] optionName The name to display for the user.
  /// \param[in] f(int) The is the function which adds functionality to
  /// the option and command.
  void AddOption(char command, std::string optionName);
   
  /// Returns the option chosen by the user/player.
  /// \returns currOption
  char GetOption() const;

  /// A function to set the added options to the character array.
  /// \param[in] row Determines which row the options will start being set at.
  /// \param[in] col Determines which column the options will start from.
  /// \param[in] How mush space inbetween rows.
  virtual void SetOptions(int row = 3, int col = 3, int space = 2);

  /// Handles the user input, and runs an option from the menu.
  /// \param[in,out] is The in-stream operator to read the input.
  virtual void HandleInput( std::istream& is);

  /// Display the multi-dimensional array.
  virtual void OutputMenu();

 private:
  /// Builds the menu based on the options and outline to the dimensions
  /// specified by the constructor.
  void BuildMenu();

 protected:
  /// Sets the character of a specific location in the array to a give
  /// character.
  /// \param[in] x This is the x-coordinate of the multi-dimensional
  /// array. (A[x,y])
  /// \param[in] y This is the y-coordinate of the multi-dimensional
  /// array. (A[x,y])
  /// \param[in] ch This is the character to be set at the coordinates
  /// (x,y) in the multi-dimensional array.
  void Set(int x, int y, char ch);

};

#endif
