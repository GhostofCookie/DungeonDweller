//
// ImportImg.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef ImportedImg_hpp
#define ImportedImg_hpp

#include <fstream>
#include "Image.hpp"



/// The DefaultImg class represents a basic square image made of characters
class ImportImg : public Image
{
private:
	/// The file name containing the image contents
	string fileName;
	/// The image in string form
	string imgStr;
	
	
	
public:
	/// constructs an Image object from the given dimensions
	/// \param[in] file the file path to get the image from
	ImportImg(string file = "");
	/// Copy constructor to duplicate the given image
	/// \param[in] img the image to copy from
	ImportImg(const ImportImg& img);
	/// Copy constructor to duplicate the given image
	/// \param[in] img the image to copy from
	ImportImg(ImportImg& img);
	/// Destructor
	~ImportImg();
	
	/// Function to draw the image to the screen
	/// \param[in] scr the screen being drawn on
	/// \param[in] y the y coordinate
	/// \param[in] x the x coordinate
	void Draw(Screen& scr, int y, int x);
	/// Function to create the image
	void Create();
	
	/// Helper function to append the lines from the file to create an image
	/// \param[in] file the file that is being accessed
	/// \param[in] img the string containing all the lines that make up the image
	void Import(string file, string &img);
};

#endif /* ImportedImg_hpp */
