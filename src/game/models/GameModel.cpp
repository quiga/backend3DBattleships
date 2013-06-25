/*
 * GameModel.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "GameModel.h"

namespace AstrOWar {

GameModel::GameModel() {
	pModel = new PhysicsModel(this);
	nModel = new NetworkModel(this);

	startClient = &NetworkModel::startAsClient;
	startServer = &NetworkModel::startAsServer;
}

GameModel::~GameModel() {
}

void GameModel::init() {
	JSON::JSONSingleton.parse("config/astrowar.json", &kollekcio);
	nModel->registerMessageEventHandler(&GameModel::messageEventHandler);
}

void GameModel::cbBad(int i) {
	cout << "hiba: " << i << endl;
}

/*
 *  n = 10
 *	add Fighter, Destroyer, Battleship, Carrier to physicsModel
 */
void GameModel::createTeszt() {
	pModel->init(10);
	pModel->addShip(kollekcio[0].clone(), 0, 3, 0, &GameModel::cbBad);
	pModel->addShip(kollekcio[1].clone(), 1, 6, 0, &GameModel::cbBad);
	pModel->addShip(kollekcio[3].clone(), 2, 0, 0, &GameModel::cbBad);
	pModel->addShip(kollekcio[5].clone(), 3, 0, 0, &GameModel::cbBad);
	pModel->toString();
}

void GameModel::sendMessageOnNetwork(Message msg) {
	lista[msg.getId()] = msg;
	nModel->sendMessage(JSON::JSONSingleton.encode(msg));
}

void GameModel::messageEventHandlerHELLO(Message &m) {
	if (!nModel->isServer()) {
		sendMessageOnNetwork(Message().init(HELLO, m.getId() + 1, m.getId()));
	}
}
void GameModel::messageEventHandlerEXIT(Message &m) {
	//TODO ellenfél kilépett
}

void GameModel::messageEventHandlerOK(Message &m) {
	if (lista.count(m.getRefId()) > 0) {
		Message oldM = lista[m.getRefId()];
		lista.erase(m.getRefId());

		if (oldM.getMsgType() == IMDIED) {
			//TODO utasítások lekezelése
		}
	}
}
void GameModel::messageEventHandlerBAD(Message &m) {
	if (lista.count(m.getRefId()) > 0) {
		lista.erase(m.getRefId());
		//INFO utasítások elvetése
	}
}
void GameModel::messageEventHandlerFIRE(Message &m) {
	//TODO	ő volt e soron

	//INFO valid e az utasítás
	if (m.validate(pModel->getDimension())) {
		//INFO utasítás végrehajtása
		pModel->fire(m);
		//INFO eredmény alapján FIREOK
		sendMessageOnNetwork(Message().init(FIREOK, m.getId() + 1, m.getId()));
		return;
	}
	//INFO eredmény alapján FIREBAD
	sendMessageOnNetwork(Message().init(FIREBAD, m.getId() + 1, m.getId()));
}
void GameModel::messageEventHandlerIMDIED(Message &m) {
	//TODO az ellenfél az összes hajóját elvesztette
	sendMessageOnNetwork(Message().init(OK, m.getId() + 1, m.getId()));
}
void GameModel::messageEventHandlerFIREOK(Message &m) {
	//TODO találat, garfikai kijelzés
	pModel->fire(m);
}
void GameModel::messageEventHandlerFIREBAD(Message &m) {
	//TODO célt tévesztett, garfikai kijelzés
	pModel->fire(m);
}

void GameModel::messageEventHandler(std::string encodedString) {
	Message m = JSON::JSONSingleton.decode(encodedString);
	if (m.validate()) {
		switch (m.getMsgType()) {
		case HELLO:
			messageEventHandlerHELLO(m);
			break;
		case OK:
			messageEventHandlerOK(m);
			break;
		case BAD:
			messageEventHandlerBAD(m);
			break;
		case FIRE:
			messageEventHandlerFIRE(m);
			break;
		case IMDIED:
			messageEventHandlerIMDIED(m);
			break;
		case FIREOK:
			messageEventHandlerFIREOK(m);
			break;
		case FIREBAD:
			messageEventHandlerFIREBAD(m);
			break;
		case EXIT:
			messageEventHandlerEXIT(m);
			break;
		}
	}
}

GameModel& GameModel::getSingleton() {
	static GameModel instance;
	return instance;
}

GameModel& GameModelSingleton = GameModel::getSingleton();

} /* namespace AstrOWar */
