//
// puzzle.h
//
/// \author Tyler Siwy
/// \date Oct 20, 2017
///

#ifndef PUZZLE_H
#define PUZZLE_H

#include "../Menu/Menu.h"
#include "../Screen/Screen.h"

#include <vector>

///This class represents an abstract base class for each mini-game/puzzle to
///derive from.
class Puzzle
{
  public:
   ///Virtual Destructor
   virtual ~Puzzle(){}
   ///Method to run the game, serves as a 'main' for the mini-game, calling
   ///functions from private until the player has won.                          
   virtual void RunGame();

   ///Remains false until the mini-game/puzzle is ready to be terminated.
   bool PuzzleEnd;
  private:
   //ALL HANDLED BY MENU OBJECT?
   //virtual void PromptUser(screen &screen);
   //virtual char UserInput(Menu &menu);
   //virtual bool ValidCommand(char input);

   ///Checks whether the move that is to be attempted is valid.  
   /// \param[in] input, Checks the input for semantic logic, otherwise error
   virtual bool ValidMove(char input)=0;
   ///Does the appropriate action to the space selected by the user depending on
   ///which puzzle derived class it is being used in.
   virtual void MovePiece()=0;
   /// Displays the screen containing the gameboard
   /// \param[in] screen, the screen object used for displaying the game. 
   virtual void OutputGame(Screen &screen)=0;
   ///Sends the menu class the options for the player to select.
   virtual void SetOptionsInMenu()=0;
   ///Sets values to the screen object in each game
   /// \param[in]xCoordinate, the coodriante to set on the x-axis
   /// \param[in]yCoordinate, the coordinate to set on the y-axis
   virtual void SetScreen(int xCoordinate, int yCoordinate)=0;
   ///Clears spaces in screen appropriately.
   /// \param[in]xCoordinate, the coodriante to clear on the x-axis
   /// \param[in]yCoordinate, the coordinate to clear on the y-axis                                                                                                                                             
   virtual void ClearScreenSpace(int xCoordinate, int yCoordinate)=0;
   ///Used to output prompts, take in user input, and handle formatting errors
   //PuzzleMenu *Menu;

   ///Used to display the gameboard to the user.
   //PuzzleScreen *Screen;
};
#endif
