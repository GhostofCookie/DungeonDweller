#include <iostream>
#include <ctime>
#include "Cutscene.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Screen/Screen.h"
#include "../Image/Image.h"
#include "../Image/ImportImg.h"
#include "../Room/Room.h"
using namespace std;




int main()
{
   srand( (unsigned int) time(NULL));
   
   ImageImporter import = ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   ImportImg *img = new ImportImg(import.collection['@'][0]);

   // create a quick room to demonstrate movements
   Room *room = new Room(import.collection);

   // create a cutscene that uses this image
   Cutscene cutscene = Cutscene(*img, room->GetImage(), *room);


   //cutscene.LeftToUp(1,1,1,1,1,1);
   // runs 4 different cutscene tests
   cutscene.CenterToTop();
   cutscene.TopToCenter();
   cutscene.CenterToBottom();
   cutscene.BottomToCenter();
   cutscene.CenterToLeft();
   cutscene.LeftToCenter();
   cutscene.CenterToRight();
   cutscene.RightToCenter();

   return 0;
}
