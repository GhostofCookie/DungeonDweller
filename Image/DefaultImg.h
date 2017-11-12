//
// DefaultImg.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef DefaultImg_h
#define DefaultImg_h

#include "Image.h"


/// The DefaultImg class represents a basic square image made of characters
class DefaultImg : public Image
{
  private:
   /// The height of the image
   int _height;
   /// The width of the image
   int _width;

	
	
  public:
   /// Constructs an Image object from the given dimensions
   /// \param[in] h the height of the image, default to 3
   /// \param[in] w the width of the image, default to 6
   DefaultImg(int h = 3, int w = 6);
   /// Copy constructor duplicates a given picture
   /// \param[in] img the image to copy from
   DefaultImg(const DefaultImg& img);
   /// Copy constructor duplicates a given picture
   /// \param[in] img the image to copy from
   DefaultImg(DefaultImg& img);
   /// Destructor
   ~DefaultImg();
	
   /// Function to draw the image to the screen
   /// \param[in] scr the screen being drawn on
   /// \param[in] y the y coordinate
   /// \param[in] x the x coordinate
   void Draw(Screen& scr, int y, int x);
   /// Function to create the image
   void Create();
};

#endif /* DefaultImg_hpp */
