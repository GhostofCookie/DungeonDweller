///
/// ImageImporter.h
///
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "../Image/Image.h"
#include "../Image/ImportImg.h"

/// \brief The ImageImporter class can import multiple files and convert them into
/// Images to use at a later time
class ImageImporter
{
  private:
   /// The main file used to open all files
   std::string masterFile;
	
   /// Open and collect each image from each file path
   /// \param[in] file the masterfile being used
   void GetAllFilePaths(const std::string &file);
	
  public:
   /// Object that opens a main file containing other file paths
   /// \param[in] file the master file used
   ImageImporter(std::string file = "../DD_Art/DD_MasterFileLinux.txt");
   /// Deconstuctor
   ~ImageImporter();
		
   /// Each additional image is given an ID based on the type
   std::map<char, std::vector<ImportImg>> collection;
};

