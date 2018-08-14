// Test file to run a random room generator (v1)
// Be sure to have all the files together when running
// might need ImageImporter classes

#include <iostream>
#include <vector>
//Screen headers
#include "Screen.h"
//Image headers
#include "../ImageImporter/ImageImporter.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
//Room Header
#include "../Room/Room.h"
//Time Headers
#ifdef ____linux____
#include <unistd.h>
#endif

#ifdef _WIN32
// Place windows unistd.h equivalent.
#endif
#include <ctime>




int main()
{
   //Needed for Room randomization
srand( (unsigned int) time(NULL));
	
   // The file path - ***change as desired
   std::string mastrFile = "../DD_Art/DD_MasterFileLinux.txt";
   
   // Display the rooms on a screen
   Screen *screen = new Screen();
   // Create an importer object and read in the masterFile
   ImageImporter imageImport = ImageImporter(mastrFile);
   // Store a bunch of rooms
   std::vector<Room*> rooms;
	
   // Generate random rooms and print them to the screen
   for(int i = 0; i < 50; i++)
   {
      rooms.push_back(new Room(imageImport.collection));
      rooms[i]->AlignCenter(*screen);
      rooms[i]->Draw(*screen);

//Print the current screen and then erase it for the next frame
std::cout << screen << std::endl;
screen->Erase();

}
	
   return 0;
}
