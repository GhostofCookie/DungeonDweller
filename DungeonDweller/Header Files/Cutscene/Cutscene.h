#pragma once

#ifdef	__linux__
#include <unistd.h>
#elif _WIN32
#include <stdlib.h>
#endif

#include "Screen.h"
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
#include "Room.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <memory>

#define RESOURCE_DIR(n) std::string("../ResourceFiles/Art")+n

/** @brief This class runs cutscenes that improve the quality of room transitions. */
class Cutscene
{
	/** Struct to contain the points of all 4 exits in a room */
	struct Point
	{
		int y = 0;
		int x = 0;
	};

public:
	/** Constructor */
	Cutscene(std::shared_ptr<Screen> scr,
		ImportImg characterImg = ImportImg(RESOURCE_DIR("/Player/DD_Player.txt")),
		ImportImg roomImg = ImportImg(RESOURCE_DIR("/Rooms/DD_Room_Square.txt")),
		Room* roomTemplate = nullptr);

	/** Sets the screen object for this object. */
	void SetScreen(std::shared_ptr<Screen> screen);

	/** Function to animate an image this direction */
	void EnterTopToCenter();

	/** Function to animate an image this direction */
	void EnterBottomToCenter();

	/** Function to animate an image this direction */
	void EnterLeftToCenter();

	/** Function to animate an image this direction */
	void EnterRightToCenter();

	/** Function to animate an image this direction */
	void ExitCenterToTop();

	/** Function to animate an image this direction */
	void ExitCenterToBottom();

	/** Function to animate an image this direction */
	void ExitCenterToLeft();

	/** Function to animate an image this direction */
	void ExitCenterToRight();

	/** Function to animate an image to the left */
	void ExitLeft();

	/** Function to animate an image to the right */
	void ExitRight();

	/** Function to animate an image to the top */
	void ExitUp();

	/** Function to animate an image to the left */
	void ExitDown();

	/** Function to animate an image from the left */
	void EnterLeft();

	/** Function to animate an image from the right */
	void EnterRight();

	/** Function to animate an image from the top */
	void EnterUp();

	/** Function to animate an image from the bottom */
	void EnterDown();

	/** Function to save the animated image's current position */
	void SaveCurrentPosition();

	/** Function to animate an intro * hardcoded in every cutscene obj */
	void Intro();

	/** Function to animate an outro * hardcoded in every cutscene obj */
	void Outro();

	/** Function to animate an encounter * hardcoded in every cutscene obj */
	void MonsterEncounter();

private:
	/** Helper function that returns the location of a character
	 * Helper function to shift an image up and handle output
	 * @param[in] y the y coordinate to save
	 * @param[in] x the x coordinate to save
	 * @param[in] c the character to look for
	 * @param[in] r the room to gain access to its points
	 */
	void FindCharacter(int& y, int& x, const char c, const Room& r);

	/** Helper function to shift an image up and handle output
	 * @param[in] originY the y coordinate to begin from
	 * @param[in] originX the x coordinate to begin from
	 * @param[in] count the amount to move by
	 */
	void MoveUp(const int originY, const int originX, const int count);

	/** Helper function to shift an image down and handle output
	 * Helper function to shift an image up and handle output
	 * @param[in] originY the y coordinate to begin from
	 * @param[in] originX the x coordinate to begin from
	 * @param[in] count the amount to move by
	 */
	void MoveDown(const int originY, const int originX, const int count);

	/** Helper function to shift an image left and handle output
	 * Helper function to shift an image up and handle output
	 * @param[in] originY the y coordinate to begin from
	 * @param[in] originX the x coordinate to begin from
	 * @param[in] count the amount to move by
	 */
	void MoveLeft(const int originY, const int originX, const int count);

	/** Helper function to shift an image right and handle output
	 * Helper function to shift an image up and handle output
	 * @param[in] originY the y coordinate to begin from
	 * @param[in] originX the x coordinate to begin from
	 * @param[in] count the amount to move by
	 */
	void MoveRight(const int originY, const int originX, const int count);

	/** x coordinate to keep track of the center ALWAYS */
	int centerX = 0;

	/** y coordinate to keep track of the center ALWAYS */
	int centerY = 0;

	/** variable to keep track of a position for animating */
	int savedX = 0;

	/** variable to keep track of a position for animating */
	int savedY = 0;

	/** temporary variable to keep track of a character found */
	int foundX = 0;

	/** temporary variable to keep track of character found */
	int foundY = 0;

	/** screen to draw the cutscene on */
	std::shared_ptr<Screen> screen;

	/** container to store the 4 directions of the given room */
	std::vector<Point> point;

	/** the animated image */
	ImportImg img;

	/** the room to be animated in */
	ImportImg room;

	/** the npc to be in the room */
	ImportImg npc;

	/** the type of room */
	int type = 0;
};
