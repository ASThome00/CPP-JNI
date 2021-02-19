/*
 * Mammal.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

class Mammal: public Animal {
	private:
		int nurse;
	public:
		string subType;
		Mammal();
		Mammal(int tempNurse);
		string getType();
		string getSubType();
		int getNurse();
		void display();
};
#endif /* MAMMAL_H_ */

