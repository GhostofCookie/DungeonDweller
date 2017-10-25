//
// RoomTree Header
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifnedef ROOMTREE_H
#define ROOMTREE_H
#include <iostream>
#include "Room/Room.h"
using namespace std;

/// Class to represent the layout of rooms in a doubly linked tree-like format
class Room {
   //Nested Class****************************************************************
   /// Class to represent nodes on the tree
   class Node {
     public:

      /// Node Constructor
      node();

      /// Pointer to left child node
      Node* left;

      /// Pointer to right child node
      Node* right;

      /// Pointer to center child node
      Node* center;

      /// Pointer to parent node
      Node* parent;

      /// Pointer to the room
      Room* room;
   };
   //****************************************************************************

  public:

   /// RoomTree Constructor
   RoomTree();

   /// RoomTree Destructor
   ~RoomTree();

   /// Inserts a new room at child (throws exeption if already occupied)
   /// \param[in] dir Direction of the new child (left(l) right(r) or center(c))
   void newRoom(char dir);

   /// Moves through the tree
   /// \param[in] dir Direction to move(left(l) right(r) center(c) or parent(p))
   void move(char dir);

   /// Gives a pointer to the room currently at
   /// \return Pointer to current room
   Room* at();

  private:

   /// Root or starting room of the dungeon
   Node* root;

   /// Node of the current room
   Node* currNode;
};
#endif
