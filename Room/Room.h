//
// Room.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef Room_h
#define Room_h

#include <iostream>
#include <map>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <algorithm>
//Screen Header
#include "../Screen/Screen.h"
//Image Headers
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
using namespace std;


/// The Room class defines random values that characterize a room's event.
/// It also applies appropriate images onto a given room image
class Room
{
   /// A struct used to contain the location of characters from a room
   struct Point
   {
      // x coordinate
      int x = -1;
      // y coordinate
      int y = -1;
      // character stored
      char ch;
   };
	
  private:
   /// A finalized version of the room with data values included
   // Public to allow user to use all the image functions from the room object
   ImportImg *room;
   /// The type of room that will be generated
   int type;
   /// The points of each image's key character
   vector<Point> point; // stores the points to each key
	
   /// Helper function to output a random value from 0 - n
   /// \param[in] n the range of the random number generated
   int Rand(int n);
   /// Function to choose a random type - with weighting
   int RoomChance();
   /// Constructs a Room object using the given image
   /// \param[in] imgFiles collects all 'event' images for the rooms
   void GetRoom(map<char, vector<ImportImg>> &imgFiles);
   /// Locates the key characters used to print other images to the room
   void GetPoints();
   /// Print event images to the room based on type
   /// \param[in] imgFiles the collection of images to use
   void GetEventImages(map<char, vector<ImportImg>> &imgFiles);
	
	
  public:
   /// Constructs a Room object using the given image
   /// \param[in] imgFiles the image used as the room
   Room(map<char, vector<ImportImg>> &imgFiles);
   /// Destroys the object
   ~Room();
	
   /// Function to align to the center of the screen
   /// \param[in] screen the screen drawn on
   void AlignCenter(Screen &screen);
   /// Function to align to the left of the screen
   /// \param[in] screen the screen drawn on
   void AlignLeft(Screen &screen);
   /// Function to align to the right of the screen
   /// \param[in] screen the screen drawn on
   void AlignRight(Screen &screen);
	
   /// Function to draw to the screen
   /// \param[in] screen the screen drawn on
   void Draw(Screen &screen);
   /// Function to draw to the screen
   /// \param[in] screen the screen drawn on
   void Draw(Screen &screen, int y, int x);
};
#endif /* Room_h */
