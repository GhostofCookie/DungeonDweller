#include "ImportImg.h"

/// Default Constructor
/// \param[in] file the masterfile used
ImportImg::ImportImg(string file)
   : fileName{file}
{
   screenX = screenY = 0;
   Create();

   height = GetRows();
   width = GetCols();
}


/// Copy constructor
/// \param[in] image the image being copied from
ImportImg::ImportImg(const ImportImg &image)
{
   Img = image.Img;
   imgStr = image.imgStr;

   height = image.GetRows();
   width = image.GetCols();

   screenX = image.screenX;
   screenY = image.screenY;
}



/// Copy constructor
/// \param[in] image the image being copied from
ImportImg::ImportImg(ImportImg &image)
{
   Img = image.Img;
   imgStr = image.imgStr;

   height = image.GetRows();
   width = image.GetCols();

   screenX = image.screenX;
   screenY = image.screenY;
}



/// Destructor
ImportImg::~ImportImg()
{
	
}



/// Overloaded assignment operator
/// \param[in] img the image to be copied from
ImportImg& ImportImg::operator=(const ImportImg& img)
{
   Image::operator=(img);
   
   height = img.GetRows();
   width = img.GetCols();
   
   screenX = img.screenX;
   screenY = img.screenY;

   Img = img.Img;
   imgStr = img.imgStr;
   
   return *this;
}


/// Function that creates an image based on the file name
void ImportImg::Create() { Import(fileName, imgStr); }



/// Function that imports from a file
/// \param[in] file the file to be opened
/// \param[in] the image in string form (can be used for later)
void ImportImg::Import(string file, string &img)
{
   ifstream in;
   string curLine;
	
   int index = 0;// index of the vector (height)
   img = "";// resets the room
	
   Img.clear();//ensures image is empty before beginning
   height = width = 0;

   if(file != "")
   {
   in.open(file);
   if(in)
   {
      // push back lines and insert them into the 2D vector
      while (getline(in, curLine, '\n'))
      {
	 Img.push_back(vector<char>());
	 for(unsigned int i = 0; i < curLine.length(); i++)
	    Img[index].push_back(curLine[i]);
			
	 index++;
      }
      //Sets the new height and width of the image dimensions
      //assumes that the vector must have been filled to have even gotten here
      width = static_cast<int>(Img[0].size());
      height = static_cast<int>(Img.size());
		
      in.close();
		
   } else
      cout << "Empty or lost file? Couldn't locate: " << file << endl;
   }
}



/// Function that returns the file path
string ImportImg::GetImageFile() { return imgStr; }
