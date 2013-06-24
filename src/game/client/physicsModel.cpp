/*
 * physicsModel.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "physicsModel.h"
using namespace std;

namespace AstrOWar {

physicsModel::physicsModel() {
}

physicsModel::~physicsModel() {
}

/**
 *  kocka bal,alsó,elülső sarka a (0,0,0) pont
 */
void physicsModel::init(int n) {
	cubeMy.resize(n);
	cubeFoe.resize(n);
	for (int i = 0; i < n; i++) {
		cubeMy[i].resize(n);
		cubeFoe[i].resize(n);
		for (int j = 0; j < n; j++) {
			cubeMy[i][j].resize(n);
			cubeFoe[i][j].resize(n);
			for (int k = 0; k < n; k++) {
				cubeMy[i][j][k] = new field(i, j, k);
				cubeFoe[i][j][k] = new field(i, j, k);
			}
		}
	}
}

/**
 * hajó hozzáadása a modelhez
 * paraméterek:
 * 		Ship - hajó objektumra mutat
 * 		x, y, z - pozíció, hova kerüljön
 * 		callbackBad - függvénymutató, hiba esetén ez hívódik int paraméterrel,
 * 					  mely tartalmazza a hiba kódját
 */
void physicsModel::addShip(Ship *s, int x, int y, int z,
		void (*callbackBad)(int)) {
	if (!s->isNew()) {
		callbackBad(1);
		return;
	}
	myShips.push_back(s);
	vector<vector<int> > structure = s->getStructure();
	for (int i = 0; i < structure.size(); i++) {
		for (int j = 0; j < structure[i].size(); j++) {
			for (int k = 0; k < structure[i][j]; k++) {
				if ((x + i >= cubeMy.size()) || (y + k >= cubeMy[x + i].size())
						|| (z + j >= cubeMy[x + i][y + k].size())) {
					callbackBad(2);
					return;
				}
				cubeMy[x + i][y + k][z + j]->setShip(s);
				s->addField(cubeMy[x + i][y + k][z + j]);
			}
		}
	}
}

void physicsModel::addBomb(int _x, int _y, int _z, void (*callbackBad)(int)){
	cubeFoe[_x][_y][_z]->setDisruptive(true);
}

void physicsModel::toString() {

	for (int i = 0; i < cubeMy.size(); i++) {
		for (int j = 0; j < cubeMy[i].size(); j++) {
			for (int k = 0; k < cubeMy[i][j].size(); k++) {
				cout << cubeMy[i][j][k]->toString() << " ";
			}
			cout << endl;
		}
		cout << "************************************************" << endl;
	}

}

} /* namespace AstrOWar */
