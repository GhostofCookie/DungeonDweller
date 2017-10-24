//
// ImageImporter.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef ImageImporter_hpp
#define ImageImporter_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
//Image Headers
#include "Image.hpp"
#include "DefaultImg.hpp"
#include "ImportImg.hpp"
using namespace std;



/// The ImageImporter class can import multiple files and convert them into
/// Images to use at a later time
class ImageImporter
{
private:
	/// The main file used to open all files
	string masterFile;
	/// Each image is given an ID based on the type of image
	map<string, char> fileNames;
	/// All of the images excluding rooms used for events
	vector<Image> eventImages;
	
	
	
public:
	/// Object that opens a main file containing other file paths
	/// \param[in] file the master file used
	ImageImporter(string file = "");
	/// Does nothing
	~ImageImporter();
	
	/// Open and collect each image from each file path
	/// \param[in] file the masterfile being used
	void GetAllFilePaths(string &file);
	/// Helper function used to insert each image that is imported into a vector
	/// \param[in] img the container used to hold all the images
	void Collect(vector<Image*> &img);
	/// Helper function to draw the image correctly onto the room
	/// \param[in] img the image being drawn on
	/// \param[in] y the y coordinate
	/// \param[in] x the x coordinate
	/// \param[in] str the room string
	void DrawImage(ImportImg &img, int y, int x, const string &str);
};

#endif /* ImageImporter_hpp */
