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
   Cutscene cutscene = Cutscene();


   cutscene.MonsterEncounter();
   //cutscene.Intro();
   // cutscene.Outro();
   
   // runs 4 different DYNAMIC cutscene tests
   /*
   cutscene.EnterRight();
   cutscene.ExitUp();
   cutscene.EnterDown();
   cutscene.ExitRight();
   cutscene.EnterUp();
   cutscene.ExitDown();
   cutscene.EnterLeft();
   cutscene.ExitLeft();
   */
   
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
   
  
   return 0;
}
