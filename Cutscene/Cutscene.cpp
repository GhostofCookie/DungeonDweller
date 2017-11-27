#include "Cutscene.h"
#include <stdlib.h>
#define HORIZSPEED 25000 //This is half the vert speed in microseconds.
#define VERTSPEED HORIZSPEED*2



/// Default Constructor
/// \param[in] image the image to be animated
/// \param[in] r the room to be animated in
/// \param[in] tempRoom to gain temporary access to its exit points
Cutscene::Cutscene(ImportImg image, ImportImg r, Room *tempRoom)
{
   // itinitialize the animated img and the background
   img = ImportImg(image);
   room = ImportImg(r);
   
   // initialize a screen for the image to lay on
   screen = Screen(33, 61);
   leftSide = rightSide = Screen(33, 20, ' ');

   screen.outlineOn = false;
   leftSide.Fill(' ');
   rightSide.Fill(' ');

   /// set the center point to gain access later on
   room.AlignCenter(screen);
   room.ShiftUp(1);
   
   // preset the room to be in the center for all animations
   img.AlignCenter(room);
   centerY = img.screenY;
   centerX = img.screenX;

   /// reserve and locate points for 4 exit locations per room
   point.reserve(4);
   if(tempRoom != nullptr)
   {
      FindCharacter(point[0].y, point[0].x, '1', *tempRoom); // up
      FindCharacter(point[1].y, point[1].x, '2', *tempRoom); // right
      FindCharacter(point[2].y, point[2].x, '3', *tempRoom); // down
      FindCharacter(point[3].y, point[3].x, '4', *tempRoom); // left
   }
}



/// Deconstructor
Cutscene::~Cutscene()
{

}



/// Function to move an image up on the screen
/// \param[in] originY
/// \param[in] originX
/// \param[in] d
void Cutscene::MoveUp(const int originY, const int originX, const int d)
{
   vector<Screen> scr = {leftSide, screen, rightSide};
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
      
      screen.MultiPrint(scr);
      usleep(VERTSPEED);
   }
}



/// Function to move an image down on the screen
/// \param[in] originY
/// \param[in] originX
/// \param[in] d
void Cutscene::MoveDown(const int originY, const int originX, const int d)
{
   vector<Screen> scr = {leftSide, screen, rightSide};
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
      
      screen.MultiPrint(scr);
      usleep(VERTSPEED);
   }
}



/// Function to move an image left on the screen
/// \param[in] originY
/// \param[in] originX
/// \param[in] d
void Cutscene::MoveLeft(const int originY, const int originX, const int d)
{
   vector<Screen> scr = {leftSide, screen, rightSide};
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
      
      screen.MultiPrint(scr);
      usleep(HORIZSPEED);
   }
}



/// Function to move an image right on the screen
/// \param[in] originY
/// \param[in] originX
/// \param[in] d
void Cutscene::MoveRight(const int originY, const int originX, const int d)
{
   vector<Screen> scr = {leftSide, screen, rightSide};
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
      
      screen.MultiPrint(scr);
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
   // adjust for character centering
   foundY = point[3].y - img.GetRows()/2;
   foundX = point[3].x - img.GetCols();

   // if exiting down the center
   if(img.screenY == foundY) {
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);

      // if exiting left side
   } else if(img.screenY > foundY) {
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);

      // if on the right side
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
   // adjust for character centering
   foundY = point[1].y - img.GetRows()/2;
   foundX = point[1].x + img.GetCols();

   // if exiting down the center
   if(img.screenY == foundY) {
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);

      // if exiting left side
   } else if(img.screenY > foundY) {
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX < foundX)
	 MoveRight(img.screenY, img.screenX, 1);

      // if on the right side
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
   // adjust for character centering
   foundY = point[0].y - img.GetRows();
   foundX = point[0].x - img.GetCols()/2;

   // if exiting down the center
   if(img.screenX == foundX) {
      while(img.screenY != foundY)
	 MoveUp(img.screenY, img.screenX, 1);

      // if exiting left side
   } else if(img.screenX > foundX) {
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY > foundY)
	 MoveUp(img.screenY, img.screenX, 1);

      // if on the right side
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
   // adjust for character centering
   foundY = point[2].y + img.GetRows();
   foundX = point[2].x - img.GetCols()/2;

   // if exiting down the center
   if(img.screenX == foundX) {
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);

      // if exiting left side
   } else if(img.screenX > foundX) {
      while(img.screenX > foundX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY < foundY)
	 MoveDown(img.screenY, img.screenX, 1);

      // if on the right side
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
   // adjust for character centering
   img.screenY = point[3].y - img.GetRows()/2;
   img.screenX = point[3].x - img.GetCols();

   // if entering from the center
   if(img.screenY == centerY) {
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);

      // if entering from the right
   } else if(img.screenY > centerY) {
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);

      // if entering from the left
   } else {
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::EnterRight()
{
   // adjust for character centering
   img.screenY = point[1].y - img.GetRows()/2;
   img.screenX = point[1].x - img.GetCols();

   // if entering from the center
   if(img.screenY == centerY) {
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);

      // if entering from the right
   } else if(img.screenY > centerY) {
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);

      // if entering from the left
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
   // adjust for character centering
   img.screenY = point[0].y - img.GetRows();
   img.screenX = point[0].x - img.GetCols()/2;

   // if entering from the center
   if(img.screenX == centerX) {
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);

      // if entering from the right
   } else if(img.screenX > centerX) {
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);

      // if entering from the left
   } else {
      while(img.screenY < centerY)
	 MoveDown(img.screenY, img.screenX, 1);
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
   }
}



/// Function To animate this direction
void Cutscene::EnterDown()
{
   // adjust for character centering
   img.screenY = point[2].y + img.GetRows();
   img.screenX = point[2].x - img.GetCols()/2;

   // if entering from the center
   if(img.screenX == centerX) {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);

      // if entering from the right
   } else if(img.screenX > centerX) {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX > centerX)
	 MoveLeft(img.screenY, img.screenX, 1);

      // if entering from the left
   } else {
      while(img.screenY > centerY)
	 MoveUp(img.screenY, img.screenX, 1);
      while(img.screenX < centerX)
	 MoveRight(img.screenY, img.screenX, 1);
   }
}



/// Function to save the animated image's current coodinate
void Cutscene::SaveCurrentPosition()
{
   // save the latest coordinates passed to it
   savedX = img.screenX;
   savedY = img.screenY;
}



/// Function To animate this direction
/// \param[in] y the y coordinate to be set
/// \param[in] x the x coordinate to be set
/// \param[in] c the character to find
/// \param[in] r the room to access its points
void Cutscene::FindCharacter(int &y, int &x, const char c, const Room &r)
{
   // iterate through the points inside the room object
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



/// Function to animate an outro * hardcoded in every cutscene obj
void Cutscene::Intro()
{
   Screen scr = Screen();
   ImportImg title = ImportImg("../DD_Art/Credits/title.txt");

   string play = "[P] Play Game";
   string quit = "[Q] Quit Game";
   
   title.AlignCenter(scr);
   title.ShiftDown(scr, scr.GetRows()/2 + title.GetRows());

   // This loop draws the title up the screen
   int i = 0;
   while(i++ < scr.GetRows()/2 + title.GetRows())
   {
      system("clear");
      
      title.Draw(scr);
      cout << scr;

      scr.Erase();
      title.ShiftUp(1);

      usleep(200000);
   }

   // initialize where the menu options begin to print
   int playX = scr.GetCols()/2 - (play.length() * 2);
   int quitX = scr.GetCols()/2 + quit.length();

   // iterate through the char array printing each character one at a time
   for(unsigned int i = 0; i < play.length(); i++)
   {
      system("clear");

      title.Draw(scr);
      scr.Set(scr.GetRows()-play.length()/2, playX++, play[i]);

      cout << scr;
      
      usleep(100000);
   }

   // iterate through the char array printing each character one at a time
   for(unsigned int i = 0; i < quit.length(); i++)
   {
      system("clear");

      title.Draw(scr);
      scr.Set(scr.GetRows()-quit.length()/2, quitX++, quit[i]);

      cout << scr;
      
      usleep(100000);
   }
}



/// Function to animate an outro * hardcoded in every cutscene obj
void Cutscene::Outro()
{  
   Screen scr = Screen();
   ImportImg credits = ImportImg("../DD_Art/Credits/credits.txt");
   
   credits.AlignCenter(scr);
   credits.ShiftDown(scr, scr.GetRows()/2 + credits.GetRows());

   // This loop draws the title up the screen
   int i = 0;
   while(i++ < scr.GetRows()/2 + credits.GetRows())
   {
      system("clear");
      
      credits.Draw(scr);
      cout << scr;

      scr.Erase();
      credits.ShiftUp(1);

      usleep(VERTSPEED * 2);
   }

   usleep(3000000);
}



/// Function to animate an encounter * hardcoded in every cutscene obj
void Cutscene::MonsterEncounter()
{
   const int am = 3;
   
   Screen scr = Screen();

   // fill from the ends into the center
   int left = 0, right = scr.GetCols()-1;
   while(left <= right)
   {
      int j = scr.GetRows()-1;
      for(int i = 0; i < scr.GetRows(); i++, j--)
      {
	 for(int k = 0; k < am; k++)
	 {
	    scr.Set(i, left + k, '*');
	    scr.Set(j, right - k, '*');
	 }
      }
      system("clear");
      cout << scr;
      usleep(20000);
      
      left += am;
      right -= am;
   }

   // erase from the middle out
   left = scr.GetCols()/2, right = scr.GetCols()/2;
   while(left >= 0 - am)
   {
      int j = scr.GetRows()-1;
      for(int i = 0; i < scr.GetRows(); i++, j--)
      {
	 for(int k = 0; k < am; k++)
	 {
	    scr.Set(i, left + k, ' ');
	    scr.Set(j, right - k, ' ');
	 }
      }
      system("clear");
      cout << scr;
      usleep(20000);
      
      left -= am;
      right += am;
   }
}
