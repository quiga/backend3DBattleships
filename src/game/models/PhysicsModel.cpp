/*
 * PhysicsModel.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "PhysicsModel.h"
using namespace std;

namespace AstrOWar {

PhysicsModel::PhysicsModel(GameModel *g) : gm(g) {
}

PhysicsModel::~PhysicsModel() {
	destroy();
}

/**
 *  kocka bal,alsó,elülső sarka a (0,0,0) pont
 */
void PhysicsModel::init(int n) {
	destroy();
	cubeMy.resize(n);
	cubeFoe.resize(n);
	for (int i = 0; i < n; i++) {
		cubeMy[i].resize(n);
		cubeFoe[i].resize(n);
		for (int j = 0; j < n; j++) {
			cubeMy[i][j].resize(n);
			cubeFoe[i][j].resize(n);
			for (int k = 0; k < n; k++) {
				cubeMy[i][j][k] = new Field(i, j, k);
				cubeFoe[i][j][k] = new Field(i, j, k);
			}
		}
	}
}

void PhysicsModel::destroy(){
	for(auto x : cubeFoe){
		for(auto y : x){
			for(auto z : y)
				delete z;
		}
	}
	for(auto x : cubeMy){
		for(auto y : x){
			for(auto z : y)
				delete z;
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
void PhysicsModel::addShip(Ship *s, int x, int y, int z,
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

void PhysicsModel::addBomb(int _x, int _y, int _z, void (*callbackBad)(int)) {
	cubeFoe[_x][_y][_z]->setDisruptive(true);
}

size_t PhysicsModel::getDimension() {
	return cubeMy.size();
}

bool PhysicsModel::fire(Message &m) {
	//INFO ha 4es akkor rám lőttek
	if (m.getMsgType() == FIRE) {
		return cubeMy[m.getPosX()][m.getPosY()][m.getPosZ()]->fire();
	}
	//INFO ha 6os v. 7es akkor én lőttem
	else if (m.getMsgType() == FIREOK || m.getMsgType() == FIREBAD) {
		//addBomb();
	}
	return true;	//TODO csak ideiglenes
}

void PhysicsModel::toString() {

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
