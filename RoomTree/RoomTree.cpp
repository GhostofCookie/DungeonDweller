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

RoomTree::RoomTree(Room* roomptr)
{
	root = new Node;
	root -> room = roomptr;
}

RoomTree::~RoomTree()
{
	deleteTree(root);
	root = nullptr;
	currNode = nullptr;
}

void RoomTree::deleteTree(Node* tempRoot)
{
	if(tempRoot) {
		deleteTree(tempRoot->left);
		deleteTree(tempRoot->center);
		deleteTree(tempRoot->right);
		delete tempRoot;
	}
}

void RoomTree::newRoom(char dir,Room* roomptr)
{

	dir = toupper(dir);

	switch(dir) {
		case 'L':
			if(currNode -> left)
				throw invalid_argument("room occupied");
			currNode -> left = roomptr;
			break;
		case 'R':
			if(currNode -> right)
				throw invalid_argument("room occupied");
			currNode -> right = roomptr;
			break;
		case 'C':
			if(currNode -> center)
				throw invalid_argument("room occupied");
			currNode -> center = roomptr;
			break;
		default:
			throw invalid_argument("invalid direction");
	}
}