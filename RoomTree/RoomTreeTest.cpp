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
}

void RoomTreeTest::tearDown()
{
   delete Tree1;
   delete Tree2;
   delete Tree3;
   delete Tree4;
}

void RoomTreeTest::testMove()
{
   CPPUNIT_ASSERT(Tree1->Move('l'));
   CPPUNIT_ASSERT(!Tree1->Move('l'));
   CPPUNIT_ASSERT(!Tree1->Move('d'));
   CPPUNIT_ASSERT(!Tree1->Move('u'));
   CPPUNIT_ASSERT(Tree1->Move('r'));
   CPPUNIT_ASSERT(Tree1->Move('r'));
   CPPUNIT_ASSERT(!Tree1->Move('r'));
   CPPUNIT_ASSERT(Tree1->Move('l'));
   CPPUNIT_ASSERT_THROW(Tree1->Move('x'),invalid_argument);
}

void RoomTreeTest::testNewRoom()
{
   Tree2->NewRoom('r',nullptr);
   CPPUNIT_ASSERT_THROW(Tree2->NewRoom('r',nullptr),invalid_argument);
   CPPUNIT_ASSERT_THROW(Tree2->NewRoom('x',nullptr),invalid_argument);
}

void RoomTreeTest::testAt()
{
   CPPUNIT_ASSERT(Tree1->At() == nullptr);
}

void RoomTreeTest::testCurrentHeight()
{ 
   CPPUNIT_ASSERT(Tree1->CurrentHeight() == 1);
   CPPUNIT_ASSERT(Tree2->CurrentHeight() == 1);
   CPPUNIT_ASSERT(Tree3->CurrentHeight() == 6);
}

void RoomTreeTest::testTotalNodes()
{
   CPPUNIT_ASSERT(Tree1->TotalNodes() == 5);
   CPPUNIT_ASSERT(Tree3->TotalNodes() == 6);
}
