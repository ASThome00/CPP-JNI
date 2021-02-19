/*
 * Oviparous.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Oviparous.h"

//Default constructor
Oviparous::Oviparous(){
	subType = "";
	type = "Oviparous";
	numberOfEggs = 0;
}

//Prefered Constructor
Oviparous::Oviparous(int eggs){
	subType = "";
	type = "Oviparous";
	numberOfEggs = eggs;
}

//getter for type
string Oviparous::getType(){
	return "Oviparous";
}

//getter for subType
string Oviparous::getSubType(){
	return subType;
}

//getter for numberOfEggs
int Oviparous::getNumberOfEggs(){
	return numberOfEggs;
}

//Handles displaying in a table-friendly format
void Oviparous::display(){
	cout << right << setfill('0') << setw(6) << trackNumber;
	cout << left << setfill(' ') << setw(10) << "" << setw(16) << name << setw(16) << type << setw(16)
			<< subType << setw(10) << numberOfEggs << setw(10) << "0" << endl;
}
