//
// HanoiTest.h
//
/// \author Tyler Siwy
/// \date Nov 9, 2017
//

#ifndef HANOI_TEST_H
#define HANOI_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Hanoi.h"

class HanoiTest : public CppUnit::TestFixure
{
CPPUNIT_TEST_SUITE(HanoiTest);
CPPUNIT_TEST_SUITE_END();

public:
void SetUp();
void TestRunGame();

Hanoi Game;

std::vector<int>::size_type indx;
};
