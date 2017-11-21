//
// RoomTree Header
//
/// \author Rylan Bueckert
/// \date Oct 25, 2017
///

#ifndef ROOMTREE_H
#define ROOMTREE_H
#include <iostream>
#include "../Room/Room.h"
using namespace std;

/// Class to represent the layout of rooms in a doubly linked tree-like format
class RoomTree {
   //Nested Class**************************************************************
   /// Class to represent nodes on the tree
   class Node {
     public:

      /// Node Constructor
      Node();

      /// Pointer to left child node
      Node* left;

      /// Pointer to right child node
      Node* right;

      /// Pointer to center child node
      Node* down;

      /// Pointer to parent node
      Node* up;

	  /// Direction toward the root
	  char RootDir;

      /// Pointer to the room
      Room* room;
   };
   //**************************************************************************

  public:

   /// RoomTree Constructor
   RoomTree(Room* rootRoom);

   /// RoomTree Destructor
   ~RoomTree();

   /// Inserts a new room at child (throws exeption if already occupied)
   /// \param[in] dir Direction of the new child (left(l) right(r) up(u) or down(d)
   /// \exception invalid_argument Thrown if the direction is invalid or space is occupied
   void NewRoom(char dir, Room* roomptr);

   /// Moves through the tree
   /// \param[in] dir Direction to move(left(l) right(r) up(u) or down(d))
   /// \return True if move was successfull, false otherwise
   /// \exception invalid_argument Thrown if the direction is invalid
   bool Move(char dir);

   /// Gives a const pointer to the room currently at for accessing
   /// \return A const pointer to current room
   const Room* At() const;

   /// Gives a pointer to current room
   /// \return Pointer to current room
   Room* At();

   /// Gives the height of the tree at the current room
   /// \returns the height of the current node
   unsigned int CurrentHeight() const;

  private:
   /// Helper function to assist in deleting the tree
   /// \param[in] tempRoot The root of the tree to be deleted
   void DeleteTree(Node *tempRoot);
   
   /// Root or starting room of the dungeon
   Node* root;

   /// Node of the current room
   Node* currNode;
};
#endif
