#include "ImportImg.h"
#include <string>

ImportImg::ImportImg(std::string file)
   : fileName{file}
{
   screenX = screenY = 0;
   Create();

   height = GetRows();
   width = GetCols();
}

ImportImg::ImportImg(const ImportImg &image)
{
   Img = image.Img;
   imgStr = image.imgStr;

   height = image.GetRows();
   width = image.GetCols();

   screenX = image.screenX;
   screenY = image.screenY;
}

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

void ImportImg::Create() { Import(fileName, imgStr); }

void ImportImg::Import(std::string file, std::string &img)
{
   std::ifstream in;
   std::string curLine;
	
   int index = 0;// index of the std::vector (height)
   img = "";// resets the room
	
   Img.clear();//ensures image is empty before beginning
   height = width = 0;

   if(file != "")
   {
   in.open(file);
   if(in)
   {
      // push back lines and insert them into the 2D std::vector
      while (getline(in, curLine, '\n'))
      {
	 Img.push_back(std::vector<char>());
	 for(unsigned int i = 0; i < curLine.length(); i++)
	    Img[index].push_back(curLine[i]);
			
	 index++;
      }
      //Sets the new height and width of the image dimensions
      //assumes that the std::vector must have been filled to have even gotten here
      width = static_cast<int>(Img[0].size());
      height = static_cast<int>(Img.size());
		
      in.close();
		
   } else
      std::cout << "Empty or lost file? Couldn't locate: " << file << std::endl;
   }
}

std::string ImportImg::GetImageFile() { return imgStr; }
