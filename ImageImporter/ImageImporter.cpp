#include "ImageImporter.h"

/// Default Constructor
/// \param[in] file the masterfile containing all other files
ImageImporter::ImageImporter(string file)
   : masterFile(file)
{ GetAllFilePaths(masterFile); }



/// Destructor
ImageImporter::~ImageImporter()
{
	
}



/// Function that reads in each file
/// and creates an image using the .txt file, then inserts the
/// image and the ID into a map
/// \param[in] file the master file being opened
void ImageImporter::GetAllFilePaths(const string &file)
{
   ifstream in;
   string curFile;
   char curKey;
	
	
   in.open(file);
	
   if(in)
   {
      while (!in.eof())
      {
	 string line; // reads in the file
			
	 getline(in, line, '\n');
	 if(line != "")
	 {
	    // get both the file and the ID
	    istringstream iss(line);
	    iss >> curFile >> curKey;

	    // if the key doesn't exist then create a key
	    if(collection.find(curKey) == collection.end())
	       collection.insert(pair<char, vector<ImportImg>>(curKey, {}));
	    // push the current image into that key
	    collection[curKey].push_back(ImportImg(curFile));
	 }
      }
      in.close();
		
   } else
      cout << "Empty or lost file? Couldn't locate: " << file << endl;
}
