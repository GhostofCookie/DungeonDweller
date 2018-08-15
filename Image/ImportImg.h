///
/// ImportImg.h
///
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#pragma once

#include <fstream>
#include "Image.h"

/// The DefaultImg class represents a basic square image made of characters
class ImportImg : public Image
{
  private:
   /// The file name containing the image contents
   std::string fileName;
   /// The image in std::string form
   std::string imgStr;

   /// Function to create the image
   void Create();
   
   /// Helper function to append the lines from the file to create an image
   /// \param[in] file the file that is being accessed
   /// \param[in] img the std::string containing all the lines that make up the image
   void Import(std::string file, std::string &img);
	
  public:
   /// constructs an Image object from the given dimensions
   /// \param[in] file the file path to get the image from
   ImportImg(std::string file = "");

   /// Copy constructor to duplicate the given image
   /// \param[in] img the image to copy from
   ImportImg(const ImportImg &img);

   /// Destructor
   ~ImportImg();

   /// Overloaded Assignment operator
   /// \param[in] img the image to copy from
   ImportImg& operator=(const ImportImg &img);

   /// Function that returns the import image's file path
   std::string GetImageFile();
};