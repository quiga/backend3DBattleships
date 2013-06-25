/*
 * gameModel.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "gameModel.h"

namespace AstrOWar {

gameModel::gameModel() {
	mSocket = nullptr;
}

gameModel::~gameModel() {
}

void gameModel::init() {
	JSON::JSONSingleton.parse("config/astrowar.json", &kollekcio);
}

void gameModel::cbBad(int i) {
	cout << "hiba: " << i << endl;
}

/**
 *  n = 10
 *	add Fighter, Destroyer, Battleship, Carrier to physicsModel
 */
void gameModel::createTeszt() {
	pModel.init(10);
	pModel.addShip(kollekcio[0].clone(), 0, 3, 0, &gameModel::cbBad);
	pModel.addShip(kollekcio[1].clone(), 1, 6, 0, &gameModel::cbBad);
	pModel.addShip(kollekcio[3].clone(), 2, 0, 0, &gameModel::cbBad);
	pModel.addShip(kollekcio[5].clone(), 3, 0, 0, &gameModel::cbBad);
	pModel.toString();
}

gameModel& gameModel::getSingleton() {
	static gameModel instance;
	return instance;
}

gameModel& GameModelSingleton = gameModel::getSingleton();

} /* namespace AstrOWar */
