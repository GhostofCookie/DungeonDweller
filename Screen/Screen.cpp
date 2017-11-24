#include "Screen.h"


/// Default Constructor
/// \param[in] h the height of the screen
/// \param[in] w the width of the screen
/// \param[in] ch the character used to draw the outline of the screen
Screen::Screen(int h, int w, char ch)
   : height{h}, width{w}, outlineCh{ch}
{
   Initialize(height, width);
   DrawBorder();
}



/// Destructor
Screen::~Screen() {}



/// Function sets up the screen by pushing back the required size
/// \param[in] h the height of the screen
/// \param[in] w the width of the screen
void Screen::Initialize(int h, int w)
{
   for(int i = 0; i < h; i++)
   {
      Window.push_back(vector<char>());
      for(int j = 0; j < w; j++)
	 Window[i].push_back(' ');
   }
}



/// Function to resize the screen
/// \param[in] h the new height of the screen
/// \param[in] w the new width of the screen
void Screen::Resize(int h, int w)
{
   height = h;
   width = w;
	
   Window.clear();
}



/// Helper function to return the width of the screen
int Screen::GetRows() const { return height; }
/// Helper function to return the height of the screen
int Screen::GetCols() const { return width; }
/// Helper function to set a new character for the border
void Screen::NewOutlineCh(char ch) { outlineCh = ch; }



/// Function that returns TRUE if a number is even
/// \param[in] num the number to be checked
bool Screen::IsEven(const int &num) const
{
   if(num % 2 == 0)
      return true;
   return false;
}



/// Function that draws the border to the edges of the screen
/// \param[in] ch the character used to draw the screen
void Screen::DrawBorder(char ch)
{
   if(outlineOn)
   {
      for(int i = 0; i < height; i++)
	 for(int j = 0; j < width; j++)
	    if(i == 0 || i == height-1 || j == 0 || j == width-1)
	       Set(i, j, ch);
   }
}



/// Function that draws the border to the edges of the screen
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



/// Function that fills the innards of the screen object
void Screen::Fill()
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 if(i != 0 && i != height-1 && j != 0 && j != width-1)
	    Set(i, j, outlineCh);
}



/// Function that fills the innards of the screen
/// \param[in] ch the character used to fill with
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



/// Function to prints as many screens as you want side by side
void Screen::MultiPrint(const vector<Screen> &screens)
{
   int h = 0;
   while(h < screens[0].height)
   {
      for(unsigned int i = 0; i < screens.size(); i++)
      {
	 for(int col = 0; col < screens[i].width; col++)
	    cout << screens[i].Window[h][col];
      }
      h++;
      cout << endl;
   }
}



/// Overloaded ostream operator
/// \param[in] os the ostream
/// \param[in] s the screen being drawn
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



/// Overloaded ostream operator
/// \param[in] os the ostream operator
/// \param[in] s the screen being drawn
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
