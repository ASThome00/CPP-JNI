/*
 * Mammal.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Mammal.h"

//Default constructor
Mammal::Mammal(){
	subType = "";
	type = "Mammal";
	nurse = 0;
}

//Prefered Constructor
Mammal::Mammal(int tempNurse){
	subType = "";
	type = "Mammal";
	nurse = tempNurse;
}

//getter for type
string Mammal::getType(){
	return type;
}

//getter for subType
string Mammal::getSubType(){
	return subType;
}

//getter for nurse
int Mammal::getNurse(){
	return nurse;
}

//handles displaying in a table-friendly format
void Mammal::display(){
	cout << right << setfill('0') << setw(6) << trackNumber;
	cout << left << setfill(' ') << setw(10) << "" << setw(16) << name << setw(16) << type << setw(16)
				<< subType << setw(10) << "0" << setw(10) << nurse << endl;
}
