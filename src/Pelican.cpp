/*
 * Pelican.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Pelican.h"

//Default constructor
Pelican::Pelican(){
	subType = "Pelican";
}

//Prefered Constructor
Pelican::Pelican(int tempEggs):Oviparous(tempEggs){
	subType = "Pelican";
}
