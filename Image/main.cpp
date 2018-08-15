#include <iostream>
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
#include "../Screen/Screen.h"

int main()
{
   Screen *screen = new Screen();
   DefaultImg *img = new DefaultImg(6, 6, '#');

   img->AlignCenter(*screen);
   img->Draw(*screen);

   std::cout << screen << std::endl;
   screen->Erase();

   img->Fill('!');
   img->Draw(*screen);

   std::cout << screen << std::endl;
   screen->Erase();
   
   return 0;
}
