#ifndef Cutscene_h
#define Cutscene_h

// Screen Header
#include "../Screen/Screen.h"
// Image Headers
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
// Room Header
#include "../Room/Room.h"
// Misc Headers
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
using namespace std;



/// \brief This class runs cutscenes that improve the quality of room transitions
class Cutscene
{
   /// Struct to contain the points of all 4 exits in a room
   struct Point
   {
      int y = 0;
      int x = 0;
   };


   
  private:
   /// screen to draw the cutscene on
   Screen screen;
   /// screen to create the left-side space
   Screen leftSide;
   /// screen to create the right-side space
   Screen rightSide;

   /// x coordinate to keep track of the center ALWAYS
   int centerX = 0;
   /// y coordinate to keep track of the center ALWAYS
   int centerY = 0;
   /// variable to keep track of a position for animating
   int savedX = 0;
   /// variable to keep track of a position for animating
   int savedY = 0;
   /// temporary variable to keep track of a character found
   int foundX = 0;
   /// temporary variable to keep track of character found
   int foundY = 0;

   /// container to store the 4 directions of the given room
   vector<Point> point;

   /// the animated image
   ImportImg img;
   /// the room to be animated in
   ImportImg room;

   /// Helper function that returns many spaces
   void ClearScreen() { for(int i = 0; i < 50; i++) cout << endl; };
   
   /// Helper function that returns the location of a character
   /// Helper function to shift an image up and handle output
   /// \param[in] y the y coordinate to save
   /// \param[in] x the x coordinate to save
   /// \param[in] c the character to look for
   /// \param[in] r the room to gain access to its points
   void FindCharacter(int &y, int &x, const char c, const Room &r);

   /// Helper function to shift an image up and handle output
   /// \param[in] originY the y coordinate to begin from
   /// \param[in] originX the x coordinate to begin from
   /// \param[in] count the amount to move by
   void MoveUp(const int originY, const int originX, const int count);
   
   /// Helper function to shift an image down and handle output
   /// Helper function to shift an image up and handle output
   /// \param[in] originY the y coordinate to begin from
   /// \param[in] originX the x coordinate to begin from
   /// \param[in] count the amount to move by
   void MoveDown(const int originY, const int originX, const int count);
   
   /// Helper function to shift an image left and handle output
   /// Helper function to shift an image up and handle output
   /// \param[in] originY the y coordinate to begin from
   /// \param[in] originX the x coordinate to begin from
   /// \param[in] count the amount to move by
   void MoveLeft(const int originY, const int originX, const int count);
   
   /// Helper function to shift an image right and handle output
   /// Helper function to shift an image up and handle output
   /// \param[in] originY the y coordinate to begin from
   /// \param[in] originX the x coordinate to begin from
   /// \param[in] count the amount to move by
   void MoveRight(const int originY, const int originX, const int count);
   
   
   
  public:
   /// Constructor
   Cutscene(ImportImg image = ImportImg("../DD_Art/Player/DD_Player.txt"),
	    ImportImg r = ImportImg("../DD_Art/Player/DD_Player.txt"),
	    Room *roomTemplate = nullptr);
   /// Destructor
   ~Cutscene();

   /// Function to animate an image this direction
   void EnterTopToCenter();
   
   /// Function to animate an image this direction
   void EnterBottomToCenter();
   
   /// Function to animate an image this direction   
   void EnterLeftToCenter();
   
   /// Function to animate an image this direction
   void EnterRightToCenter();
   
   /// Function to animate an image this direction
   void ExitCenterToTop();
   
   /// Function to animate an image this direction
   void ExitCenterToBottom();
   
   /// Function to animate an image this direction
   void ExitCenterToLeft();
   
   /// Function to animate an image this direction
   void ExitCenterToRight();
   
   /// Function to animate an image to the left
   void ExitLeft();
   
   /// Function to animate an image to the right
   void ExitRight();
   
   /// Function to animate an image to the top
   void ExitUp();
   
   /// Function to animate an image to the left
   void ExitDown();
   
   /// Function to animate an image from the left
   void EnterLeft();
   
   /// Function to animate an image from the right
   void EnterRight();
   
   /// Function to animate an image from the top
   void EnterUp();
   
   /// Function to animate an image from the bottom
   void EnterDown();
   
   /// Function to save the animated image's current position
   void SaveCurrentPosition();

   /// Function to animate an intro * hardcoded in every cutscene obj
   void Intro();

   /// Function to animate an outro * hardcoded in every cutscene obj
   void Outro();
};

#endif
