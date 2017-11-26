#include "Room.h"
#define ROOMTYPES 4



/// Default Constructor
/// \param[in] collection the images used to generate a room
Room::Room(map<char, vector<ImportImg>> &collection, int t, bool c)
   : type{t}, complete{c}
{
   // What type of room is generated e.g. treasure, puzzle, etc
   if(type < 0 || type > ROOMTYPES)
      type = RoomChance();
   // If an enemy room or Puzzle room
   if(type == 2 || type == 3)
      complete = false;
   
	
   // Find out how many rooms there are to pick from
   // All rooms are located at '0' in the map
   int roomCount = 0;
   for(unsigned int i = 0; i < collection['0'].size(); ++i)
      roomCount++;
	
   // Decides on one of the rooms in that set
   int num = Rand(roomCount);
   room = new ImportImg(collection['0'][num]);
	
   //Insert the appropriate images to fill the room
   GetRoom(collection);
   GetEventImages(collection);
}



/// Copy Constructor
Room::Room(Room &r)
{
   string s = r.GetImageFile();
   delete room;
   room = new ImportImg(s);

   type = r.GetType();
}



/// Copy Constructor
Room::Room(const Room &r)
{
   string s = r.GetImageFile();
   delete room;
   room = new ImportImg(s);

   type = r.GetType();
}



/// Destructor
Room::~Room() { delete room; }



/// Function to return the image
ImportImg Room::GetImage() const { return *room; }



/// Function to return the image file path
string Room::GetImageFile() const { return room->GetImageFile(); }



/// Function to return the type
int Room::GetType() const { return type; }



/// Function to return whether or not the room has an event to do
bool Room::IsComplete() const { return complete; }



/// Function decides which images need to be assigned to the room
/// \param[in] collection, the set of images passed
void Room::GetRoom(map<char, vector<ImportImg>> &collection)
{
   map<char, int> setType;
	
   GetPoints();
	
   // Finds the correct images using points and then prints them onto room image
   for(unsigned int i = 0; i < point.size(); i++)
   {
      // Decides on a varient if there are more than 1 type of object
      if(collection[point[i].ch].size() > 1)
	 setType.insert(pair<char, int>(point[i].ch, Rand(collection[point[i].ch].size())));
      else
	 setType[point[i].ch] = 0;

      int num = setType.at(point[i].ch);
		
      // Permanently draws that object to the location on the room
      ImportImg img = collection[point[i].ch][num];
      img.AlignCenter(*room, point[i].x, point[i].y);
      img.Image::Draw(*room);
   }
}



/// Function that identifies key characters and sets their location
void Room::GetPoints()
{
   // Move through the room image and save the locations found as a point
   for(int y = 0; y < room->GetRows(); ++y)
   {
      // seperates the characters from the digits (up, down, left, right)
      // that way they print over the rest of the images
      for(int x = 0; x < room->GetCols(); ++x)
      {
	 if(isalpha(room->Img[y][x]))
	 {
	    Point p;
	    p.x = x; p.y = y; p.ch = room->Img[y][x];
	    point.insert(point.begin(), p);
				
	 } else if(isdigit(room->Img[y][x]))
	 {
	    Point p;
	    p.x = x; p.y = y; p.ch = room->Img[y][x];
	    point.push_back(p);
	 }
      }
   }
}



/// Helper function to determine what to draw in the room based on type
void Room::GetEventImages(map<char, vector<ImportImg>> &collection)
{  
   ImportImg event = ImportImg(collection['@'][0]);//assign it just to avoid error
   
   switch(type)
   {
      //empty room
      case 0 :
	 break;
	 //NPC Shop
      case 1 :
	 event = ImportImg(collection['@'][1]);
	 event.AlignCenter(*room);
	 event.Image::ShiftRight(*room, 10);
	 event.Image::Draw(*room);
	 break;
	 //NPC Enemy	 
      case 2 :
	 event = ImportImg(collection['@'][2]);
	 event.AlignCenter(*room);
	 event.Image::ShiftRight(*room, 10);
	 event.Image::Draw(*room);
	 break;
	 //NPC Puzzle
      case 3 :
	 event = ImportImg(collection['@'][3]);
	 event.AlignCenter(*room);
	 event.Image::ShiftRight(*room, 10);
	 event.Image::Draw(*room);
	 break;
   }
}



/// Function aligns the room to the center to the screen
/// \param[in] screen The screen that is passed
void Room::AlignCenter(Screen &screen) { room->Image::AlignCenter(screen); }



/// Function aligns the room to the center to the screen
/// \param[in] screen The screen that is passed
void Room::AlignLeft(Screen &screen) { room->Image::AlignLeft(screen); }



/// Function aligns the room to the center to the screen
/// \param[in] screen The screen that is passed
void Room::AlignRight(Screen &screen) { room->Image::AlignRight(screen); }



/// Function aligns the room to the top to the screen
/// \param[in] screen The screen that is passed
void Room::AlignTop(Screen &screen) { room->Image::AlignTop(screen); }



/// Function aligns the room to the bottom to the screen
/// \param[in] screen The screen that is passed
void Room::AlignBottom(Screen &screen) { room->Image::AlignBottom(screen); }



/// Function aligns the room to the center to the screen
/// \param[in] screen The screen that is passed
void Room::Draw(Screen &screen) { room->Image::Draw(screen); }



/// Function aligns the room to the center to the screen
/// \param[in] screen The screen that is passed
/// \param[in] y the y coordinate
/// \param[in] x The x coordinate
void Room::Draw(Screen &screen, int y, int x) { room->Image::Draw(screen, y, x); }



/// Randomly selects a number from 0 to n-1
/// \param[in] n the range 0-n
int Room::Rand(int n)
{
   n = rand() % n;
   return n;
}



/// Function generate a roomType using a basic random # with weighting %
int Room::RoomChance()
{  
   bool selected = false;
   vector<int> chance = {57, 10, 0, 5}; // weight
   int roomType = 0;

   int outOf = 0; // total of the weights
   for(int i = 0; i < ROOMTYPES; i++)
      outOf += chance[i];


   // Function runs while a room has not been chosen
   do
   {
      // allows the index to start at a random location in the vector
      for(int r = Rand(ROOMTYPES); r < ROOMTYPES; r++)
      {
	 int n = Rand(outOf);
	 // trys to generate a random number less than the chance %
	 if(n < chance[r])
	 {
	    selected = true;
	    roomType = r;
	 }
      }
   }
   while(!selected);

   return roomType;
}
