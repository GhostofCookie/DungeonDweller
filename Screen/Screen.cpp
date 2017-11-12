#include "Screen.h"


/// Default Constructor
Screen::Screen(int h, int w, char ch)
   : height{h}, width{w}, outlineCh{ch}
{
   Initialize(height, width);
   CreateBorder(outlineCh);
}


/// Destructor
Screen::~Screen() {}



void Screen::Initialize(int h, int w)
{
   for(int i = 0; i < h; i++)
   {
      Window.push_back(vector<char>());
      for(int j = 0; j < w; j++)
	 Window[i].push_back(' ');
   }
}



void Screen::Resize(int h, int w)
{
   height = h;
   width = w;
	
   Window.clear();
}



int Screen::GetRows() const { return height; }
int Screen::GetCols() const { return width; }
void Screen::NewOutlineCh(char ch) { outlineCh = ch; }



bool Screen::IsEven(const int &num) const
{
   if(num % 2 == 0)
      return true;
   return false;
}



void Screen::CreateBorder(char ch)
{
   if(outlineOn)
   {
      for(int i = 0; i < height; i++)
	 for(int j = 0; j < width; j++)
	    if(i == 0 || i == height-1 || j == 0 || j == width-1)
	       Set(i, j, ch);
   }
}



void Screen::DrawBorder()
{
   if(outlineOn)
   {
      for(int i = 0; i < height; i++)
	 for(int j = 0; j < width; j++)
	    if(i == 0 || i == height-1 || j == 0 || j == width-1)
	       Set(i, j, outlineCh);
   }
}



void Screen::Fill()
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 if(i != 0 && i != height-1 && j != 0 && j != width-1)
	    Set(i, j, outlineCh);
}



void Screen::Fill(char ch)
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 if(i != 0 && i != height-1 && j != 0 && j != width-1)
	    Set(i, j, ch);
}



/// Sets the characters at the given location to the given character
// (rows are numbered from 0 from the top, and columns are numbered 0 from the left)
// If the location is invalid, simply ignore the request
/// \param[in] int row
/// \param[in] int col
/// \param[in] char ch
void Screen::Set(int h, int w, char ch)
{
   if((h >= 0 && h < height) && (w >= 0 && w < width))
      Window[h][w] = ch;
}



/// This function erases the contents of the screen and resets
void Screen::Erase()
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 Set(i, j, ' ');
   if(outlineOn)
      DrawBorder();
}



ostream& operator <<(ostream &os, const Screen &s)
{
   //checks if s is empty
   if(s.Window.begin() == s.Window.end())
      return os;
	
   //Prints a two-dimensional vector of characters
   for (unsigned int i = 0; i < s.Window.size(); i++)
   {
      for (auto it = s.Window[i].begin(); it != s.Window[i].end(); ++it)
	 cout << *it;
      cout << endl;
   }
   return os;
}



ostream& operator <<(ostream &os, const Screen *s)
{
   //checks if s is empty
   if(s->Window.begin() == s->Window.end())
      return os;
	
   //Prints a two-dimensional vector of characters
   for (unsigned int i = 0; i < s->Window.size(); i++)
   {
      for (auto it = s->Window[i].begin(); it != s->Window[i].end(); ++it)
	 cout << *it;
      cout << endl;
   }
   return os;
}
