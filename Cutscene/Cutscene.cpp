#include "Cutscene.h"
#include <stdlib.h>
#define HORIZSPEED 50000 //This is half the vert speed in microseconds.
#define VERTSPEED HORIZSPEED*2


Cutscene::Cutscene(ImportImg image, ImportImg r, Room &tempRoom)
{
   screen = Screen(33, 63);
   
   img = ImportImg(image);
   room = ImportImg(r);

   /// set the center point to gain access later on
   img.AlignCenter(screen);
   centerY = img.screenY;
   centerX = img.screenX;

   /// reserve space for 4 exit locations per room
   point.reserve(4);
   FindCharacter(point[0].y, point[0].x, '1', tempRoom);
   FindCharacter(point[1].y, point[1].x, '2', tempRoom);
   FindCharacter(point[2].y, point[2].x, '3', tempRoom);
   FindCharacter(point[3].y, point[3].x, '4', tempRoom);

   for(int i = 0; i < 4; i++)
      cout << "point:x " << point[i].x << ", y " << point[i].y << endl;
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
   foundY = point[3].y;
   foundX = point[3].x;

   //if in the center
   if(centerY == foundY) {
      MoveLeft(img.screenY, img.screenX, centerX - foundX);
      // if top
   } else if(centerY > foundY) {
      MoveUp(img.screenY, img.screenX, img.screenY - foundY);
      MoveLeft(img.screenY, img.screenX, centerX - foundX);
   } else {
      //if bottom
      MoveDown(img.screenY, img.screenX, foundY - img.screenY);
      MoveLeft(img.screenY, img.screenX, centerX - foundX);
   }

   img.AlignCenter(screen);
}



/// Function To animate this direction
void Cutscene::ExitRight()
{
   foundY = point[1].y;
   foundX = point[1].x;

   // if in the center
   if(centerY == foundY) {
      MoveRight(img.screenY, img.screenX, foundX/2);
      // if 
   } else if(centerY > foundY) {
      MoveUp(img.screenY, img.screenX, img.screenY - foundY);
      MoveRight(img.screenY, img.screenX, foundX/2);
   } else {
      // if bottom
      MoveDown(img.screenY, img.screenX, foundY - img.screenY);
      MoveRight(img.screenY, img.screenX, foundX/2);
   }

   img.AlignCenter(screen);
}



/// Function To animate this direction
void Cutscene::ExitUp()
{
   foundY = point[0].y;
   foundX = point[0].x - img.GetCols()/2 + 1;

   // if in the center
   if(centerX == foundX) {
      MoveUp(img.screenY, img.screenX, centerY - foundY);
      // if leftside
   } else if(centerX > foundX) {
      MoveLeft(img.screenY, img.screenX, img.screenX - foundX);
      MoveUp(img.screenY, img.screenX, img.screenY - foundY);
   } else {
      // if rightside
      MoveRight(img.screenY, img.screenX, foundX - img.screenX);   
      MoveUp(img.screenY, img.screenX, img.screenY - foundY);
   }

   img.AlignCenter(screen);
}



/// Function To animate this direction
void Cutscene::ExitDown()
{
   foundY = point[2].y;
   foundX = point[2].x - img.GetCols()/2 + 1;

   // if in the center
   if(centerX == foundX) {
      MoveDown(img.screenY, img.screenX, foundY - centerY);
      // if top
   } else if(centerX > foundX) {
      MoveLeft(img.screenY, img.screenX, img.screenX - foundX);
      MoveDown(img.screenY, img.screenX, foundY - img.screenY);
   } else {
      // if bottom
      MoveRight(img.screenY, img.screenX, foundX - img.screenX);   
      MoveDown(img.screenY, img.screenX, foundY - img.screenY);
   }

   img.AlignCenter(screen);
}



/// Function To animate this direction
void Cutscene::EnterLeft()
{
   img.screenY = point[3].y;
   img.screenX = point[3].x;

   //if in the center
   if(centerY == img.screenY) {
      MoveRight(img.screenY, img.screenX, centerX - img.screenX);
      // if coming in from left top
   } else if(centerY > img.screenY) {
      MoveRight(img.screenY, img.screenX, centerX - img.screenX);
      MoveDown(img.screenY, img.screenX, centerY - img.screenY);
   } else {
      //if coming in from left bottom
      MoveRight(img.screenY, img.screenX, centerX - img.screenX);
      MoveUp(img.screenY, img.screenX, img.screenY - centerY);
   }
}



/// Function To animate this direction
void Cutscene::EnterRight()
{
   img.screenY = point[1].y;
   img.screenX = point[1].x;

   // if in the center
   if(centerY == img.screenY) {
      MoveLeft(img.screenY, img.screenX, img.screenX - centerX);
      // if coming in from top right
   } else if(centerY > foundY) {
      MoveLeft(img.screenY, img.screenX, img.screenX - centerX);
      MoveDown(img.screenY, img.screenX, centerY - img.screenY);
   } else {
      // if coming in from bottom right
      MoveLeft(img.screenY, img.screenX, img.screenX - centerX);
      MoveUp(img.screenY, img.screenX, img.screenY - centerY);
   }
}



/// Function To animate this direction
void Cutscene::EnterUp()
{
   img.screenY = point[0].y;
   img.screenX = point[0].x - img.GetCols()/2 + 1;

   // if in the center
   if(centerX == img.screenX) {
      MoveDown(img.screenY, img.screenX, centerY - img.screenY);
      // if coming in from right side
   } else if(centerX > img.screenX) {
      MoveDown(img.screenY, img.screenX, centerY - img.screenY);
      MoveRight(img.screenY, img.screenX, centerX - img.screenX);
   } else {
      // if coming in from left side
      MoveDown(img.screenY, img.screenX, centerY - img.screenY);
      MoveLeft(img.screenY, img.screenX, img.screenY - centerY);
   }
}



/// Function To animate this direction
void Cutscene::EnterDown()
{
   img.screenY = point[2].y;
   img.screenX = point[2].x - img.GetCols()/2 + 1;

   // if in the center
   if(centerX == img.screenX) {
      MoveUp(img.screenY, img.screenX, img.screenY - centerY);
      // if coming in from bottom right side
   } else if(centerX < img.screenX) {
      MoveUp(img.screenY, img.screenX, img.screenY - centerY);
      MoveLeft(img.screenY, img.screenX, img.screenX - centerX);
   } else {
      // if coming in from bottom left side
      MoveUp(img.screenY, img.screenX, centerY - img.screenY);
      MoveRight(img.screenY, img.screenX, centerX - img.screenX);
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
