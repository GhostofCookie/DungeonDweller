#include "Cutscene.h"
#include <stdlib.h>
#define HORIZSPEED 50000 //This is half the vert speed in microseconds.
#define VERTSPEED HORIZSPEED*2


Cutscene::Cutscene(ImportImg image, ImportImg r, Room &tempRoom)
{
   screen = Screen();
   
   img = ImportImg(image);
   room = ImportImg(r);
   
   img.AlignCenter(screen);
   SaveCurrentPosition();

   point.reserve(4);
   FindCharacter(point[0].y, point[0].x, '1', tempRoom);
   FindCharacter(point[1].y, point[1].x, '2', tempRoom);
   FindCharacter(point[2].y, point[2].x, '3', tempRoom);
   FindCharacter(point[3].y, point[3].x, '4', tempRoom);

   for(int i = 0; i < 4; i++)
      cout << "point: " << point[i].x << ", " << point[i].y << endl;
}



Cutscene::~Cutscene()
{

}



void Cutscene::MoveUp(const int originY, const int originX, const int d)
{
   room.AlignCenter(screen);
   img.SetOrigin(screen, originY, originX);

   // This loop will animate the image and print to the screen
   int n = 0;
   while(n < d)
   {
      img.ShiftUp(1);
      n++;

      system("clear");
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(VERTSPEED);
   }
}



void Cutscene::MoveDown(const int originY, const int originX, const int d)
{
   room.AlignCenter(screen);
   img.SetOrigin(screen, originY, originX);

   // This loop will animate the image and print to the screen
   int n = 0;
   while(n < d)
   {
      img.ShiftDown(screen, 1);
      n++;

      system("clear");
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(VERTSPEED);
   }
}



void Cutscene::MoveLeft(const int originY, const int originX, const int d)
{
   room.AlignCenter(screen);
   img.SetOrigin(screen, originY, originX);

   // This loop will animate the image and print to the screen
   int n = 0;
   while(n < d)
   {
      img.ShiftLeft(1);
      n++;

      system("clear");
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(HORIZSPEED);
   }
}



void Cutscene::MoveRight(const int originY, const int originX, const int d)
{
   room.AlignCenter(screen);
   img.SetOrigin(screen, originY, originX);

   // This loop will animate the image and print to the screen
   int n = 0;
   while(n < d)
   {
      img.ShiftRight(screen, 1);
      n++;

      system("clear");
      screen.Erase();
      room.Draw(screen);
      img.Draw(screen);
      
      cout << screen << endl;
      usleep(HORIZSPEED);
    }
}



void Cutscene::TopToCenter()
{
   img.AlignTop(screen);
   MoveDown(img.screenY, img.screenX, startY - img.screenY);
}



void Cutscene::BottomToCenter()
{
   img.AlignBottom(screen);
   MoveUp(img.screenY, img.screenX, img.screenY - startY);
}



void Cutscene::LeftToCenter()
{
   img.AlignLeft(screen);
   MoveRight(img.screenY, img.screenX, startX - img.screenX);
}



void Cutscene::RightToCenter()
{
   img.AlignRight(screen);
   MoveLeft(img.screenY, img.screenX, img.screenX - startX);
}



void Cutscene::CenterToTop()
{
   MoveUp(img.screenY, img.screenX, screen.GetRows() - img.screenY);
}



void Cutscene::CenterToBottom()
{
   MoveDown(img.screenY, img.screenX, screen.GetRows() - img.screenY);
}



void Cutscene::CenterToLeft()
{
   MoveLeft(img.screenY, img.screenX, room.GetCols()/2 + img.GetCols()/2);
}



void Cutscene::CenterToRight()
{
   MoveRight(img.screenY, img.screenX, room.GetCols()/2 + img.GetCols()/2);
}



void Cutscene::DownToLeft(const int yDown, const int xDown, int nDown, const int yLeft, const int xLeft, const int nLeft)
{
   foundY = point[4].y;
   foundX = point[4].x;
   img.AlignCenter(screen);
   
   MoveDown(img.screenY, img.screenX, img.screenY - foundY);
   MoveLeft(img.screenY, img.screenX, img.screenX - foundX);
}



void Cutscene::DownToRight(const int yDown, const int xDown, int nDown, const int yRight, const int xRight, const int nRight)
{
   foundY = point[2].y;
   foundX = point[2].x;
   MoveDown(img.screenY, img.screenX, img.screenY - foundY);
   MoveRight(img.screenY, img.screenX, img.screenX - foundX);
}



void Cutscene::UpToLeft(const int yUp, const int xUp, int nUp, const int yLeft, const int xLeft, const int nLeft)
{
   foundY = point[4].y;
   foundX = point[4].x;
   MoveUp(img.screenY, img.screenX, img.screenY - foundY);
   MoveLeft(img.screenY, img.screenX, img.screenX - foundX);
}



void Cutscene::UpToRight(const int yUp, const int xUp, int nUp, const int yRight, const int xRight, const int nRight)
{
   foundY = point[2].y;
   foundX = point[2].x;
   MoveUp(img.screenY, img.screenX, img.screenY - foundY);
   MoveRight(img.screenY, img.screenX, img.screenX - foundX);
}



void Cutscene::RightToUp(const int yRight, const int xRight, int nRight, const int yUp, const int xUp, const int nUp)
{
   foundY = point[2].y;
   foundX = point[2].x;
   MoveRight(img.screenY, img.screenX, img.screenX - foundX);
   MoveUp(img.screenY, img.screenX, img.screenY - foundY);
}



void Cutscene::RightToDown(const int yRight, const int xRight, int nRight, const int yDown, const int xDown, const int nDown)
{
   foundY = point[3].y;
   foundX = point[3].x;
   MoveRight(img.screenY, img.screenX, img.screenX - foundX);
   MoveDown(img.screenY, img.screenX, img.screenY - foundY);
}



void Cutscene::LeftToUp(const int yLeft, const int xLeft, int nLeft, const int yUp, const int xUp, const int nUp)
{
   foundY = point[0].y;
   foundX = point[0].x;
   MoveLeft(img.screenY, img.screenX, img.screenX - foundX);
   MoveUp(img.screenY, img.screenX, img.screenY - foundY);
}



void Cutscene::LeftToDown(const int yLeft, const int xLeft, int nLeft, const int yDown, const int xDown, const int nDown)
{
   foundY = point[3].y;
   foundX = point[3].x;
   MoveLeft(img.screenY, img.screenX, img.screenX - foundX);
   MoveDown(img.screenY, img.screenX, img.screenY - foundY);
}



void Cutscene::SaveCurrentPosition()
{
   // save the latest coordinates passed to it
   startX = img.screenX;
   startY = img.screenY;
}



void Cutscene::FindCharacter(int &y, int &x, const char c, const Room &r)
{
   for(auto i = r.point.begin(); i != r.point.end(); ++i)
   {
      if(i->ch == c)
      {
	 y = i->y;
	 x = i->x;
	 break;
      }
   }
}