/*
 * Goose.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Goose.h"

//Default constructor
Goose::Goose(){
	subType = "Goose";
}

//Prefered Constructor
Goose::Goose(int tempEggs): Oviparous(tempEggs){
	subType = "Goose";
}
