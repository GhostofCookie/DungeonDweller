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

   /// variable to keep track of a position for animating
   int startX = 0;
   /// variable to keep track of a position for animating
   int startY = 0;

   /// variable to keep track of a character found
   int foundX = 0;
   /// variable to keep track of character found
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

   void TopToCenter();
   void BottomToCenter();
   void LeftToCenter();
   void RightToCenter();

   void CenterToTop();
   void CenterToBottom();
   void CenterToLeft();
   void CenterToRight();

   void DownToLeft(const int yD, const int xD, const int nD, const int yL, const int xL, const int nL);
   void DownToRight(const int yD, const int xD, const int nD, const int yR, const int xR, const int nR);
   void UpToLeft(const int yU, const int xU, const int nU, const int yL, const int xL, const int nL);
   void UpToRight(const int yU, const int xU, const int nU, const int yR, const int xR, const int nR);
   void RightToUp(const int yR, const int xR, const int nR, const int yU, const int xU, const int nU);
   void RightToDown(const int yR, const int xR, const int nR, const int yD, const int xD, const int nD);
   void LeftToUp(const int yL, const int xL, const int nL, const int yU, const int xU, const int nU);
   void LeftToDown(const int yL, const int xL, const int nL, const int yD, const int xD, const int nD);

   void SaveCurrentPosition();
};

#endif
