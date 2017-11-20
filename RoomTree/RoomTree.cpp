//
// RoomTree Implementation
//
/// \author Rylan Bueckert
/// \date Nov 10, 2017
///

#include "RoomTree.h"
#include <stdexcept>
#include <cctype>
using namespace std;

//*****************************************************************************
/// Node constructor
//*****************************************************************************
RoomTree::Node::Node()
{
   left = nullptr;
   right = nullptr;
   center = nullptr;
   parent = nullptr;
}

//*****************************************************************************
/// RoomTree Construtor
//*****************************************************************************
RoomTree::RoomTree(Room* rootRoom)
{
   root = new Node;
   root->room = rootRoom;
   currNode = root;
}

//*****************************************************************************
/// RoomTree Destructor
//*****************************************************************************
RoomTree::~RoomTree()
{
   DeleteTree(root);
   root = nullptr;
   currNode = nullptr;
}

//*****************************************************************************
/// Helper function to assist in deleting the tree
//*****************************************************************************
void RoomTree::DeleteTree(Node* tempRoot)
{
   if(tempRoot) {
      DeleteTree(tempRoot->left);
      DeleteTree(tempRoot->center);
      DeleteTree(tempRoot->right);
      delete tempRoot;
   }
}

//*****************************************************************************
/// Inserts a new room at child (throws exeption if already occupied)
//*****************************************************************************
void RoomTree::NewRoom(char dir,Room* roomptr)
{
   dir = toupper(dir);

   switch(dir) {
      case 'L':
	 if(currNode->left)
	    throw invalid_argument("room occupied");
	 currNode->left = new Node;
	 currNode->left->parent = currNode;
	 currNode->left->room = roomptr;
	 break;
      case 'R':
	 if(currNode->right)
	    throw invalid_argument("room occupied");
	 currNode->right = new Node;
	 currNode->right->parent = currNode;
	 currNode->right->room = roomptr;
	 break;
      case 'C':
	 if(currNode->center)
	    throw invalid_argument("room occupied");
	 currNode->center = new Node;
	 currNode->center->parent = currNode;
	 currNode->center->room = roomptr;
	 break;
      case 'P':
	 if(currNode->parent)
	    throw invalid_argument("room occupied");
	 currNode->parent = new Node;
	 currNode->parent->parent = currNode;
	 currNode->parent->room = roomptr;
	 break;
      default:
	 throw invalid_argument("invalid direction");
   }
}

//*****************************************************************************
/// Moves current position through the tree
//*****************************************************************************
bool RoomTree::Move(char dir)
{
   dir = toupper(dir);

   switch(dir) {
      case 'L':
	 if(!(currNode->left))
	    return false;
	 currNode = currNode->left;
	 break;
      case 'R':
	 if(!(currNode->right))
	    return false;
	 currNode = currNode->right;
	 break;
      case 'C':
	 if(!(currNode->center))
	    return false;
	 currNode = currNode->center;
	 break;
      case 'P':
	 if(!(currNode->parent))
	    return false;
	 currNode = currNode->parent;
	 break;
      default:
	 throw invalid_argument("invalid direction");
   }
   return true;
}

//*****************************************************************************
/// Gives a const pointer to the room currently at for accessing
//*****************************************************************************
const Room* RoomTree::At() const
{
   return currNode->room;
}

//*****************************************************************************
/// Gives a pointer to the room currently at
//*****************************************************************************
Room* RoomTree::At()
{
   return currNode->room;
}

//*****************************************************************************
/// Gives the height of the tree at the current node
//*****************************************************************************
unsigned int RoomTree::CurrentHeight() const
{
   if(!currNode)
      return 0;
   Node *findNode = currNode;
   unsigned int i;
   for(i = 1; findNode != root; ++i)
      findNode = findNode->parent;
   return i;
}
