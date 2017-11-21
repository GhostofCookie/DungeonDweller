#include "Cutscene.h"

Cutscene::Cutscene(ImportImg image, ImportImg r)
{
   img = ImportImg(image);
   room = ImportImg(r);
   cout << room.GetImageFile() << ", " << room.GetRows() << endl;
   startX = img.screenX;
   startY = img.screenY;
}



Cutscene::~Cutscene()
{

}



void Cutscene::TopToCenter(Screen &screen)
{
   // Center the room for the cutscene
   room.AlignCenter(screen);
   cout << "screenX: " << room.screenX << ", screenY: " << room.screenY << endl;
   cout << "width: " << room.GetCols() << ", height: " << room.GetRows() << endl;

   
   // Set up the position of the image to animate
   img.AlignCenter(screen);
   SaveCurrentPosition();
   img.AlignTop(screen);

   // This loop will animate the image and print to the screen
   int n = img.screenY;
   while(n < startY)
   {
      img.ShiftDown(screen, 1);
      n++;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(100000);
   }
}



void Cutscene::BottomToCenter(Screen &screen) {}



void Cutscene::LeftToCenter(Screen &screen) {}



void Cutscene::RightToCenter(Screen &screen) {}



void Cutscene::CenterToTop(Screen &screen)
{
   // Set the image to the center for the animation
   room.AlignCenter(screen);
   // Set the image to be animated
   img.AlignCenter(screen);

   
   // This loop will set the image and print to the screen
   int n = img.screenY;
   while(n >= 0)
   {
      img.ShiftUp(1);
      n--;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(100000);
   }
}



void Cutscene::CenterToBottom(Screen &screen)
{
   // Set the room to the center for the animation
   room.AlignCenter(screen);
   // Set the image to be animated
   img.AlignCenter(screen);

   // This loop will set the image and print to the screen
   int n = img.screenY;
   while(n < screen.GetRows())
   {
      img.ShiftDown(screen, 1);
      n++;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(100000);
   }
}



void Cutscene::CenterToLeft(Screen &screen)
{
   // Set the room to the center for the animation
   room.AlignCenter(screen);
   // Set the image to be animated
   img.AlignCenter(screen);

   
   int n = img.screenX;
   while(n >= 0)
   {
      img.ShiftLeft(1);
      n--;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(50000);
   }
}



void Cutscene::CenterToRight(Screen &screen)
{
   // Set the room to the center for the animation
   room.AlignCenter(screen);
   // Set the image to be animated
   img.AlignCenter(screen);

   
   int n = img.screenX;
   while(n < screen.GetCols())
   {
      img.ShiftRight(screen, 1);
      n++;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(50000);
   }
}



void Cutscene::SaveCurrentPosition()
{
   // save the latest coordinates passed to it
   startX = img.screenX;
   startY = img.screenY;
}
