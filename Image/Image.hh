//
// Image.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
//

#ifndef Image_hpp
#define Image_hpp

#include <iostream>
#include <cassert>
#include <vector>
#include "Screen.hpp" 
using namespace std;



/// the Image class represents a 2d vector that displays an image on screen
class Image
{
protected:
	/// The screen x coordinate to draw on, default to 0
	int screenX = 0;
	/// The screen y coordinate to draw on, default to 0
	int screenY = 0;
	/// The height of the image
	int height;
	/// The width of the image
	int width;
	
	
	
public:
	/// Constructs an Image object from the given dimensions
	/// \param[in] h the height of the image, default to 3
	/// \param[in] w the width of the image, default to 6
	Image(int h = 3, int w = 6);
	/// Copy constructor duplicates a given picture
	/// \param[in] img the image to copy from
	Image(const Image& img);
	/// Copy constructor duplicates a given picture
	/// \param[in] img the image to copy from
	Image(Image& img);
	/// Virtual Destructor
	virtual ~Image();
	
	/// The image - publically availiable to allow access to locations
	vector<vector<char>> Img;
	
	/// Overloaded '=' operator
	/// \param[in] img the image being copied
	virtual void operator =(const Image& img);
	/// Returns the height of the image
	int GetRows() const;
	/// Returns the width of the image
	int GetCols() const;
	/// Returns true if the number is even
	/// \param[in] num the number to check
	bool IsEven(const int &num) const;
	/// Helper function to draw onto the Screen object
	/// \param[in] scr the screen to draw on
	virtual void Draw(Screen& scr);
	/// Helper function to draw onto the Screen object
	/// \param[in] scr the screen to draw on
	/// \param[in] x the x coordinate
	/// \param[in] y the y coordinate
	virtual void Draw(Screen& scr, int y, int x) = 0;
	
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
	/// Function that flips an image horizontally
	/// \param[in] scr the screen the image will flip on
	void FlipHoriz(Screen &scr);
	/// Function that flips an image vertically
	/// \param[in] scr the screen the image will flip on
	void FlipVert(Screen &scr);
	
	/// Helper function to align the image left
	/// \param[in] scr the screen to align to
	void AlignLeft(Screen &scr);
	/// Helper function to align the image right
	/// \param[in] scr the screen to align to
	void AlignRight(Screen &scr);
	/// Helper function to align the image center
	/// \param[in] scr the screen to align to
	void AlignCenter(Screen &scr);
	
	/// Helper function to shift the image up
	/// \param[in] scr the screen the image will shift on
	/// \param[in] num the amount of shifting
	void ShiftUp(Screen &scr, int num);
	/// Helper function to shift the image down
	/// \param[in] scr the screen the image will shift on
	/// \param[in] num the amount of shifting
	void ShiftDown(Screen &scr, int num);
	/// Helper function to shift the image left
	/// \param[in] scr the screen the image will shift on
	/// \param[in] num the amount of shifting
	void ShiftLeft(Screen &scr, int num);
	/// Helper function to shift the image right
	/// \param[in] scr the screen the image will shift on
	/// \param[in] num the amount of shifting
	void ShiftRight(Screen &scr, int num);
	
	/// Helper function to switch the slant characters
	void FixSlants();
};

#endif /* Image_hpp */