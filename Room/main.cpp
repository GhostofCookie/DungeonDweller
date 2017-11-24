#include <iostream>
#include "Room.h"
#include "../Screen/Screen.h"
#include "../Room/Room.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Image/Image.h"
#include "../Image/DefaultImg.h"
#include "../Image/ImportImg.h"
using namespace std;


int main()
{
   Screen screen = Screen();
   ImageImporter import("../DD_Art/DD_MasterFileLinux.txt");
   Room room = Room(import.collection);


   cout << room.GetType() << endl;
   room.AlignCenter(screen);
   room.Draw(screen);
   cout << screen << endl;


   
   return 0;
}
