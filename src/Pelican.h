/*
 * Pelican.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Andrew Tanner
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include "Oviparous.h"

class Pelican: public Oviparous {
	public:
		Pelican();
		Pelican(int tempEggs);
};
#endif /* PELICAN_H_ */

