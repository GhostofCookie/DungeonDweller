#include "Image.h"

/// Default Constructor
Image::Image(int h, int w)
   : height{h}, width{w}
{
   Create();
}



Image::Image(const Image& image)
{
   Img = image.Img;
   height = image.GetRows();
   width = image.GetCols();
   screenX = image.screenX;
   screenY = image.screenY;
}


Image::Image(Image& image)
{
   Img = image.Img;
   height = image.GetRows();
   width = image.GetCols();
   screenX = image.screenX;
   screenY = image.screenY;
}



/// Destructor
Image::~Image()
{
	
}



void Image::operator=(const Image &image)
{
   //delete[] str;
   Img.clear();
	
   for(int i = 0; i < image.GetRows(); ++i)
   {
      Img.push_back(vector<char>());
      for(int j = 0; j < image.GetCols(); ++j)
	 Img[i].push_back(image.Img[i][j]);
   }
}



void Image::operator=(Image &image)
{
   //delete[] str;
   Img.clear();
	
   for(int i = 0; i < image.GetRows(); ++i)
   {
      Img.push_back(vector<char>());
      for(int j = 0; j < image.GetCols(); ++j)
	 Img[i].push_back(image.Img[i][j]);
   }
}



int Image::GetRows() const { return height; }
int Image::GetCols() const { return width; }



bool Image::IsEven(const int& num) const
{
   if(num % 2 == 0)
      return true;
   return false;
}



void Image::Draw(Screen &screen)
{
   Draw(screen, screenX, screenY);
}



void Image::Draw(Screen &screen, int y, int x)
{
   int imgY = y;
   int imgX = x;
	
   // An algorithm that moves through each element in the Img
   // and attempts to place on the screen with the given start location
   for(int i = 0; i < Img.size(); i++)
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



void Image::Draw(Image &img)
{
   Draw(img, screenX, screenY);
}



void Image::Draw(Image &img, int y, int x)
{
   int imgY = y;
   int imgX = x;
	
   // An algorithm that moves through each element in the Img
   // and attempts to place on the screen with the given start location
   for(int i = 0; i < Img.size(); i++)
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



void Image::Create()
{
   for(int i = 0; i < height; i++)
   {
      Img.push_back(vector<char>());
      for(int j = 0; j < width; j++)
	 Img[i].push_back('*');
   }
}



void Image::DrawBorder(char ch)
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 if(i == 0 || i == height-1 || j == 0 || j == width-1)
	    Set(i, j, ch);
}



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
   if((y >= 0 && y < height) && (x >= 0 && x < width))
      Img[y][x] = ch;
}



void Image::Fill(char ch)
{
   for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++)
	 Set(i, j, ch);
}



//ALIGN MEMBER FUNCTIONS
void Image::SetOrigin(Screen &screen, int y, int x)
{
   assert(y >= 0 || y < screen.GetRows());
   assert(x >= 0 || x < screen.GetCols());
   screenX = x;
   screenY = y;
}



void Image::SetOrigin(Image &img, int y, int x)
{
   assert(y >= 0 || y < img.GetRows());
   assert(x >= 0 || x < img.GetCols());
   screenX = x;
   screenY = y;
}



void Image::FlipHoriz(Screen &screen)
{
   vector<vector<char>> temp;
   int imgSize = static_cast<int>(Img.size());
	
   for(int i = 0; i < Img.size(); ++i)
   {
      vector<char> _temp;
      for(unsigned int j = imgSize-1; j != 1; --j)
      {
	 _temp.push_back(Img[i][j]);
      }
      temp.push_back(_temp);
   }
	
   Img = temp;
   FixSlants();//by-product of having console characters
}



void Image::FlipVert(Screen &screen)
{
   vector<vector<char>> temp;
   int imgSize = static_cast<int>(Img.size());
	
   for(unsigned int i = imgSize-1; i != -1; --i)
   {
      vector<char> _temp;
      for(int j = 0; j < Img[i].size(); ++j)
      {
	 _temp.push_back(Img[i][j]);
      }
      temp.push_back(_temp);
   }
	
   Img = temp;
   FixSlants();//by-product of having console characters
}



void Image::AlignLeft(Screen &screen)
{
   screenX = 1;//that way the images are always within the border of the screen
   SetOrigin(screen, screenX, screenY);
}



void Image::AlignRight(Screen &screen)
{
   //uses the image's width and screen's width to find the right side
   screenX = static_cast<int>(screen.GetCols()-Img[0].size()-1);
   SetOrigin(screen, screenX, screenY);
}



void Image::AlignCenter(Screen &screen)
{
   int scrX = screen.GetCols()/2; // 101/2
   int scrY = screen.GetRows()/2; // 61/2
   int imgX = width/2; // 30  61/2
   int imgY = height/2; // 15  31/2
	
   // Relys on it being odd for centering perfection
   screenX = scrX - imgX;
   screenY = scrY - imgY;
	
   SetOrigin(screen, screenX, screenY);
}



void Image::AlignLeft(Image &img)
{
   screenX = 1;//that way the images are always within the border of the screen
   SetOrigin(img, screenX, screenY);
}



void Image::AlignRight(Image &img)
{
   //uses the image's width and screen's width to find the right side
   screenX = static_cast<int>(img.GetCols()-Img[0].size()-1);
   SetOrigin(img, screenX, screenY);
}



void Image::AlignCenter(Image &img)
{
   int scrX = img.GetCols()/2; // 101/2
   int scrY = img.GetRows()/2; // 61/2
   int imgX = width/2; // 30  61/2
   int imgY = height/2; // 15  31/2
	
   /*
     if(IsEven(x))
     scrX--;
     if(IsEven(y))
     scrY--;
     if(IsEven(width))
     imgX--;
     if(IsEven(height))
     imgY--;
   */
   // Relys on it being odd for centering perfection
   screenX = scrX - imgX;
   screenY = scrY - imgY;
	
   SetOrigin(img, screenX, screenY);
}



void Image::AlignCenter(Image &img, int x, int y)
{
   int scrX = x;
   int scrY = y;
   int imgX = width/2;
   int imgY = height/2;
	
   // Relys on it being odd for centering perfection
   screenX = scrX - imgX;
   screenY = scrY - imgY;
	
   SetOrigin(img, screenX, screenY);
}



void Image::ShiftUp(Screen &screen, int num) { screenY -= num; }
void Image::ShiftDown(Screen &screen, int num) { screenY += num; }
void Image::ShiftLeft(Screen &screen, int num) { screenX -= num; }
void Image::ShiftRight(Screen &screen, int num) { screenX += num; }



void Image::FixSlants()
{
   for(int i = 0; i < Img.size(); ++i)
   {
      for(int j = 0; j < Img[i].size(); ++j)
      {
	 if(Img[i][j] == '/')
	    Img[i][j] = '\\';
	 else if(Img[i][j] == '\\')
	    Img[i][j] = '/';
      }
   }
}
