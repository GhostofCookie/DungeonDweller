#include "Image.h"

/// Default Constructor
/// \param[in] h the height of the image
/// \param[in] w the width of the image
/// \param[in] c the character to be drawn with
Image::Image(int h, int w, char c)
   : height{h}, width{w}, ch{c}
{ Create(); }



/// Copy Constructor for the image
/// \param[in] image the image to be copied from
Image::Image(const Image &image)
   : height{image.GetRows()}, width{image.GetCols()}, screenX{image.screenX}, screenY{image.screenY}
{}



/// Copy Constructor for the image
/// \param[in] image the image to be copied from
Image::Image(Image &image)
   : height{image.GetRows()}, width{image.GetCols()}, screenX{image.screenX}, screenY{image.screenY}
{}



/// Destructor
Image::~Image()
{}



Image& Image::operator=(const Image& img)
{
   Img = img.Img;
   
   height = img.GetRows();
   width = img.GetCols();
   screenX = img.screenX;
   screenY = img.screenY;
   ch = img.ch;
   return *this;
}



/// Function that returns the width of the image
int Image::GetRows() const { return height; }
/// Function that returns the height of the image
int Image::GetCols() const { return width; }



/// Function returns true if a number is even
/// \param[in] num the number to be checked
bool Image::IsEven(const int& num) const { return(num % 2 == 0); }



/// Function to draw the image to the screen
/// \param[in] screen the screen drawn on
void Image::Draw(Screen &screen) { Draw(screen, screenY, screenX); }



/// Function to draw the image to the screen
/// \param[in] screen the screen drawn on
/// \param[in] y the y coordinate to begin drawing from
/// \param[in] x the x coordinate to begin drawing from
void Image::Draw(Screen &screen, int y, int x)
{
   int imgY = y;
   int imgX = x;
	
   // An algorithm that moves through each element in the Img
   // and attempts to place on the screen with the given start location
   for(unsigned int i = 0; i < Img.size(); ++i)
   {
      for(auto p = Img[i].begin(); p != Img[i].end(); ++p)
      {
	 if((imgX >= 0 || imgX < screen.GetCols()) && (imgY >= 0 || imgY < screen.GetRows()))
	    screen.Set(imgY, imgX, *p);
	 imgX++;
      }
      imgY++;
      imgX = x;
   }
   screen.DrawBorder();
}



/// Function to draw the image to the screen
/// \param[in] image the image drawn on
void Image::Draw(Image &img) { Draw(img, screenY, screenX); }



/// Function to draw the image to the screen
/// \param[in] img the image drawn on
/// \param[in] y the y coordinate to begin drawing from
/// \param[in] x the x coordinate to begin drawing from
void Image::Draw(Image &img, int y, int x)
{
   int imgY = y;
   int imgX = x;
	
   // An algorithm that moves through each element in the Img
   // and attempts to place on the screen with the given start location
   for(unsigned int i = 0; i < Img.size(); ++i)
   {
      for(auto p = Img[i].begin(); p != Img[i].end(); ++p)
      {
	 if((imgX >= 0 || imgX < img.GetCols()) && (imgY >= 0 || imgY < img.GetRows()))
	    img.Set(imgY, imgX, *p);
	 imgX++;
      }
      imgY++;
      imgX = x;
   }
}



/// Function that fills in the vector that makes up the image
void Image::Create()
{
   for(int i = 0; i < height; i++)
   {
      Img.push_back(vector<char>());
      for(int j = 0; j < width; j++)
	 Img[i].push_back(ch);
   }
}



/// Function that draws and border around the image
/// \param[in] ch the character used to draw the border
void Image::DrawBorder(char ch)
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 if(i == 0 || i == height-1 || j == 0 || j == width-1)
	    Set(i, j, ch);
}



/// Erase the image contents be replacing with spaces
void Image::Erase()
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 Set(i, j, ' ');
}



/// Sets the characters at the given location to the given character
// (rows are numbered from 0 from the top, and columns are numbered 0 from the left)
// If the location is invalid, simply ignore the request
void Image::Set(int y, int x, char ch)
{
   Img[y][x] = ch;
}



// Function that fills the image with its given character
void Image::Fill(char ch)
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 Set(i, j, ch);
}



// ALIGN MEMBER FUNCTIONS
/// Sets the print origin of the image relative to the screen
/// \param[in] y the y coordinate to begin from
/// \param[in] the x coordinate to begin from
void Image::SetOrigin(Screen &screen, int y, int x)
{
   assert(y >= 0 || y < screen.GetRows());
   assert(x >= 0 || x < screen.GetCols());
   screenX = x;
   screenY = y;
}



/// Sets the print origin of the image relative to the screen
/// \param[in] y the y coordinate to begin from
/// \param[in] the x coordinate to begin from
void Image::SetOrigin(Image &img, int y, int x)
{
   assert(y >= 0 || y < img.GetRows());
   assert(x >= 0 || x < img.GetCols());
   screenX = x;
   screenY = y;
}



/// Function to flip the image horizontally
void Image::FlipHoriz()
{
   vector<vector<char>> temp;
   int imgSize = static_cast<int>(Img.size());
	
   for(unsigned int i = 0; i < Img.size(); ++i)
   {
      vector<char> _temp;
      for(unsigned int j = imgSize-1; j != 1; --j)
	 _temp.push_back(Img[i][j]);

      temp.push_back(_temp);
   }
	
   Img = temp;
   FixSlants();// by-product of having console characters
}



/// Function to flip the image vertically 
void Image::FlipVert()
{
   vector<vector<char>> temp;
   int imgSize = static_cast<int>(Img.size());
	
   for(int i = imgSize-1; i != -1; --i)
   {
      vector<char> _temp;
      for(unsigned int j = 0; j < Img[i].size(); ++j)
	 _temp.push_back(Img[i][j]);
      
      temp.push_back(_temp);
   }
	
   Img = temp;
   FixSlants();// by-product of having console characters
}



/// Align the image to the center of the screen
/// \param[in] screen checks to ensure the bounds aren't exceeded
void Image::AlignCenter(Screen &screen)
{
   int scrX = screen.GetCols()/2;
   int scrY = screen.GetRows()/2;
   int imgX = width/2;
   int imgY = height/2;
	
   // Relys on it being odd for centering perfection
   SetOrigin(screen, scrY - imgY, scrX - imgX);
}



/// Align the image to the center of the given image
/// \param[in] image checks to ensure the bounds aren't exceeded
void Image::AlignCenter(Image &img)
{
   // in this situation the screen is represented by the image
   int scrX = img.GetCols()/2;
   int scrY = img.GetRows()/2;
   int imgX = width/2;
   int imgY = height/2;

   // Relys on it being odd for centering perfection
   SetOrigin(img, scrY - imgY, scrX - imgX);
}



/// Align the image to the center of the given image
/// \param[in] image checks to ensure the bounds aren't exceeded
/// \param[in] x the x coordinate to center around
/// \param[in] y the y coordinate to center around
void Image::AlignCenter(Image &img, int x, int y)
{
   // in this situation the screen is represented by the image
   int scrX = x;
   int scrY = y;
   int imgX = width/2;
   int imgY = height/2;

   // Relys on it being odd for centering perfection
   SetOrigin(img, scrY - imgY, scrX - imgX);
}



/// Align the image to the left of the given image
/// \param[in] image checks to ensure the bounds aren't exceeded
// Ensures it draws one character from the border
void Image::AlignLeft(Image &img) { screenX = 1; }



/// Align the image to the right of the given image
/// \param[in] image checks to ensure the bounds aren't exceeded
void Image::AlignRight(Image &img)
{
   //uses the image's width and screen's width to find the right side
   screenX = static_cast<int>(img.GetCols()-Img[0].size()-1);
}



/// Align the image to the left of the screen
/// \param[in] screen used to align with
// Ensures it draws one character from the border
void Image::AlignLeft(Screen &screen) { screenX = 1; };



/// Align the image to the right of the screen
/// \param[in] screen used to align with
void Image::AlignRight(Screen &screen)
{
   // uses the image's width and screen's width to find the right side
   screenX = static_cast<int>(screen.GetCols()-Img[0].size()-1);
}



/// Align the image to the top of the screen
/// \param[in] screen used to align with
// Ensures it draws one character from the border
void Image::AlignTop(Screen &screen) { screenY = 1; };



/// Align the image to the top of the image
/// \param[in] img used to align with
// Ensures it draws one character from the border
void Image::AlignTop(Image &img) { screenY = img.screenY-1; };



/// Align the image to the bottom of the screen
/// \param[in] screen used to align with
// Ensures it draws one character from the border
void Image::AlignBottom(Screen &screen) { screenY = static_cast<int>(screen.GetRows() - Img.size()-1); };



/// Align the image to the bottom of the image
/// \param[in] img used to align with
// Ensures it draws one character from the border
void Image::AlignBottom(Image &img) { screenY = static_cast<int>(img.GetRows() - Img.size()-1); };



/// Function to shift the image up
/// \param[in] num the amount to shift by
void Image::ShiftUp(int num)
{
   int i = 0;
   while(i < num)
   {
      screenY--;
      i++;
   }
}



/// Function to shift the image down
///\param[in] screen checks the bounds of the screen
/// \param[in] num the amount to shift by
void Image::ShiftDown(Screen &screen, int num)
{
   int i = 0;
   while(i < num)
   {
      screenY++;
      i++;
   }
}



/// Function to shift the image down
/// \param[in] img checks the bounds of the image
/// \param[in] num the amount to shift by
void Image::ShiftDown(Image &img, int num)
{
   int i = 0;
   while(i < num)
   {
      screenY++;
      i++;
   }
}



/// Function to shift the image left
/// \param[in] num the amount to shift by
void Image::ShiftLeft(int num)
{
   int i = 0;
   while(i < num)
   {
      screenX--;
      i++;
   }
}



/// Function to shift the image right
/// \param[in] screne checks the bounds of the screen 
/// \param[in] num the amount to shift by
void Image::ShiftRight(Screen &screen, int num)
{
   int i = 0;
   while(i < num)
   {
      screenX++;
      i++;
   }
}



/// Function to shift the image right
/// \param[in] img checks the bounds of the image
/// \param[in] num the amount to shift by
void Image::ShiftRight(Image &img, int num)
{
   int i = 0;
   while(i < num)
   {
      screenX++;
      i++;
   }
}



/// Function that switches the slant characters
/// Used for images that looks wierd after being flipped
void Image::FixSlants()
{
   for(unsigned int i = 0; i < Img.size(); ++i)
   {
      for(unsigned int j = 0; j < Img[i].size(); ++j)
      {
	 if(Img[i][j] == '/')
	    Img[i][j] = '\\';
	 else if(Img[i][j] == '\\')
	    Img[i][j] = '/';
      }
   }
}
