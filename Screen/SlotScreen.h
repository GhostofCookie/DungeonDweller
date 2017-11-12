//
// SlotScreen.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef SlotScreen_h
#define SlotScreen_h

#include <iostream>
#include <vector>
#include "Screen.h"
using namespace std;

#define MAXSLOTS = 10


/// The SlotScreen class represents a screen that displays an array of images
class SlotScreen : public Screen
{
  private:
   /// The height of the image
   int height;
   /// The width of the image
   int width;
   /// The number of images to be ordered
   int slotCount;
   /// All images to be evenly printed
   vector<int> pictures;
	
	
	
  public:
   /// Constructs an Image object from the given dimensions
   /// \param[in] h the height of the image, default to 13
   /// \param[in] w the width of the image, default to 101
   /// \param[in] slots the amount of images to be evenly spaced, default to 1
   SlotScreen(int h = 13, int w = 101, int slots = 1);
   /// Destructor
   ~SlotScreen();
};

#endif /* SlotScreen_hpp */

