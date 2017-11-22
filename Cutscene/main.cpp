#include <iostream>
#include "Cutscene.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Screen/Screen.h"
#include "../Image/Image.h"
#include "../Image/ImportImg.h"
#include "../Room/Room.h"
using namespace std;




int main()
{
   ImageImporter import = ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   ImportImg *img = new ImportImg(import.collection['@'][0]);

   // create a quick room to demonstrate movements
   Room *room = new Room(import.collection);

   // create a cutscene that uses this image
   Cutscene cutscene = Cutscene(*img, room->GetImage());

   
   // runs 4 different cutscene tests
   cutscene.CenterToTop();
   cutscene.TopToCenter();
   cutscene.CenterToBottom();
   //cutscene.CenterToLeft();
   //cutscene.CenterToRight();

   return 0;
}
