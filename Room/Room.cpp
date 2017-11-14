#include "Room.h"

/// Default Constructor
Room::Room(map<char, vector<ImportImg>> &collection)
{
   //What type of room is generated e.g. treasure, puzzle, etc
   type = Rand(4);
	
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



/// Destructor
Room::~Room()
{
   delete room;
}



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
   ImportImg event = ImportImg("");

   /*
   switch(type)
   {
      //empty room
      case 0 :
	 break;
	 //NPC Shop
      case 1 :
	 event = ImportImg(collection['@'][1]);
	 event.AlignCenter(*room);
	 event.Image::ShiftUp(10);
	 event.Image::Draw(*room);
	 break;
	 //NPC Enemy	 
      case 2 :
	 event = ImportImg(collection['@'][2]);
	 event.AlignCenter(*room);
	 event.Image::ShiftUp(10);
	 event.Image::Draw(*room);
	 break;
	 //NPC Puzzle
      case 3 :
	 event = ImportImg(collection['@'][2]);
	 event.AlignCenter(*room);
	 event.Image::ShiftUp(10);
	 event.Image::Draw(*room);
	 break;
   }
   */
   // force draw the player after everything
   ImportImg img = ImportImg(collection['@'][0]);
   img.AlignCenter(*room);
   img.Image::Draw(*room);
}


void Room::AlignCenter(Screen &screen)
{
   room->AlignCenter(screen);
}



void Room::AlignLeft(Screen &screen)
{
   room->AlignLeft(screen);
}



void Room::AlignRight(Screen &screen)
{
   room->AlignRight(screen);
}



void Room::Draw(Screen &screen)
{
   room->Image::Draw(screen);
}



void Room::Draw(Screen &screen, int y, int x)
{
   room->Draw(screen, y, x);
}



/// Randomly selects a number from 0 to n-1
int Room::Rand(int n)
{
   n = rand() % n;
   return n;
}
