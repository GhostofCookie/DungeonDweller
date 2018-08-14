#include "DefaultImg.h"

/// Default Constructor
/// \param[in] h the height of the image
/// \param[in] w the width of the image
/// \param[in] c the character used to draw the image
DefaultImg::DefaultImg(int h, int w, char c)
   : _height{h}, _width{w}, _ch{c}
{
   // couldn't assign directly needed to assign to non-static var first
   height = _height;
   width = _width;
   ch = _ch;
   Create();
}

/// Copy constructor
/// \param[in] image the image copied from
DefaultImg::DefaultImg(const DefaultImg &image)
{
   Img = image.Img;
   _height = height = image.GetRows();
   _width = width = image.GetCols();
   
}

/// Destructor
DefaultImg::~DefaultImg()
{
	
}

DefaultImg& DefaultImg::operator=(const DefaultImg &img)
{
   Image::operator=(img);
   return *this;
}

/// Function that creates the image by pushing back the std::vector
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



