/*
 * Animal.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Animal {
public:
	string name;
	int trackNumber;
	string type;
	Animal(){};
	virtual string getSubType() {return "";}
	virtual void display() {};
};

#endif /* ANIMAL_H_ */
