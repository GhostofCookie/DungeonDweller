#ifnedef ROOMTREE_H
#define ROOMTREE_H
#include <iostream>
#include "Room/Room.h"
using namespace std;

class Room {
   //Nested Class****************************************************************
   class Node {
     public:
      node();

      Node* left;
      Node* right;
      Node* center;
      Node* parent;
      Room* room;
   };
   //****************************************************************************

  public:
   RoomTree();
   ~RoomTree();

   void newRoom(char dir);
   void move(char dir);
   Room* getRoom();

  private:
   Ndoe* root;
   Node* currNode;
};
#endif
