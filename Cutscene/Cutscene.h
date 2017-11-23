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



/// This class runs cutscenes that improve the quality of room transitions
class Cutscene
{
   struct Point
   {
      int y = 0;
      int x = 0;
   };


   
  private:
   /// A screen to draw the cutscene on
   Screen screen;

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
   
   ImportImg img;
   ImportImg room;

   /// Helper function that returns many spaces
   void ClearScreen() { for(int i = 0; i < 50; i++) cout << endl; };
   /// Helper function that returns the location of a character
   void FindCharacter(int &y, int &x, const char c, const Room &r);

   
   
   
  public:
   /// Constructor
   Cutscene(ImportImg image, ImportImg r, Room &roomTemplate);
   /// Destructor
   ~Cutscene();

   void MoveUp(const int originX, const int originY, const int y);
   void MoveDown(const int originX, const int originY, const int y);
   void MoveLeft(const int originX, const int originY, const int y);
   void MoveRight(const int originX, const int originY, const int y);

   void EnterTopToCenter();
   void EnterBottomToCenter();
   void EnterLeftToCenter();
   void EnterRightToCenter();

   void ExitCenterToTop();
   void ExitCenterToBottom();
   void ExitCenterToLeft();
   void ExitCenterToRight();

   void ExitLeft();
   void ExitRight();
   void ExitUp();
   void ExitDown();

   void EnterLeft();
   void EnterRight();
   void EnterUp();
   void EnterDown();

   void SaveCurrentPosition();
};

#endif
