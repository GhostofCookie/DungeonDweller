#include "Cutscene.h"

Cutscene::Cutscene(ImportImg image)
{
   img = new ImportImg(image);
   startX = image.screenX;
   startY = image.screenY;
}



Cutscene::~Cutscene()
{

}



void Cutscene::TopToCenter(Screen &screen)
{

}

void Cutscene::BottomToCenter(Screen &screen) {}

void Cutscene::LeftToCenter(Screen &screen) {}

void Cutscene::RightToCenter(Screen &screen) {}

void Cutscene::CenterToTop(Screen &screen)
{
   img->AlignCenter(screen);
   
   int n = img->screenY;
 
   while(n >= 0)
   {
      img->ShiftUp(1);
      n--;

      ClearScreen();
      screen.Erase();
      img->Draw(screen);
      cout << screen << endl;
      usleep(100000);
   }
}

void Cutscene::CenterToBottom(Screen &screen)
{
   img->AlignCenter(screen);

   int n = img->screenY;

   while(n < screen.GetRows())
   {
      img->ShiftDown(screen, 1);
      n++;

      ClearScreen();
      screen.Erase();
      img->Draw(screen);
      cout << screen << endl;
      usleep(100000);
   }
}

void Cutscene::CenterToLeft(Screen &screen)
{
   img->AlignCenter(screen);

   int n = img->screenX;

   while(n >= 0)
   {
      img->ShiftLeft(1);
      n--;

      ClearScreen();
      screen.Erase();
      img->Draw(screen);
      cout << screen << endl;
      usleep(50000);
   }
}

void Cutscene::CenterToRight(Screen &screen)
{
   img->AlignCenter(screen);

   int n = img->screenX;

   while(n < screen.GetCols())
   {
      img->ShiftRight(screen, 1);
      n++;

      ClearScreen();
      screen.Erase();
      img->Draw(screen);
      cout << screen << endl;
      usleep(50000);
   }
}

void Cutscene::SaveCurrentPosition()
{
   
}
