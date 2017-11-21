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
   Screen *screen = new Screen();
   ImageImporter import = ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   ImportImg *img = new ImportImg(import.collection['@'][0]);

   // create a quick room to demonstrate movements
   Room *room = new Room(import.collection);

   // create a cutscene that uses this image
   Cutscene cutscene = Cutscene(*img, room->GetImage());

   
   // runs 4 different cutscene tests
   cutscene.CenterToTop(*screen);
   cutscene.TopToCenter(*screen);
   cutscene.CenterToBottom(*screen);
   //cutscene.CenterToLeft(*screen);
   //cutscene.CenterToRight(*screen);

   return 0;
}
