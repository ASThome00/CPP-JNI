/*
 * Whale.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Whale.h"

//Default constructor
Whale::Whale(){
	subType = "Whale";
}

//Prefered Constructor
Whale::Whale(int tempNurse):Mammal(tempNurse){
	subType = "Whale";
}
