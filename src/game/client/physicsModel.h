/*
 * physicsModel.h
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#ifndef PHYSICSMODEL_H_
#define PHYSICSMODEL_H_
#include <vector>
#include "field.h"

#include <iostream>
using namespace std;

namespace AstrOWar {

class physicsModel {
protected:
	std::vector<std::vector<std::vector<field*> > > cubeMy;
	std::vector<std::vector<std::vector<field*> > > cubeFoe;
	std::vector<Ship*> myShips;

public:
	physicsModel();
	virtual ~physicsModel();
	void init(int n);
	void addShip(Ship* s, int _x, int _y, int _z, void (*callbackBad)(int));
	void addBomb(int _x, int _y, int _z, void (*callbackBad)(int));
	void toString();
};

} /* namespace AstrOWar */
#endif /* PHYSICSMODEL_H_ */
