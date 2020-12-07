/**
 * Viewport.h
 *
 * @author Reid Paulhus
 * @date Oct 20, 2017
 */

#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

 /** @brief This class represents an abstract base class in which different
  * screens can be created from the default
  */
class Viewport
{
public:
	/** Constructs an Image object from the given dimensions
	 * @param[in] h the height of the image, default to 33
	 * @param[in] w the width of the image, default to 101
	 */
	Viewport(int h = 33, int w = 101, int x = 0, int y = 0);

	/** Helper function to build the viewport
	 * @param[in] h the height of the viewport
	 * @param[in] w the width of the viewport
	 */
	void Initialize(int h, int w);

	/** Helper function to resize the viewport
	 * @param[in] h the height of the viewport
	 * @param[in] w the width of the viewport
	 */
	void Resize(int h, int w);

	/** Get the character at the given coordinates */
	const char& Get(int y, int x) const;

	/** Returns the height of the viewport */
	int GetRows() const;

	/** Returns the width of the viewport */
	int GetCols() const;

	/** Helper function to draw the border on the viewport */
	void DrawBorder();

	/** Fill the viewport with the default character */
	void Fill();

	/** Fill the viewport with a given character */
	void Fill(char ch);

	/** Sets the characters at the given location to the given character
	 * (rows are numbered from 0 from the top, and columns are numbered 0 from the left)
	 * If the location is invalid, simply ignore the request
	 * @param[in] y the y coordinate
	 * @param[in] x the x coordinate
	 * @param[in] ch the character used to draw on that location
	 */
	void Set(int y, int x, char ch);

	/** This function erases the contents of the viewport */
	void Erase();

	/** This function erases the contents and border of the viewport */
	void Wipe();

	/** Static method to print multiple views at once.
	 * @param[in] views The views to be printed to the screen.
	 */
	static void DisplayAll(const std::vector<std::shared_ptr<Viewport>>& views);

	/** Static method to print multiple views at once.
	 * @param[in] views The views to be printed to the screen.
	 */
	static void DisplayAll(const std::unordered_map<std::string, std::shared_ptr<Viewport>>& views);

	/** Overloaded std::ostream operator */
	friend std::ostream& operator<<(std::ostream& os, const Viewport& s);

	/** Overloaded std::ostream operator */
	friend std::ostream& operator<<(std::ostream& os, const Viewport* s);

protected:
	/** The height of the image, default to 0 */
	int height = 0;

	/** The width of the image, default to 0 */
	int width = 0;

	/** The origin coordinates of the screen from the top left corner. */
	int originX, originY;

	/** 2D std::vector representing the viewport object */
	std::vector<std::vector<char>> Window;
	std::vector<std::vector<char>> ChangeBuffer;
};

