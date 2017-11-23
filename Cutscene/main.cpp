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

   
   // runs 4 different cutscene tests
   /*
   cutscene.ExitCenterToTop();
   cutscene.EnterTopToCenter();
   cutscene.ExitCenterToBottom();
   cutscene.EnterBottomToCenter();
   cutscene.ExitCenterToLeft();
   cutscene.EnterLeftToCenter();
   cutscene.ExitCenterToRight();
   cutscene.EnterRightToCenter();
   */

   // runs 4 different DYNAMIC cutscene tests (run seperately!!)
   
   cutscene.ExitUp();
   cutscene.EnterDown();
   cutscene.ExitRight();
   cutscene.EnterRight();
   cutscene.ExitDown();
   cutscene.EnterRight();
   cutscene.ExitLeft();
   cutscene.EnterRight();
   
  
   return 0;
}
