#include <iostream>
#include "Room.h"
#include "../Screen/Screen.h"
#include "../Room/Room.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"



int main()
{
   Screen screen = Screen();
   ImageImporter import("../DD_Art/DD_MasterFileLinux.txt");
   Room room = Room(import.collection);


   std::cout << room.GetType() << std::endl;
   room.AlignCenter(screen);
   room.Draw(screen);
   std::cout << screen << std::endl;


   
   return 0;
}
