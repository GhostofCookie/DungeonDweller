#include <iostream>
#include "Cutscene.h"
#include "../ImageImporter/ImageImporter.h"
#include "../Screen/Screen.h"
#include "../Image/Image.h"
#include "../Image/ImportImg.h"
using namespace std;




int main()
{
   Screen *screen = new Screen();
   ImageImporter import = ImageImporter("../DD_Art/DD_MasterFileLinux.txt");
   ImportImg *img = new ImportImg(import.collection['@'][0]);

   // create a cutscene that uses this image
   Cutscene *cutscene = new Cutscene(*img);

   
   // runs 4 different cutscene tests
   cutscene->CenterToTop(*screen);
   cutscene->CenterToBottom(*screen);
   cutscene->CenterToLeft(*screen);
   cutscene->CenterToRight(*screen);

   return 0;
}
