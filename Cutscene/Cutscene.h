#ifndef Cutscene_h
#define Cutscene_h

// Screen Header
#include "../Screen/Screen.h"
// Image Headers
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
// Misc Headers
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;



/// This class runs cutscenes that imporve the quality of room transitions
class Cutscene
{
  private:
   int startX = 0;
   int startY = 0;
   ImportImg *img;


   /// Helper function that returns many spaces
   void ClearScreen() { for(int i = 0; i < 50; i++) cout << endl; };
   
  public:
   /// Constructor
   Cutscene(ImportImg image);
   /// Destructor
   ~Cutscene();

   void TopToCenter(Screen&);
   void BottomToCenter(Screen&);
   void LeftToCenter(Screen&);
   void RightToCenter(Screen&);

   void CenterToTop(Screen&);
   void CenterToBottom(Screen&);
   void CenterToLeft(Screen&);
   void CenterToRight(Screen&);

   void SaveCurrentPosition();
};

#endif
