#include "RoomTree.h"
#include <iostream>
using namespace std;

int main() {
   RoomTree *Tree1;
   RoomTree *Tree2;
   RoomTree *Tree3;
   RoomTree *Tree4;

   Tree1 = new RoomTree(nullptr);
   Tree2 = new RoomTree(nullptr);
   Tree3 = new RoomTree(nullptr);
   Tree4 = new RoomTree(nullptr);
   Tree1->NewRoom('l',nullptr);
   Tree1->NewRoom('d',nullptr);
   Tree1->NewRoom('r',nullptr);
   Tree1->NewRoom('u',nullptr);
   Tree3->NewRoom('D',nullptr);
   Tree3->Move('D');
   Tree3->NewRoom('D',nullptr);
   Tree3->Move('D');
   Tree3->NewRoom('D',nullptr);
   Tree3->Move('D');
   Tree3->NewRoom('D',nullptr);
   Tree3->Move('D');
   Tree3->NewRoom('D',nullptr);
   Tree3->Move('D');

   delete Tree1;
   delete Tree2;
   delete Tree3;
   delete Tree4;
   return 0;
}
