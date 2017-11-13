#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "RoomTree.h"
#include "RoomTreeTest.h"
#include <stdexcept>

void RoomTreeTest::setUp()
{
	Tree1 = new RoomTree(nullptr);
	Tree2 = new RoomTree(nullptr);
	Tree3 = new RoomTree(nullptr);
	Tree1->newRoom('l',nullptr);
	Tree1->newRoom('c',nullptr);
	Tree1->newRoom('r',nullptr);
}


void RoomTreeTest::testMove()
{
	CPPUNIT_ASSERT(Tree1->move('l'));
	CPPUNIT_ASSERT(!Tree1->move('l'));
	CPPUNIT_ASSERT(!Tree1->move('r'));
	CPPUNIT_ASSERT(!Tree1->move('c'));
	CPPUNIT_ASSERT(Tree1->move('p'));
	CPPUNIT_ASSERT(!Tree1->move('p'));
	CPPUNIT_ASSERT(Tree1->move('r'));
	CPPUNIT_ASSERT(Tree1->move('p'));
}

void RoomTreeTest::testNewRoom()
{
	CPPUNIT_ASSERT_THROW(Tree1->newRoom('r',nullptr),invalid_argument)
}

void RoomTreeTest::testAt()
{

}
