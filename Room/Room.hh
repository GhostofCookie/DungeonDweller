//
// Room.h
//
/// \author Reid Paulhus
/// \date Oct 20, 2017
///

#ifndef Room_hpp
#define Room_hpp

#include <iostream>
#include <vector>
#include <ctime>
//Image Headers
#include "Image.hpp"
#include "DefaultImg.hpp"
#include "ImportImg.hpp"
using namespace std;



/// The Room class defines random values that characterize a room's event.
/// It also applies appropriate images onto a given room image
class Room
{
private:
	/// A finalized version of the room with data values included
	Image *room;
	/// The type of room that will be generated
	int type;
	
	
	
public:
	/// Constructs a Room object using the given image
	/// \param[in] img the image used as the room
	Room(Image& img);
	/// Destroys the object
	~Room();

	/// Constructs a Room object using the given image
	/// \param[in] collection collects all 'event' images for the rooms
	void GetRoom(vector<Image*> &collection);
	/// Helper function to apply the images onto the room image
	void MakeChanges();
	
	/// Helper function to output a random value from 0 - n
	/// \param[in] n the range of the random number generated
	int Randomizer(int n);
};
#endif /* Room_hpp */
