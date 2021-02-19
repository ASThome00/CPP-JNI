/*
 * Crocodile.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Crocodile.h"

//Default constructor
Crocodile::Crocodile(){
	subType = "Crocodile";
}

//Prefered Constructor
Crocodile::Crocodile(int tempEggs): Oviparous(tempEggs){
	subType = "Crocodile";
}
