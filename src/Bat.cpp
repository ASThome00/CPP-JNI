/*
 * Bat.cpp
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#include "Bat.h"

//Default constructor
Bat::Bat(){
	subType = "Bat";
}

//Prefered Constructor
Bat::Bat(int tempNurse): Mammal(tempNurse){
	subType = "Bat";
}
