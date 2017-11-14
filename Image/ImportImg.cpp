#include "ImportImg.h"

/// Default Constructor
ImportImg::ImportImg(string file)
   : fileName{file}
{
   screenX = screenY = 0;
   Create();
}


//construct from base class
ImportImg::ImportImg(const ImportImg &image)
{
   Img = image.Img;
   height = image.height;
   width = image.width;
   imgStr = image.imgStr;
   screenX = image.screenX;
   screenY = image.screenY;
}



//construct from base class
ImportImg::ImportImg(ImportImg &image)
{
   Img = image.Img;
   height = image.height;
   width = image.width;
   imgStr = image.imgStr;
   screenX = image.screenX;
   screenY = image.screenY;
}



/// Destructor
ImportImg::~ImportImg()
{
	
}



void ImportImg::Create()
{
   Import(fileName, imgStr);
}



void ImportImg::Import(string file, string &img)
{
   ifstream in;
   string curLine;
	
   int index = 0;//index of the vector (height)
   img = "";//resets the room
	
   Img.clear();//ensures image is empty before beginning
   height = width = 0;
	
	
   in.open(file);
   //Only activates if the file is opened
   if(in)
   {
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



void ImportImg::Draw(Screen &screen, int y, int x)
{
   int imgY = y;
   int imgX = x;
	
   // An algorithm that moves through each element in the Img
   // and attempts to place on the screen with the given start location
   for(unsigned int i = 0; i < Img.size(); i++)
   {
      for(auto p = Img[i].begin(); p != Img[i].end(); ++p)
      {
	 if((imgX >= 0 || imgX < screen.GetCols()) && (imgY >= 0 || imgY < screen.GetRows()))
	    screen.Set(imgY, imgX, *p);
	 imgX++;
      }
      imgY++;
      imgX = x;
   }
   screen.DrawBorder();
}
