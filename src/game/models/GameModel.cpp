/*
 * GameModel.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "GameModel.h"

namespace AstrOWar {

GameModel::GameModel() :
		fireHandler(nullptr), hitHandler(nullptr), deadHandler(nullptr), exitHandler(
				nullptr), errorHandler(nullptr) {
	youtNext = false;
	pModel = new PhysicsModel(this);
	nModel = new NetworkModel(this);

}

GameModel::~GameModel() {
}

void GameModel::init(graphics *g) {
	gr = g;
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
	//INFO ellenfél kilépett
	if (exitHandler != nullptr)
		(gr->*exitHandler)();
}

void GameModel::messageEventHandlerOK(Message &m) {
	if (lista.count(m.getRefId()) > 0) {
		Message oldM = lista[m.getRefId()];
		lista.erase(m.getRefId());

		if (oldM.getMsgType() == IMDIED) {
			//INFO utasítások lekezelése
			if (deadHandler != nullptr) {
				(gr->*deadHandler)(true);
			}
		}
	}
}

void GameModel::messageEventHandlerBAD(Message &m) {
	if (lista.count(m.getRefId()) > 0) {
		Message oldM = lista[m.getRefId()];
		lista.erase(m.getRefId());
		//INFO utasítások elvetése
		if (errorHandler != nullptr)
			(gr->*errorHandler)(m.getMsgType());
	}
}
void GameModel::messageEventHandlerFIRE(Message &m) {
	//INFO	ő volt e soron
	if (!isYourNext()) {
		//INFO valid e az utasítás
		if (m.validate(pModel->getDimension())) {
			//INFO utasítás végrehajtása
			if (pModel->fire(m)) {
				//INFO eredmény alapján FIREOK
				sendMessageOnNetwork(
						Message().init(FIREOK, m.getId() + 1, m.getId()));
				pModel->check();
				if (hitHandler != nullptr)
					(gr->*hitHandler)(m.getPosX(), m.getPosY(), m.getPosZ(),
							true);
				if (pModel->idead()) {
					sendMessageOnNetwork(
							Message().init(IMDIED, m.getId() + 2, 0));
				}

			} else {
				//INFO eredmény alapján FIREBAD
				sendMessageOnNetwork(
						Message().init(FIREBAD, m.getId() + 1, m.getId()));
				if (hitHandler != nullptr)
					(gr->*hitHandler)(m.getPosX(), m.getPosY(), m.getPosZ(),
							false);
			}
			youtNext = true;
			return;
		}
	}
	//INFO eredmény alapján BAD
	sendMessageOnNetwork(Message().init(BAD, m.getId() + 1, m.getId()));
}
void GameModel::messageEventHandlerIMDIED(Message &m) {
	//INFO az ellenfél az összes hajóját elvesztette
	sendMessageOnNetwork(Message().init(OK, m.getId() + 1, m.getId()));
	if (deadHandler != nullptr) {
		(gr->*deadHandler)(false);
	}
}
void GameModel::messageEventHandlerFIREOK(Message &m) {
	//INFO találat, garfikai kijelzés
	if (lista.count(m.getRefId()) > 0) {
		Message oldM = lista[m.getRefId()];
		lista.erase(m.getRefId());

		if (oldM.getMsgType() == FIRE) {
			pModel->fire(m);
			youtNext = false;
			if (fireHandler != nullptr) {
				(gr->*fireHandler)(m.getPosX(), m.getPosY(), m.getPosZ(), true);
			}
		}
	}
}
void GameModel::messageEventHandlerFIREBAD(Message &m) {
	//INFO célt tévesztett, garfikai kijelzés
	if (lista.count(m.getRefId()) > 0) {
		Message oldM = lista[m.getRefId()];
		lista.erase(m.getRefId());

		if (oldM.getMsgType() == FIRE) {
			pModel->fire(m);
			youtNext = false;
			if (fireHandler != nullptr) {
				(gr->*fireHandler)(m.getPosX(), m.getPosY(), m.getPosZ(),
						false);
			}
		}
	}
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

void GameModel::startServer(unsigned short port) {
	youtNext = true;
	std::cout << "SZERVER indítása" << std::endl;
	nModel->startAsServer(port);
	while (!nModel->isEnableConnection()) {
		sf: sleep(sf::milliseconds(500));
	}
	std::cout << "SERVER: " << "Adat kuldese" << std::endl;
	sendMessageOnNetwork(Message().init(HELLO, 1, 0));
}

void GameModel::startClient(std::string address, unsigned short port) {
	youtNext = false;
	std::cout << "KLIENS indítása" << std::endl;
	nModel->startAsClient(address, port);
}

void GameModel::registerFireEventHandler(
		void (graphics::*fire)(int, int, int, bool)) {
	fireHandler = fire;
}
void GameModel::registerHitEventHandler(
		void (graphics::*hit)(int, int, int, bool)) {
	hitHandler = hit;
}
void GameModel::registerDeadEventHandler(void (graphics::*dead)(bool)) {
	deadHandler = dead;
}
void GameModel::registerExitEventHandler(void (graphics::*exit)()) {
	exitHandler = exit;
}
void GameModel::registerErrorEventHandler(void (graphics::*error)(int)) {
	errorHandler = error;
}

bool GameModel::isYourNext() {
	return youtNext;
}
;

GameModel& GameModel::getSingleton() {
	static GameModel instance;
	return instance;
}

GameModel& GameModelSingleton = GameModel::getSingleton();

} /* namespace AstrOWar */
