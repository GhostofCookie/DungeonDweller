#include <iostream>
#include "Room.h"
#include "Screen.h"
#include "Room.h"
#include "ImageImporter.h"
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"



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
