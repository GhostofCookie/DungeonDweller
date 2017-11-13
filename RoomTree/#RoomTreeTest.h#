#ifndef ROOMTREE_TEST_H
#define ROOMTREE_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "RoomTree.h"
#include <stdexcept>

/// Class that tests functionality of RoomTree Class
class RoomTreeTest : public CppUnit::TestFixture
{
   /// test suite macros
   CPPUNIT_TEST_SUITE(RoomTreeTest);
   CPPUNIT_TEST(testMove);
   CPPUNIT_TEST(testNewRoom);
   CPPUNIT_TEST(testAt);
   CPPUNIT_TEST_SUITE_END();

  public:
   /// Sets up tests for RoomTree
   void setUp();

   /// Tests the move Function
   void testMove();

   /// Tests the newRoom Function
   void testNewRoom();

   /// Tests the at Function
   void testAt();

  private:
   RoomTree Tree1,Tree2,Tree3;

};
#endif
