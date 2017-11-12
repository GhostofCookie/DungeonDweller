#include "DefaultImg.h"

/// Default Constructor
DefaultImg::DefaultImg(int h, int w)
   : _height{h}, _width{w}
{
   //couldn't assign directly needed to assign to non-static var first
   height = _height;
   width = _width;
   Create();
}



DefaultImg::DefaultImg(const DefaultImg &image)
{
   Img = image.Img;
   _height = image.GetRows();
   _width = image.GetCols();
}



DefaultImg::DefaultImg(DefaultImg &image)
{
   Img = image.Img;
   _height = image.GetRows();
   _width = image.GetCols();
}



/// Destructor
DefaultImg::~DefaultImg()
{
	
}



void DefaultImg::Draw(Screen &screen, int y, int x)
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



void DefaultImg::Create()
{
   for(int i = 0; i < height; i++)
   {
      Img.push_back(vector<char>());
      for(int j = 0; j < width; j++)
	 Img[i].push_back('*');
   }
}
