/**
 * DefaultImg.h
 *
 * @author Reid Paulhus
 * @date Oct 20, 2017
 */

#pragma once

#include "Image.h"

/** The DefaultImg class represents a basic square image made of characters. */
class DefaultImg : public Image
{
  private:
   /** The height of the image */
   int _height;
   /** The width of the image */
   int _width;
   /** The character used to draw the image */
   char _ch;

   /** Function to create the image */
   void Create();
	
  public:
   /** Constructs an Image object from the given dimensions
    * @param[in] h the height of the image, default to 3
    * @param[in] w the width of the image, default to 6
    */
   DefaultImg(int h = 3, int w = 6, char c = '$');

   /** Copy constructor duplicates a given picture
    * @param[in] img the image to copy from
    */
   DefaultImg(const DefaultImg &img);

   /** Destructor */
   ~DefaultImg();

   /** Overloaded Assignment operator
    * @param[in] img the image to copy from
    */
   DefaultImg& operator=(const DefaultImg &img);
};
