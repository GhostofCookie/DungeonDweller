#include "ImageImporter.h"

ImageImporter::ImageImporter(string file)
   : masterFile(file)
{
   GetAllFilePaths(masterFile);
}


ImageImporter::~ImageImporter()
{
	
}



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
	    istringstream iss(line);
	    iss >> curFile >> curKey;
				
	    if(collection.find(curKey) == collection.end())
	       collection.insert(pair<char, vector<ImportImg>>(curKey, {}));
				
	    collection[curKey].push_back(ImportImg(curFile));
	 }
      }
      in.close();
		
   } else
      cout << "Empty or lost file? Couldn't locate: " << file << endl;
}
