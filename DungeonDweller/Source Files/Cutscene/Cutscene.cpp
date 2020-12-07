#include "Cutscene.h"
#include <stdlib.h>

#ifdef __linux__
#define HORIZSPEED 25000 //This is half the vert speed in microseconds.
#define VERTSPEED HORIZSPEED*2
#elif _WIN32
#include "Windows.h"
#define HORIZSPEED 2//100 //This is half the vert speed in microseconds.
#define VERTSPEED HORIZSPEED*2
#endif

void Wait(size_t time)
{
#ifdef __linux__
	usleep(200000);
#else
	Sleep(100);
#endif
}


Cutscene::Cutscene(std::shared_ptr<Viewport> view, ImportImg characterImg, ImportImg roomImg, Room* tempRoom)
{
	// initialize the animated img and the background
	img = ImportImg(characterImg);
	room = ImportImg(roomImg);
	npc = ImportImg(characterImg);

	viewport = view;

	// set the center point to gain access later on
	room.AlignCenter(*viewport);
	room.ShiftUp(1);

	// preset the room to be in the center for all animations
	img.AlignCenter(room);
	centerY = img.screenY;
	centerX = img.screenX;

	// reserve and locate points for 4 exit locations per room
	if (tempRoom != nullptr)
	{
		point.resize(4);
		FindCharacter(point[0].y, point[0].x, '1', *tempRoom); // up
		FindCharacter(point[1].y, point[1].x, '2', *tempRoom); // right
		FindCharacter(point[2].y, point[2].x, '3', *tempRoom); // down
		FindCharacter(point[3].y, point[3].x, '4', *tempRoom); // left
		type = tempRoom->GetType();
	}
}

void Cutscene::SetScreen(std::shared_ptr<Viewport> viewport)
{
	this->viewport = viewport;
}

void Cutscene::MoveUp(const int originY, const int originX, const int d)
{
	// This loop will animate the image and print to the viewport
	int n = 0;
	while (n < d)
	{
		img.ShiftUp(1);
		n++;

		viewport->Erase();
		room.Draw(*viewport);
		img.Draw(*viewport);
		std::cout << viewport;
		Wait(VERTSPEED);
	}
}

void Cutscene::MoveDown(const int originY, const int originX, const int d)
{
	// This loop will animate the image and print to the viewport
	int n = 0;
	while (n < d)
	{
		img.ShiftDown(*viewport, 1);
		n++;

		viewport->Erase();
		room.Draw(*viewport);
		img.Draw(*viewport);
		std::cout << viewport;
		Wait(VERTSPEED);
	}
}

void Cutscene::MoveLeft(const int originY, const int originX, const int d)
{
	img.SetOrigin(*viewport, originY, originX);
	// This loop will animate the image and print to the viewport
	int n = 0;
	while (n < d)
	{
		img.ShiftLeft(1);
		n++;

		viewport->Erase();
		room.Draw(*viewport);
		img.Draw(*viewport);

		std::cout << viewport;
#ifdef __linux__
		usleep(HORIZSPEED);
#else
		Sleep(HORIZSPEED);
#endif
	}
}

void Cutscene::MoveRight(const int originY, const int originX, const int d)
{
	img.SetOrigin(*viewport, originY, originX);
	// This loop will animate the image and print to the viewport
	int n = 0;
	while (n < d)
	{
		img.ShiftRight(*viewport, 1);
		n++;

		viewport->Erase();
		room.Draw(*viewport);
		img.Draw(*viewport);

		std::cout << viewport;
		Wait(HORIZSPEED);
	}
}

void Cutscene::EnterTopToCenter()
{
	img.AlignTop(*viewport);
	MoveDown(img.screenY, img.screenX, savedY - img.screenY);
}

void Cutscene::EnterBottomToCenter()
{
	img.AlignBottom(*viewport);
	MoveUp(img.screenY, img.screenX, img.screenY - savedY);
}

void Cutscene::EnterLeftToCenter()
{
	img.AlignLeft(*viewport);
	MoveRight(img.screenY, img.screenX, savedX - img.screenX);
}

void Cutscene::EnterRightToCenter()
{
	img.AlignRight(*viewport);
	MoveLeft(img.screenY, img.screenX, img.screenX - savedX);
}

void Cutscene::ExitCenterToTop()
{
	MoveUp(img.screenY, img.screenX, viewport->GetRows() - img.screenY);
}

void Cutscene::ExitCenterToBottom()
{
	MoveDown(img.screenY, img.screenX, viewport->GetRows() - img.screenY);
}

void Cutscene::ExitCenterToLeft()
{
	MoveLeft(img.screenY, img.screenX, room.GetCols() / 2 + img.GetCols() / 2);
}

void Cutscene::ExitCenterToRight()
{
	MoveRight(img.screenY, img.screenX, room.GetCols() / 2 + img.GetCols() / 2);
}

void Cutscene::ExitLeft()
{
	// adjust for character centering
	foundY = point[3].y - img.GetRows() / 2;
	foundX = point[3].x - img.GetCols();

	// if exiting down the center
	if (img.screenY == foundY) {
		while (img.screenX > foundX)
			MoveLeft(img.screenY, img.screenX, 1);

		// if exiting left side
	}
	else if (img.screenY > foundY) {
		while (img.screenY > foundY)
			MoveUp(img.screenY, img.screenX, 1);
		while (img.screenX > foundX)
			MoveLeft(img.screenY, img.screenX, 1);

		// if on the right side
	}
	else {
		while (img.screenY < foundY)
			MoveDown(img.screenY, img.screenX, 1);
		while (img.screenX > foundX)
			MoveLeft(img.screenY, img.screenX, 1);
	}
}

void Cutscene::ExitRight()
{
	// adjust for character centering
	foundY = point[1].y - img.GetRows() / 2;
	foundX = point[1].x + img.GetCols();

	// if exiting down the center
	if (img.screenY == foundY) {
		while (img.screenX < foundX)
			MoveRight(img.screenY, img.screenX, 1);

		// if exiting left side
	}
	else if (img.screenY > foundY) {
		while (img.screenY > foundY)
			MoveUp(img.screenY, img.screenX, 1);
		while (img.screenX < foundX)
			MoveRight(img.screenY, img.screenX, 1);

		// if on the right side
	}
	else {
		while (img.screenY < foundY)
			MoveDown(img.screenY, img.screenX, 1);
		while (img.screenX < foundX)
			MoveRight(img.screenY, img.screenX, 1);
	}
}

void Cutscene::ExitUp()
{
	// adjust for character centering
	foundY = point[0].y +img.GetRows();
	foundX = point[0].x +img.GetCols() / 2;

	// if exiting down the center
	if (img.screenX == foundX) {
		while (img.screenY != foundY)
			MoveUp(img.screenY, img.screenX, 1);

		// if exiting left side
	}
	else if (img.screenX > foundX) {
		while (img.screenX > foundX)
			MoveLeft(img.screenY, img.screenX, 1);
		while (img.screenY > foundY)
			MoveUp(img.screenY, img.screenX, 1);

		// if on the right side
	}
	else {
		while (img.screenX < foundX)
			MoveRight(img.screenY, img.screenX, 1);
		while (img.screenY > foundY)
			MoveUp(img.screenY, img.screenX, 1);
	}
}

void Cutscene::ExitDown()
{
	// adjust for character centering
	foundY = point[2].y + img.GetRows();
	foundX = point[2].x - img.GetCols() / 2;

	// if exiting down the center
	if (img.screenX == foundX) {
		while (img.screenY < foundY)
			MoveDown(img.screenY, img.screenX, 1);

		// if exiting left side
	}
	else if (img.screenX > foundX) {
		while (img.screenX > foundX)
			MoveLeft(img.screenY, img.screenX, 1);
		while (img.screenY < foundY)
			MoveDown(img.screenY, img.screenX, 1);

		// if on the right side
	}
	else {
		while (img.screenX < foundX)
			MoveRight(img.screenY, img.screenX, 1);
		while (img.screenY < foundY)
			MoveDown(img.screenY, img.screenX, 1);
	}
}

void Cutscene::EnterLeft()
{
	// adjust for character centering
	img.screenY = point[3].y - img.GetRows() / 2;
	img.screenX = point[3].x - img.GetCols();

	// if entering from the center
	if (img.screenY == centerY) {
		while (img.screenX < centerX)
			MoveRight(img.screenY, img.screenX, 1);

		// if entering from the right
	}
	else if (img.screenY > centerY) {
		while (img.screenX < centerX)
			MoveRight(img.screenY, img.screenX, 1);
		while (img.screenY > centerY)
			MoveUp(img.screenY, img.screenX, 1);

		// if entering from the left
	}
	else {
		while (img.screenX < centerX)
			MoveRight(img.screenY, img.screenX, 1);
		while (img.screenY < centerY)
			MoveDown(img.screenY, img.screenX, 1);
	}
}

void Cutscene::EnterRight()
{
	// adjust for character centering
	img.screenY = point[1].y - img.GetRows() / 2;
	img.screenX = point[1].x - img.GetCols();

	// if entering from the center
	if (img.screenY == centerY) {
		while (img.screenX > centerX)
			MoveLeft(img.screenY, img.screenX, 1);

		// if entering from the right
	}
	else if (img.screenY > centerY) {
		while (img.screenX > centerX)
			MoveLeft(img.screenY, img.screenX, 1);
		while (img.screenY > centerY)
			MoveUp(img.screenY, img.screenX, 1);

		// if entering from the left
	}
	else {
		while (img.screenX > centerX)
			MoveLeft(img.screenY, img.screenX, 1);
		while (img.screenY < centerY)
			MoveDown(img.screenY, img.screenX, 1);
	}
}

void Cutscene::EnterUp()
{
	// adjust for character centering
	img.screenY = point[0].y - img.GetRows();
	img.screenX = point[0].x - img.GetCols() / 2;

	// if entering from the center
	if (img.screenX == centerX) {
		while (img.screenY < centerY)
			MoveDown(img.screenY, img.screenX, 1);

		// if entering from the right
	}
	else if (img.screenX > centerX) {
		while (img.screenY < centerY)
			MoveDown(img.screenY, img.screenX, 1);
		while (img.screenX > centerX)
			MoveLeft(img.screenY, img.screenX, 1);

		// if entering from the left
	}
	else {
		while (img.screenY < centerY)
			MoveDown(img.screenY, img.screenX, 1);
		while (img.screenX < centerX)
			MoveRight(img.screenY, img.screenX, 1);
	}
}

void Cutscene::EnterDown()
{
	// adjust for character centering
	img.screenY = point[2].y + img.GetRows();
	img.screenX = point[2].x - img.GetCols() / 2;

	// if entering from the center
	if (img.screenX == centerX) {
		while (img.screenY > centerY)
			MoveUp(img.screenY, img.screenX, 1);

		// if entering from the right
	}
	else if (img.screenX > centerX) {
		while (img.screenY > centerY)
			MoveUp(img.screenY, img.screenX, 1);
		while (img.screenX > centerX)
			MoveLeft(img.screenY, img.screenX, 1);

		// if entering from the left
	}
	else {
		while (img.screenY > centerY)
			MoveUp(img.screenY, img.screenX, 1);
		while (img.screenX < centerX)
			MoveRight(img.screenY, img.screenX, 1);
	}
}

void Cutscene::SaveCurrentPosition()
{
	// save the latest coordinates passed to it
	savedX = img.screenX;
	savedY = img.screenY;
}

void Cutscene::FindCharacter(int& y, int& x, const char c, const Room& r)
{
	// iterate through the points inside the room object
	for (auto i = r.point.begin(); i != r.point.end(); ++i)
	{
		if (i->ch == c)
		{
			y = i->y;
			x = i->x;
			break;
		}
	}
}

void Cutscene::Intro()
{
	ImportImg title = ImportImg("../ResourceFiles/Art/Credits/title.txt");

	std::string play = "[P] Play Game";
	std::string quit = "[Q] Quit Game";

	title.AlignCenter(*viewport);
	title.ShiftDown(*viewport, viewport->GetRows() / 2 + title.GetRows());

	// This loop draws the title up the viewport
	int i = 0;
	while (i++ < viewport->GetRows() / 2 + title.GetRows())
	{

		title.Draw(*viewport);
		std::cout << viewport;

		viewport->Erase();
		title.ShiftUp(1);

#ifdef __linux__
		usleep(200000);
#else
		Sleep(100);
#endif
	}

	// initialize where the menu options begin to print
	int playX = viewport->GetCols() / 2 - static_cast<int>(play.length() * 2);
	int quitX = viewport->GetCols() / 2 + static_cast<int>(quit.length());

	// iterate through the char array printing each character one at a time
	for (unsigned int i = 0; i < play.length(); i++)
	{
		title.Draw(*viewport);
		viewport->Set(viewport->GetRows() - static_cast<int>(play.length()) / 2, playX++, play[i]);

		std::cout << viewport;

#ifdef __linux__
		usleep(100000);
#else
		Sleep(10);
#endif
	}

	// iterate through the char array printing each character one at a time
	for (unsigned int i = 0; i < quit.length(); i++)
	{
		title.Draw(*viewport);
		viewport->Set(viewport->GetRows() - static_cast<int>(quit.length()) / 2, quitX++, quit[i]);

		std::cout << viewport;

#ifdef __linux__
		usleep(100000);
#else
		Sleep(10);
#endif
	}
}

void Cutscene::Outro()
{
	ImportImg credits = ImportImg("../ResourceFiles/Art/Credits/credits.txt");

	credits.AlignCenter(*viewport);
	credits.ShiftDown(*viewport, viewport->GetRows() / 2 + credits.GetRows());

	// This loop draws the title up the viewport
	int i = 0;
	while (i++ < viewport->GetRows() / 2 + credits.GetRows())
	{


		credits.Draw(*viewport);
		std::cout << viewport;

		viewport->Erase();
		credits.ShiftUp(1);
#ifdef __linux__
		usleep(VERTSPEED * 2);
#endif
	}

#ifdef __linux__
	usleep(3000000);
#endif
}

void Cutscene::MonsterEncounter()
{
	const int am = 1;
	Viewport view;
	// Fill from the ends into the center
	int left = 1, right = view.GetCols() - 2;
	while (left <= right)
	{
		int j = view.GetRows() - 2;
		for (int i = 1; i < view.GetRows()-1; i++, j--)
			for (int k = 0; k < am; k++)
			{
				view.Set(i, left + k, '*');
				view.Set(j, right - k, '*');
			}

		std::cout << view;

		left += am;
		right -= am;
	}

	// Erase from the middle out
	left = view.GetCols() / 2, right = view.GetCols() / 2;
	while (left > 0)
	{
		int j = view.GetRows() - 2;
		for (int i = 1; i < view.GetRows()-1; i++, j--)
			for (int k = 0; k < am; k++)
			{
				view.Set(i, left + k, viewport->Get(i, left+k));
				view.Set(j, right - k, viewport->Get(j, right - k));
			}

		std::cout << view;

		left -= am;
		right += am;
	}
}
