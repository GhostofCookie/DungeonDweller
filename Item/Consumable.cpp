//
// Consumable Implementation File
//
/// \author Rylan Bueckert
/// \date Nov 18, 2017
///

#include "Consumable.h"
#include <fstream>
#include <iostream>
using namespace std;

//*****************************************************************************
/// Generates adjetives to add to Consumable names
//*****************************************************************************
string Consumable::nameGenerator()
{
	static vector<string> consumableNames;
	static bool gotNames = false;

	// Generates the vector if it is first time
	if(!gotNames) {
		ifstream fin;
		fin.open("ConsumableNames.txt");
		string tempName;
		while(!fin.eof()) {
			getline(fin,tempName);
			consumableNames.push_back(tempName);
		}
		fin.close();
		if(consumableNames.size < 1)
			throw runtime_error("ConsumableNames.txt is empty");
		gotNames=true;
	}

	// Returns a random element of the vector
	return consumableNames[random(0,consumableNames.size()-1)]
}
