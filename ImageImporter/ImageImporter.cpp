#include "ImageImporter.h"

/// Default Constructor
/// \param[in] file the masterfile containing all other files
ImageImporter::ImageImporter(std::string file)
   : masterFile(file)
{ GetAllFilePaths(masterFile); }



/// Destructor
ImageImporter::~ImageImporter()
{
	
}



/// Function that reads in each file
/// and creates an image using the .txt file, then inserts the
/// image and the ID into a std::map
/// \param[in] file the master file being opened
void ImageImporter::GetAllFilePaths(const std::string &file)
{
   std::ifstream in;
   std::string curFile;
   char curKey;
	
	
   in.open(file);
	
   if(in)
   {
      while (!in.eof())
      {
	 std::string line; // reads in the file
			
	 getline(in, line, '\n');
	 if(line != "")
	 {
	    // get both the file and the ID
	    std::istringstream iss(line);
	    iss >> curFile >> curKey;

	    // if the key doesn't exist then create a key
	    if(collection.find(curKey) == collection.end())
	       collection.insert(std::pair<char, std::vector<ImportImg>>(curKey, {}));
	    // push the current image into that key
	    collection[curKey].push_back(ImportImg(curFile));
	 }
      }
      in.close();
		
   } else
      std::cout << "Empty or lost file? Couldn't locate: " << file << std::endl;
}
