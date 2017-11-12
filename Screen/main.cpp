// Test file to run a random room generator (v1)
// Be sure to have all the files together when running
// might need ImageImporter classes


/*
#include <iostream>
#include <vector>
//ScreenClass headers
#include "Screen.h"
#include "SlotScreen.h"
//Image headers
#include "ImageImporter.h"
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
//Room Header
#include "Room.h"
//Time Headers
#include <unistd.h>//for slowing down time
#include <ctime>
using namespace std;



int main()
{
   //Needed for Room randomization
   srand( (unsigned int) time(NULL));
	
   // The file path - ***change as desired
   string mastrFile = "DD_MasterFile.txt";
   
   // Display the rooms on a screen
   Screen *screen = new Screen();
   // Create an importer object and read in the masterFile
   ImageImporter imageImport = ImageImporter(mastrFile);
   // Store a bunch of rooms
   vector<Room*> rooms;
	
   // Generate random rooms and print them to the screen
   for(int i = 0; i < 50; i++)
   {
      rooms.push_back(new Room(imageImport.collection));
      rooms[i]->AlignCenter(*screen);
      rooms[i]->Draw(*screen);
		
      //Print the current screen and then erase it for the next frame
      cout << screen;
      screen->Erase();
   }
	
   return 0;
}
*/
