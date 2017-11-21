//
// Screen.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef Screen_h
#define Screen_h

#include <iostream>
#include <vector>
using namespace std;


/// This class represents an abstract base class in which different
/// screens can be created from the default
class Screen
{	
  protected:
   /// The height of the image, default to 0
   int height = 0;
   /// The width of the image, default to 0
   int width = 0;
   /// 2D vector representing the screen object
   vector<vector<char>> Window;
	
	
	
  public:
   /// Constructs an Image object from the given dimensions
   /// \param[in] h the height of the image, default to 33
   /// \param[in] w the width of the image, default to 101
   /// \param[in] ch the default character to draw the border with
   Screen(int h = 33, int w = 101, char ch = '-');
   /// Virtual Destructor
   virtual ~Screen();
	
   /// Controls whether or not a screen will have an outline
   bool outlineOn = true;
   /// the character used to draw the screen border
   char outlineCh;
	
   /// Helper function to build the screen
   /// \param[in] h the height of the screen
   /// \param[in] w the width of the screen
   void Initialize(int h, int w);
   /// Helper function to resize the screen
   /// \param[in] h the height of the screen
   /// \param[in] w the width of the screen
   void Resize(int h, int w);
	
   /// Returns the height of the screen
   int GetRows() const;
   /// Returns the width of the screen
   int GetCols() const;
   /// Returns the center of the screen
   int GetCenterPnt() const;
   /// Returns true if the number is even
   /// \param[in] num the number to check
   bool IsEven(const int &num) const;
	
   /// Helper function to swap out the character used to draw the border
   /// \param[in] ch the character used to create the outline
   void NewOutlineCh(char ch);
   /// Helper function to switch the border character
   /// \param[in] ch the character used to draw the border
   void DrawBorder(char ch);
   /// Helper function to draw the border on the screen
   void DrawBorder();
   /// Fill the screen with the default character
   void Fill();
   /// Fill the screen with a given character
   void Fill(char ch);
	
   /// Sets the characters at the given location to the given character
   // (rows are numbered from 0 from the top, and columns are numbered 0 from the left)
   // If the location is invalid, simply ignore the request
   /// \param[in] y the y coordinate
   /// \param[in] x the x coordinate
   /// \param[in] ch the character used to draw on that location
   void Set(int y, int x, char ch);
	
   /// This function erases the contents of the screen and resets
   void Erase();
	
   /// Overloaded ostream operator
   friend ostream& operator <<(ostream &os, const Screen *s);
   /// Overloaded ostream operator
   friend ostream& operator <<(ostream &os, const Screen &s);
};

#endif /* Screen_h */

