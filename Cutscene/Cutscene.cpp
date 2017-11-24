#include "Cutscene.h"
#include <stdlib.h>
#define HORIZSPEED 50000 //This is half the vert speed in microseconds.
#define VERTSPEED HORIZSPEED*2


Cutscene::Cutscene(ImportImg image, ImportImg r, Room &tempRoom)
{
   screen = Screen(31, 61);
   screen.outlineOn = false;
   
   img = ImportImg(image);
   room = ImportImg(r);

   /// set the center point to gain access later on
   room.AlignCenter(screen);
   img.AlignCenter(room);
   centerY = img.screenY;
   centerX = img.screenX;

   /// reserve space for 4 exit locations per room
   point.reserve(4);
   FindCharacter(point[0].y, point[0].x, '1', tempRoom);
   FindCharacter(point[1].y, point[1].x, '2', tempRoom);
   FindCharacter(point[2].y, point[2].x, '3', tempRoom);
   FindCharacter(point[3].y, point[3].x, '4', tempRoom);

   for(int i = 0; i < 4; i++)
      cout << i << ":  point:x " << point[i].x << ", y " << point[i].y << endl;
   cout << endl;
   cout << "screenY: " << img.screenY << ", screenX: " << img.screenX << endl;
}



Cutscene::~Cutscene()
{

}



void Cutscene::MoveUp(const int originY, const int originX, const int d)
{
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



/// Function To animate this direction
void Cutscene::EnterTopToCenter()
{
   img.AlignTop(screen);
   MoveDown(img.screenY, img.screenX, savedY - img.screenY);
}



/// Function To animate this direction
void Cutscene::EnterBottomToCenter()
{
   img.AlignBottom(screen);
   MoveUp(img.screenY, img.screenX, img.screenY - savedY);
}



/// Function To animate this direction
void Cutscene::EnterLeftToCenter()
{
   img.AlignLeft(screen);
   MoveRight(img.screenY, img.screenX, savedX - img.screenX);
}



/// Function To animate this direction
void Cutscene::EnterRightToCenter()
{
   img.AlignRight(screen);
   MoveLeft(img.screenY, img.screenX, img.screenX - savedX);
}



/// Function To animate this direction
void Cutscene::ExitCenterToTop()
{
   MoveUp(img.screenY, img.screenX, screen.GetRows() - img.screenY);
}



/// Function To animate this direction
void Cutscene::ExitCenterToBottom()
{
   MoveDown(img.screenY, img.screenX, screen.GetRows() - img.screenY);
}



/// Function To animate this direction
void Cutscene::ExitCenterToLeft()
{
   MoveLeft(img.screenY, img.screenX, room.GetCols()/2 + img.GetCols()/2);
}



/// Function To animate this direction
void Cutscene::ExitCenterToRight()
{
   MoveRight(img.screenY, img.screenX, room.GetCols()/2 + img.GetCols()/2);
}



/// Function To animate this direction
void Cutscene::ExitLeft()
{
   foundY = point[3].y - img.GetRows()/2;
   foundX = point[3].x - img.GetCols();

   if(img.screenY == foundY) {
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
      
   } else if(img.screenY > foundY) {
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::ExitRight()
{
   foundY = point[1].y - img.GetRows()/2;
   foundX = point[1].x + img.GetCols();

   if(img.screenY == foundY) {
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);
      
   } else if(img.screenY > foundY) {
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::ExitUp()
{
   foundY = point[0].y - img.GetRows();
   foundX = point[0].x - img.GetCols()/2;

   if(img.screenX == foundX) {
      while(img.screenY != foundY)
	 MoveUp(img.screenY, img.screenX, 1);
      
   } else if(img.screenX > foundX) {
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);
   } 
}



/// Function To animate this direction
void Cutscene::ExitDown()
{
   foundY = point[2].y + img.GetRows();
   foundX = point[2].x - img.GetCols()/2;

   if(img.screenX == foundX) {
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);
      
   } else if(img.screenX > foundX) {
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::EnterLeft()
{
   img.screenY = point[3].y - img.GetRows()/2;
   img.screenX = point[3].x - img.GetCols();

   if(img.screenY == centerY) {
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
      
   } else if(img.screenY > centerY) {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::EnterRight()
{
   img.screenY = point[1].y - img.GetRows()/2;
   img.screenX = point[1].x - img.GetCols();

   if(img.screenY == centerY) {
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);
      
   } else if(img.screenY > centerY) {
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::EnterUp()
{
   img.screenY = point[0].y - img.GetRows();
   img.screenX = point[0].x - img.GetCols()/2;

   if(img.screenX == centerX) {
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
      
   } else if(img.screenX > centerX) {
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
      while(img.screenX < centerX)
	 MoveDown(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::EnterDown()
{
   img.screenY = point[2].y + img.GetRows();
   img.screenX = point[2].x - img.GetCols()/2;

   if(img.screenX == centerX) {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      
   } else if(img.screenX > centerX) {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);
      
   } else {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::SaveCurrentPosition()
{
   // save the latest coordinates passed to it
   savedX = img.screenX;
   savedY = img.screenY;
}



/// Function To animate this direction
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
