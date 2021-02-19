/*
 * Oviparous.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "Animal.h"

class Oviparous: public Animal {
	private:
		int numberOfEggs;
	public:
		string subType;
		Oviparous();
		Oviparous(int eggs);
		string getType();
		string getSubType();
		int getNumberOfEggs();
		void display();
};
#endif /* OVIPAROUS_H_ */

