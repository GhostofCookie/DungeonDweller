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
	CPPUNIT_ASSERT_THROW(Tree1->move('x'),invalid_argument);
}

void RoomTreeTest::testNewRoom()
{
   Tree2->newRoom('r',nullptr);
   CPPUNIT_ASSERT_THROW(Tree1->newRoom('r',nullptr),invalid_argument);
   CPPUNIT_ASSERT_THROW(Tree1->newRoom('x',nullptr),invalid_argument);
}

void RoomTreeTest::testAt()
{

}
