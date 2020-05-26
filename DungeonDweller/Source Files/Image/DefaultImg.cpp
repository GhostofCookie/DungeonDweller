#include "DefaultImg.h"

DefaultImg::DefaultImg(int h, int w, char c)
   : _height{h}, _width{w}, _ch{c}
{
   // couldn't assign directly needed to assign to non-static var first
   height = _height;
   width = _width;
   ch = _ch;
   Create();
}

DefaultImg::DefaultImg(const DefaultImg &image)
{
   Img = image.Img;
   _height = height = image.GetRows();
   _width = width = image.GetCols();
   
}

DefaultImg::~DefaultImg()
{
	
}

DefaultImg& DefaultImg::operator=(const DefaultImg &img)
{
   Image::operator=(img);
   return *this;
}

void DefaultImg::Create()
{
   Img.clear();
   
   for(int i = 0; i < height; i++)
   {
      Img.push_back(std::vector<char>());
      for(int j = 0; j < width; j++)
	 Img[i].push_back(ch);
   }
}



