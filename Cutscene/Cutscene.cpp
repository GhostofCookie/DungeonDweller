#include "Cutscene.h"
#define HORIZSPEED 60000
#define VERTSPEED 120000


Cutscene::Cutscene(ImportImg image, ImportImg r)
{
   screen = Screen();
   
   img = ImportImg(image);
   room = ImportImg(r);
   cout << room.GetImageFile() << ", " << room.GetRows() << endl;
   startX = img.screenX;
   startY = img.screenY;
}



Cutscene::~Cutscene()
{

}



void Cutscene::TopToCenter()
{
   // Center the room for the cutscene
   room.AlignCenter(screen);
   
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
      usleep(VERTSPEED);
   }
}



void Cutscene::BottomToCenter()
{
   // Center the room for the cutscene
   room.AlignCenter(screen);
   
   // Set up the position of the image to animate
   img.AlignCenter(screen);
   SaveCurrentPosition();
   img.AlignBottom(screen);

   // This loop will animate the image and print to the screen
   int n = img.screenY;
   while(n > startY)
   {
      img.ShiftUp(1);
      n--;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(VERTSPEED);
   }
}



void Cutscene::LeftToCenter()
{
// Center the room for the cutscene
   room.AlignCenter(screen);

   // Set up the position of the image to animate
   img.AlignCenter(screen);
   SaveCurrentPosition();
   img.AlignLeft(screen);

   // This loop will animate the image and print to the screen
   int n = img.screenX;
   while(n < startX)
   {
      img.ShiftRight(screen, 1);
      n++;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(HORIZSPEED);
   }
}



void Cutscene::RightToCenter()
{
   // Center the room for the cutscene
   room.AlignCenter(screen);
   
   // Set up the position of the image to animate
   img.AlignCenter(screen);
   SaveCurrentPosition();
   img.AlignRight(screen);

   // This loop will animate the image and print to the screen
   int n = img.screenX;
   while(n > startX)
   {
      img.ShiftLeft(1);
      n--;

      ClearScreen();
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(HORIZSPEED);
   }
}



void Cutscene::CenterToTop()
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
      usleep(VERTSPEED);
   }
}



void Cutscene::CenterToBottom()
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
      usleep(VERTSPEED);
   }
}



void Cutscene::CenterToLeft()
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
      usleep(HORIZSPEED);
   }
}



void Cutscene::CenterToRight()
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
      usleep(HORIZSPEED);
   }
}



void Cutscene::SaveCurrentPosition()
{
   // save the latest coordinates passed to it
   startX = img.screenX;
   startY = img.screenY;
}
