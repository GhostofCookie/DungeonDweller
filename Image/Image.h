//
// Image.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
//

#ifndef Image_h
#define Image_h

#include <iostream>
#include <cassert>
#include <vector>
#include "../Screen/Screen.h"
using namespace std;


/// \brief The Image class represents a 2D vector that displays an image on screen
class Image
{
  protected:
   /// The height of the image
   int height; 
   /// The width of the image
   int width;
   /// The character used to draw the image
   char ch;

   /// Returns true if the number is even
   /// \param[in] num the number to check
   bool IsEven(const int &num) const;


   
  public:
   /// The image - publically availiable to allow access to locations
   vector<vector<char>> Img;
   /// The screen x coordinate to draw on
   int screenX = 0;
   /// The screen y coordinate to draw on
   int screenY = 0;
   
   /// Constructs an Image object from the given dimensions
   /// \param[in] h the height of the image, default to 3
   /// \param[in] w the width of the image, default to 6
   Image(int h = 3, int w = 6, char c = '*');
   /// Copy constructor duplicates a given picture
   /// \param[in] img the image to copy from
   Image(Image &img);
   /// Copy constructor duplicates a given picture
   /// \param[in] img the image to copy from
   Image(const Image &img);
   /// Virtual Destructor
   virtual ~Image();
	
   /// Overloaded '=' operator
   /// \param[in] img the image being copied
   virtual Image& operator=(const Image &img);
  
   /// Helper function to draw onto the Screen object
   /// \param[in] scr the screen to draw on
   virtual void Draw(Screen &scr);
   
   /// Helper function to draw onto the Screen object
   /// \param[in] scr the screen to draw on
   /// \param[in] x the x coordinate
   /// \param[in] y the y coordinate
   virtual void Draw(Screen &scr, int y, int x);
   
   /// Helper function to draw onto the Screen object
   /// \param[in] img the screen to draw on
   virtual void Draw(Image &img);
   
   /// Helper function to draw onto the Screen object
   /// \param[in] img the screen to draw on
   /// \param[in] x the x coordinate
   /// \param[in] y the y coordinate
   virtual void Draw(Image &img, int y, int x);
	
   /// Function to create the image
   virtual void Create();
   
   /// Function to draw a border around the image
   /// \param[in] ch the character to draw the border with
   void DrawBorder(char ch);
   
   /// Function to erase the contents of the image and replace with spaces
   void Erase();
   
   /// Function to fill the enitre image with a character
   /// \param[in] ch the character the fill the image with
   void Fill(char ch);
   
   /// Function to set the coordinate of the image with a character
   /// \param[in] y the y coordinate to set
   /// \param[in] x the x coordniate to set
   /// \param[in] ch the character to set the coordinate with
   void Set(int y, int x, char ch);
	
   //ALIGN VIRTUAL MEMBER FUNCTIONS
   /// Function that sets a permanent location to draw from
   /// \param[in] scr the screen to access
   /// \param[in] y the y coordinate
   /// \param[in] x the x coordinate
   void SetOrigin(Screen &scr, int y, int x);
   
   /// Function that sets a permanent location to draw from
   /// \param[in] img the screen to access
   /// \param[in] y the y coordinate
   /// \param[in] x the x coordinate
   void SetOrigin(Image &img, int y, int x);
   
   /// Function that flips an image horizontally
   void FlipHoriz();
   
   /// Function that flips an image vertically
   void FlipVert();
	
   /// Helper function to align the image left
   /// \param[in] scr the screen to align to
   void AlignLeft(Screen &scr);
   
   /// Helper function to align the image right
   /// \param[in] scr the screen to align to
   void AlignRight(Screen &scr);
   
   /// Helper function to align the image center
   /// \param[in] scr the screen to align to
   void AlignCenter(Screen &scr);
   
   /// Helper function to align the image to the top
   /// \param[in] scr the screen to draw to
   void AlignTop(Screen &scr);
   
   /// Helper function to align the image to the bottom
   /// \param[in] scr the screen to draw to
   void AlignBottom(Screen &scr);
   
   /// Helper function to align the image left
   /// \param[in] img the screen to align to
   void AlignLeft(Image &img);
   
   /// Helper function to align the image right
   /// \param[in] img the image to align to
   void AlignRight(Image &img);
   
   /// Helper function to align the image to the center
   /// \param[in] img the image to align to
   void AlignCenter(Image &img);
   
   /// Helper function to align the image center
   /// \param[in] img the image to align to
   void AlignCenter(Image &img, int x, int y);
   
   /// Helper function to align the image to the top
   /// \param[in] img the image to align to
   void AlignTop(Image &img);
   
   /// Helper function to align the image to the bottom
   /// \param[in] img the image to draw to
   void AlignBottom(Image &img);
	
   /// Helper function to shift the image down
   /// \param[in] scr the screen the image will shift on
   /// \param[in] num the amount of shifting
   void ShiftDown(Screen &scr, int num);
   
   /// Helper function to shift the image right
   /// \param[in] scr the screen the image will shift on
   /// \param[in] num the amount of shifting
   void ShiftRight(Screen &scr, int num);
   
   /// Helper function to shift the image down
   /// \param[in] scr the screen the image will shift on
   /// \param[in] num the amount of shifting
   void ShiftDown(Image &img, int num);
   
   /// Helper function to shift the image right
   /// \param[in] img the screen the image will shift on
   /// \param[in] num the amount of shifting
   void ShiftRight(Image &img, int num);

   /// Helper function to shift the image up
   /// \param[in] scr the screen the image will shift on
   /// \param[in] num the amount of shifting
   void ShiftUp(int num);
   
   /// Helper function to shift the image left
   /// \param[in] img the screen the image will shift on
   /// \param[in] num the amount of shifting
   void ShiftLeft(int num);

   /// Returns the height of the image
   int GetRows() const;
   
   /// Returns the width of the image
   int GetCols() const;

   void CopyCoordinates(const Image &img) { screenY = img.screenY; screenX = img.screenX; }
	
   /// Helper function to switch the slant characters
   void FixSlants();
};

#endif /* Image_h */
