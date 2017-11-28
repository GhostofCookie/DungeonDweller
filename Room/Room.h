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
//Character Headers
#include "../Character/Character.h"
#include "../Character/Player.h"
#include "../Character/Npc.h"
//Item Header
#include "../Item/Item.h"
#include "../Item/MyConsumables.h"
#include "../Item/MyWeapons.h"
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
   ImportImg *room = nullptr;
   /// The type of room that will be generated
   int type;
   /// An NPC that can be displayed in a room
   Character npc;
   
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
   Room(map<char, vector<ImportImg>> &imgFiles, int type = -1, bool c = true);
   /// Copy Constructor
   /// \param[in] r the room being copied
   Room(Room &r);
   /// Copy Constructor
   /// \param[in] r the room being copied
   Room(const Room &r);
   /// Destroys the object
   ~Room();

   /// The points of each image's key character
   vector<Point> point; // stores the points to each key

   /// To indicate if a room has any events that need to take place
   bool complete;

   /// Function that returns the image object
   ImportImg& GetImage() const;
   
   /// Function that returns the room's image file path
   string GetImageFile() const;
   
   /// Function that returns the room's type
   int GetType() const;

   /// Function that returns the room's type
   bool IsComplete() const;
   
   /// Function to align to the center of the screen
   /// \param[in] screen the screen drawn on
   void AlignCenter(Screen &screen);
   
   /// Function to align to the left of the screen
   /// \param[in] screen the screen drawn on
   void AlignLeft(Screen &screen);
   
   /// Function to align to the right of the screen
   /// \param[in] screen the screen drawn on
   void AlignRight(Screen &screen);
   
   /// Function to align to the top of the screen
   /// \param[in] screen the screen drawn on
   void AlignTop(Screen &screen);
   /// Function to align the room to the bottom of the screen
   /// \param[in] screen the screen drawn on
   void AlignBottom(Screen &screen);
	
   /// Function to draw to the screen
   /// \param[in] screen the screen drawn on
   void Draw(Screen &screen);
   
   /// Function to draw to the screen
   /// \param[in] screen the screen drawn on
   void Draw(Screen &screen, int y, int x);

    /// Function to draw to the screen
   /// \param[in] img the img drawn on
   void Draw(ImportImg &img);

    /// Function to draw to the screen
   /// \param[in] img the img drawn on
   void Draw(ImportImg &img, int y, int x);
   
   /// Function to return the npc
   Character& GetNpc() { return npc; }
};
#endif /* Room_h */
