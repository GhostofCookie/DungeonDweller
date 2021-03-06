/** @author Rylan Bueckert
 * @date Nov 10, 2017
 */

#include "RoomTree.h"
#include <stdexcept>
#include <cctype>


RoomTree::Node::Node()
{
	left = nullptr;
	right = nullptr;
	down = nullptr;
	up = nullptr;
	RootDir = '\0';
}

RoomTree::RoomTree(Room* rootRoom)
{
	root = new Node;
	root->room = rootRoom;
	currNode = root;
}

RoomTree::~RoomTree()
{
	DeleteTree(root);
	currNode = nullptr;
}

void RoomTree::DeleteTree(Node* tempRoot)
{
	if (tempRoot) //if this node exists
	{
		if ('U' != tempRoot->RootDir) //delete up child if its not the parent node
			DeleteTree(tempRoot->up);

		if ('L' != tempRoot->RootDir) //delete left child if its not the parent node
			DeleteTree(tempRoot->left);

		if ('R' != tempRoot->RootDir) //delete right child if its not the parent node
			DeleteTree(tempRoot->right);

		if ('D' != tempRoot->RootDir) //delete down child if its not the parent node
			DeleteTree(tempRoot->down);

		delete tempRoot->room; //delete the room
		tempRoot->room = nullptr;
		delete tempRoot; //delete this node
		tempRoot = nullptr;
	}
}

void RoomTree::NewRoom(char dir, Room* roomptr)
{
	dir = toupper(dir);

	switch (dir)
	{
	case 'U':
		if (currNode->up)
			throw std::invalid_argument("room occupied");
		currNode->up = new Node;
		currNode->up->down = currNode;
		currNode->up->room = roomptr;
		currNode->up->RootDir = 'D';
		break;

	case 'L':
		if (currNode->left)
			throw std::invalid_argument("room occupied");
		currNode->left = new Node;
		currNode->left->right = currNode;
		currNode->left->room = roomptr;
		currNode->left->RootDir = 'R';
		break;

	case 'R':
		if (currNode->right)
			throw std::invalid_argument("room occupied");
		currNode->right = new Node;
		currNode->right->left = currNode;
		currNode->right->room = roomptr;
		currNode->right->RootDir = 'L';
		break;

	case 'D':
		if (currNode->down)
			throw std::invalid_argument("room occupied");
		currNode->down = new Node;
		currNode->down->up = currNode;
		currNode->down->room = roomptr;
		currNode->down->RootDir = 'U';
		break;

	default:
		throw std::invalid_argument("invalid direction");
	}
}

bool RoomTree::Move(char dir)
{
	dir = toupper(dir);

	switch (dir)
	{
	case 'L':
		if (!(currNode->left))
			return false;
		currNode = currNode->left;
		break;
	case 'R':
		if (!(currNode->right))
			return false;
		currNode = currNode->right;
		break;
	case 'D':
		if (!(currNode->down))
			return false;
		currNode = currNode->down;
		break;
	case 'U':
		if (!(currNode->up))
			return false;
		currNode = currNode->up;
		break;
	default:
		throw std::invalid_argument("invalid direction");
	}
	return true;
}

Room const* RoomTree::At() const
{
	return currNode->room;
}

Room* RoomTree::At()
{
	return currNode->room;
}

unsigned int RoomTree::CurrentHeight() const
{
	if (!currNode)
		return 0;
	Node* findNode = currNode;
	unsigned int i;

	for (i = 1; findNode->RootDir != '\0'; ++i)
		switch (findNode->RootDir)
		{
		case 'U':
			findNode = findNode->up;
			break;

		case 'L':
			findNode = findNode->left;
			break;

		case 'R':
			findNode = findNode->right;
			break;

		case 'D':
			findNode = findNode->down;
			break;
		}
	return i;
}

unsigned int RoomTree::TotalNodes() const
{
	return NodesInBranch(root);
}

unsigned int RoomTree::NodesInBranch(Node* tempRoot) const
{
	if (tempRoot)
	{
		switch (tempRoot->RootDir)
		{
		case '\0':
			return NodesInBranch(tempRoot->left)
				+ NodesInBranch(tempRoot->down)
				+ NodesInBranch(tempRoot->right)
				+ NodesInBranch(tempRoot->up) + 1;
		case 'U':
			return NodesInBranch(tempRoot->left)
				+ NodesInBranch(tempRoot->down)
				+ NodesInBranch(tempRoot->right) + 1;
			break;
		case 'L':
			return NodesInBranch(tempRoot->up)
				+ NodesInBranch(tempRoot->down)
				+ NodesInBranch(tempRoot->right) + 1;
			break;
		case 'R':
			return NodesInBranch(tempRoot->left)
				+ NodesInBranch(tempRoot->down)
				+ NodesInBranch(tempRoot->up) + 1;
			break;
		case 'D':
			return NodesInBranch(tempRoot->left)
				+ NodesInBranch(tempRoot->up)
				+ NodesInBranch(tempRoot->right) + 1;
			break;
		default:
			break;
		}
	}

	return 0;
}
