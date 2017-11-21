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
	Tree1->newRoom('d',nullptr);
	Tree1->newRoom('r',nullptr);
	Tree1->newRoom('u',nullptr);
}

void RoomTreeTest::tearDown()
{
	delete Tree1;
	delete Tree2;
	delete Tree3;
}

void RoomTreeTest::testMove()
{
	CPPUNIT_ASSERT(Tree1->move('l'));
	CPPUNIT_ASSERT(!Tree1->move('l'));
	CPPUNIT_ASSERT(!Tree1->move('d'));
	CPPUNIT_ASSERT(!Tree1->move('u'));
	CPPUNIT_ASSERT(Tree1->move('r'));
	CPPUNIT_ASSERT(!Tree1->move('r'));
	CPPUNIT_ASSERT(Tree1->move('d'));
	CPPUNIT_ASSERT(Tree1->move('u'));
	CPPUNIT_ASSERT_THROW(Tree1->move('x'),invalid_argument);
}

void RoomTreeTest::testNewRoom()
{
   Tree2->newRoom('r',nullptr);
   CPPUNIT_ASSERT_THROW(Tree2->newRoom('r',nullptr),invalid_argument);
   CPPUNIT_ASSERT_THROW(Tree2->newRoom('x',nullptr),invalid_argument);
}

void RoomTreeTest::testAt()
{
	CPPUNIT_ASSERT(Tree1->At() == nullptr);
}
