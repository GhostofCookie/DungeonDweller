#include <iostream>
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
#include "../Screen/Screen.h"
using namespace std;



int main()
{
   Screen *screen = new Screen();
   DefaultImg *img = new DefaultImg(6, 6, '#');

   img->AlignCenter(*screen);
   img->Draw(*screen);

   cout << screen << endl;
   screen->Erase();

   img->Fill('!');
   img->Draw(*screen);

   cout << screen << endl;
   screen->Erase();
   
   return 0;
}
