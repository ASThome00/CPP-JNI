/*
 * SeaLion.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "SeaLion.h"

//Default constructor
SeaLion::SeaLion(){
	subType = "SeaLion";
}

//Prefered Constructor
SeaLion::SeaLion(int tempNurse):Mammal(tempNurse){
	subType = "SeaLion";
}
