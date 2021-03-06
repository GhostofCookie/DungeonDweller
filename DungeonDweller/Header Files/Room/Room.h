/**
 * Room.h
 *
 * @author Reid Paulhus
 * @date Oct 20, 2017
 */

#pragma once

#include <iostream>
#include <map>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include "Viewport.h"
#include "Image.h"
#include "DefaultImg.h"
#include "ImportImg.h"
#include "Character.h"
#include "Player.h"
#include "Npc.h"
#include "Item.h"
#include "MyConsumables.h"
#include "MyWeapons.h"

/** @brief The Room class defines random values that characterize a room's event.
 * It also applies appropriate images onto a given room image
 */
class Room
{
   /** A struct used to contain the location of characters from a room */
   struct Point
   {
      /** x coordinate */
      int x = -1;

      /** y coordinate */
      int y = -1;

      /** character stored */
      char ch = ' ';
   };
   
  private:
   /** A finalized version of the room with data values included. */
   ImportImg *room = nullptr;
   
   /** The type of room that will be generated */
   int type;
   
   /** An NPC that can be displayed in a room */
   Character npc;
   
   /** Helper function to output a random value from 0 - n
    * @param[in] n the range of the random number generated
    */
   int Rand(int n);
   
   /** Function to choose a random type - with weighting */
   int RoomChance();
   
   /** Constructs a Room object using the given image
    * @param[in] imgFiles collects all 'event' images for the rooms
    */
   void GetRoom(std::map<char, std::vector<ImportImg>> &imgFiles);
   
   /** Locates the key characters used to print other images to the room */
   void GetPoints();
   
   /** Print event images to the room based on type
    * @param[in] imgFiles the collection of images to use
    */
   void GetEventImages(std::map<char, std::vector<ImportImg>> &imgFiles);
   
  public:
   /** Constructs a Room object using the given image
    * @param[in] imgFiles the image used as the room
    */
   Room(std::map<char, std::vector<ImportImg>> &imgFiles, int type = -1, bool c = true);

   /** Copy Constructor
    * @param[in] r the room being copied
    */
   Room(const Room &r);

   /** Destroys the object */
   ~Room();

   /** The points of each image's key character */
   std::vector<Point> point; // stores the points to each key

   /** To indicate if a room has any events that need to take place */
   bool complete;

   /** Function that returns the image object */
   ImportImg GetImage() const;
   
   /** Function that returns the room's image file path */
   std::string GetImageFile() const;
   
   /** Function that returns the room's type */
   int GetType() const;

   /** Function that returns the room's type */
   bool IsComplete() const;
   
   /** Function to align to the center of the viewport
    * @param[in] viewport the viewport drawn on
    */
   void AlignCenter(Viewport &viewport);
   
   /** Function to align to the left of the viewport
    * @param[in] viewport the viewport drawn on
    */
   void AlignLeft(Viewport &viewport);
   
   /** Function to align to the right of the viewport
    * @param[in] viewport the viewport drawn on
    */
   void AlignRight(Viewport &viewport);
   
   /** Function to align to the top of the viewport
    * @param[in] viewport the viewport drawn on
    */
   void AlignTop(Viewport &viewport);
    
   /** Function to align the room to the bottom of the viewport
    * @param[in] viewport the viewport drawn on
    */
   void AlignBottom(Viewport &viewport);
	
   /** Function to draw to the viewport
    * @param[in] viewport the viewport drawn on
    */
   void Draw(Viewport &viewport);
   
   /** Function to draw to the viewport
    * @param[in] viewport the viewport drawn on
    */
   void Draw(Viewport &viewport, int y, int x);

   /** Function to draw to the viewport
    * @param[in] img the img drawn on
    */
   void Draw(ImportImg &img);

   /** Function to draw to the viewport
    * @param[in] img the img drawn on
    */
   void Draw(ImportImg &img, int y, int x);
   
   /** Function to return the npc */
   Character GetNpc() { return npc; }
};
