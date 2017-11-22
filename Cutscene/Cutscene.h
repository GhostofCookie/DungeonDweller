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
using namespace std;



/// This class runs cutscenes that improve the quality of room transitions
class Cutscene
{
  private:
   Screen screen;
   
   int startX = 0;
   int startY = 0;
   ImportImg img;
   ImportImg room;

   /// Helper function that returns many spaces
   void ClearScreen() { for(int i = 0; i < 50; i++) cout << endl; };


   
  public:
   /// Constructor
   Cutscene(ImportImg image, ImportImg r);
   /// Destructor
   ~Cutscene();

   void TopToCenter();
   void BottomToCenter();
   void LeftToCenter();
   void RightToCenter();

   void CenterToTop();
   void CenterToBottom();
   void CenterToLeft();
   void CenterToRight();

   void SaveCurrentPosition();
};

#endif
