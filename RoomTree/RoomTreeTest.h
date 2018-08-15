/// RoomTreeTest.h
///
/// \author Rylan Bueckart
/// \date 8/11/2017
///

#pragma once

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
   CPPUNIT_TEST(testCurrentHeight);
   CPPUNIT_TEST(testTotalNodes);
   CPPUNIT_TEST_SUITE_END();

  public:
   /// Sets up tests for RoomTree
   void setUp();

   /// Cleans up tests
   void tearDown();

   /// Tests the move Function
   void testMove();

   /// Tests the newRoom Function
   void testNewRoom();

   /// Tests the at Function
   void testAt();

   /// Tests the CurrentHeight function
   void testCurrentHeight();

   /// Tests the TotalNodes function
   void testTotalNodes();

  private:
	  RoomTree *Tree1;
	  RoomTree *Tree2;
	  RoomTree *Tree3;
	  RoomTree *Tree4;

};
