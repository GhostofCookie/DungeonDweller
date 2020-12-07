#include "Room.h"
#define ROOMTYPES 4

Room::Room(std::map<char, std::vector<ImportImg>>& collection, int t, bool c)
	: type{ t }, complete{ c }
{
	// What type of room is generated e.g. treasure, puzzle, etc
	if (type < 0 || type > ROOMTYPES)
		type = RoomChance();
	// If an enemy room or Puzzle room
	if (type == 2 || type == 3)
		complete = false;


	// Find out how many rooms there are to pick from
	// All rooms are located at '0' in the std::map
	int roomCount = 0;
	for (unsigned int i = 0; i < collection['0'].size(); ++i)
		roomCount++;

	// Decides on one of the rooms in that set
	int num = Rand(roomCount);
	room = new ImportImg(collection['0'][num]);

	//Insert the appropriate images to fill the room
	GetRoom(collection);
	GetEventImages(collection);
}

Room::Room(const Room& r)
{
	std::string s = r.GetImageFile();
	delete room;
	room = new ImportImg(s);

	type = r.GetType();
}

Room::~Room()
{
	delete room;
	room = nullptr;
}

ImportImg Room::GetImage() const { return *room; }

std::string Room::GetImageFile() const { return room->GetImageFile(); }

int Room::GetType() const { return type; }

bool Room::IsComplete() const { return complete; }

void Room::GetRoom(std::map<char, std::vector<ImportImg>>& collection)
{
	std::map<char, int> setType;

	GetPoints();

	// Finds the correct images using points and then prints them onto room image
	for (unsigned int i = 0; i < point.size(); i++)
	{
		// Decides on a varient if there are more than 1 type of object
		if (collection[point[i].ch].size() > 1)
			setType.insert(std::pair<char, int>(point[i].ch, Rand(collection[point[i].ch].size())));
		else
			setType[point[i].ch] = 0;

		int num = setType.at(point[i].ch);

		// Permanently draws that object to the location on the room
		ImportImg img = collection[point[i].ch][num];
		img.AlignCenter(*room, point[i].x, point[i].y);
		img.Image::Draw(*room);
	}
}

void Room::GetPoints()
{
	// Move through the room image and save the locations found as a point
	for (int y = 0; y < room->GetRows(); ++y)
	{
		// seperates the characters from the digits (up, down, left, right)
		// that way they print over the rest of the images
		for (int x = 0; x < room->GetCols(); ++x)
		{
			if (isalpha(room->Img[y][x]))
			{
				Point p;
				p.x = x; p.y = y; p.ch = room->Img[y][x];
				point.insert(point.begin(), p);

			}
			else if (isdigit(room->Img[y][x]))
			{
				Point p;
				p.x = x; p.y = y; p.ch = room->Img[y][x];
				point.push_back(p);
			}
		}
	}
}

void Room::GetEventImages(std::map<char, std::vector<ImportImg>>& collection)
{

	switch (type)
	{
		//NPC Shop
	case 1:
		npc.Img() = ImportImg(collection['n'][0]);
		npc.Img().Image::AlignCenter(*room);
		npc.Img().Image::ShiftRight(*room, 10);
		npc.Img().Draw(*room);
		break;
		//NPC Enemy	 
	case 2:
		npc.Img() = ImportImg(collection['m'][0]);
		npc.Img().Image::AlignCenter(*room);
		npc.Img().Image::ShiftRight(*room, 10);
		npc.Img().Draw(*room);
		break;
		//NPC Puzzle
	case 3:
		npc.Img() = ImportImg(collection['n'][1]);
		npc.Img().Image::AlignCenter(*room);
		npc.Img().Image::ShiftRight(*room, 10);
		npc.Img().Draw(*room);
		break;
	default:
		break;
	}
}

void Room::AlignCenter(Viewport& viewport) { room->Image::AlignCenter(viewport); }

void Room::AlignLeft(Viewport& viewport) { room->Image::AlignLeft(viewport); }

void Room::AlignRight(Viewport& viewport) { room->Image::AlignRight(viewport); }

void Room::AlignTop(Viewport& viewport) { room->Image::AlignTop(viewport); }

void Room::AlignBottom(Viewport& viewport) { room->Image::AlignBottom(viewport); }

void Room::Draw(Viewport& viewport) { room->Image::Draw(viewport); }

void Room::Draw(Viewport& viewport, int y, int x) { room->Image::Draw(viewport, y, x); }

void Room::Draw(ImportImg& img) { room->Image::Draw(img); }

void Room::Draw(ImportImg& img, int y, int x) { room->Image::Draw(img, y, x); }

int Room::Rand(int n)
{
	n = rand() % n;
	return n;
}

int Room::RoomChance()
{
	bool selected = false;
	std::vector<int> chance = { 80, 5, 10, 5 }; // weight
	int roomType = 0;

	int outOf = 0; // total of the weights
	for (int i = 0; i < ROOMTYPES; i++)
		outOf += chance[i];


	// Function runs while a room has not been chosen
	do
	{
		// allows the index to start at a random location in the std::vector
		for (int r = Rand(ROOMTYPES); r < ROOMTYPES; r++)
		{
			int n = Rand(outOf);
			// trys to generate a random number less than the chance %
			if (n < chance[r])
			{
				selected = true;
				roomType = r;
			}
		}
	} while (!selected);

	return roomType;
}
