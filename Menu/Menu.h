/// \author Tomas Rigaux
/// \date 21/10/2017
//
/// This is the Menu class. It handles the complicated inner workings of all
/// menus.
///

#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
using namespace std;

#ifndef MENU_H
#define MENU_H

/// \class Menu Menu.h
/// \brief This is the base class for all menus for the main game.
class Menu 
{
  protected:
   map<int,string> indexMap;
   map<char, void (*)(int)> optionMap;
   int menuHeight;
   int menuWidth;
   char **menu_Array;
  private:
   /// Builds the menu based on the options and outline to the dimensions
   /// specified by the constructor.
   void BuildMenu();
  public:
   /// Helper function to quit the game.
   /// \param[in] value This parameter serves to pass the function to the
   /// options map.
   static void QuitGame(int value);
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
   /// Sets the various options for the menu, mapping them to unique keys
   /// to make handling easier.
   /// \param[in] OptionsList A map of all the options for the current
   /// menu. Each option has a unique key to make input easier.
   /// \param[in] type This denotes the type of menu to display.
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
//   template<typename T>
//      void AddOption(char command, string optionName, void(T::*f)(int)=0);
      void AddOption(char command, string optionName, void(*f)(int)=0);
   /// A function to set the added options to the character array.
   /// \param[in] row Determines which row the options will start being set at.
   /// \param[in] col Determines which column the options will start from.
   /// \param[in] How mush space inbetween rows.
   virtual void SetOptions(int row=3, int col=3, int space=2);
   /// Handles the user input, and runs an option from the menu.
   /// \param[in,out] is The in-stream operator to read the input.
   virtual void HandleInput(istream& is);
   /// Display the multi-dimensional array.
   virtual void OutputMenu();
};

#endif
