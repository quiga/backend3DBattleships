/*
 * gameModel.cpp
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#include "gameModel.h"

namespace AstrOWar {

//TODO  közös ősosztály mindennek, akkor müxik a function pointer

gameModel::gameModel() {
	mSocket = nullptr;
}

gameModel::~gameModel() {
}

void gameModel::init() {
	JSON::JSONSingleton.parse("config/astrowar.json", &kollekcio);
	//NetworkSingleton.registerMessageEventHandler(&gameModel::messageEventHandler);
}

void gameModel::cbBad(int i) {
	cout << "hiba: " << i << endl;
}

/*
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

//void gameModel::messageEventHandler(){}

void gameModel::sendMessageOnNetwork(message msg){
	lista[msg.getId()] = msg;
	NetworkSingleton.sendMessage(JSON::JSONSingleton.encode(msg));
}

void gameModel::messageEventHandlerHELLO(message &m) {
	if(!NetworkSingleton.isServer()){
		sendMessageOnNetwork( message().init( 1, m.getId()+1, m.getId()) );
	}
}
void gameModel::messageEventHandlerEXIT(message &m) {
	//TODO ellenfél kilépett
}

//		switch(oldM.getMsgType()){
//			/* FIRE */ case 4 : break;
//			/**/ case 5 : break;
//		}


void gameModel::messageEventHandlerOK(message &m) {
	if(lista.count(m.getRefId()) > 0){
		message oldM = lista[m.getRefId()];
		lista.erase(m.getRefId());

		if(oldM.getMsgType() == 5){
			//TODO utasítások lekezelése
		}
	}
}
void gameModel::messageEventHandlerBAD(message &m) {
	if(lista.count(m.getRefId()) > 0){
			lista.erase(m.getRefId());
			//TODO utasítások elvetése
		}
}
void gameModel::messageEventHandlerFIRE(message &m) {
	//TODO	ő volt e soron
	//TODO valid e az utasítás
	//TODO utasítás végrehajtása
	//TODO eredmény alapján FIREOK v. FIREBAD
}
void gameModel::messageEventHandlerIMDIED(message &m) {
	//TODO az ellenfél az összes hajóját elvesztette
}
void gameModel::messageEventHandlerFIREOK(message &m) {
	//TODO találat, garfikai kijelzés
}
void gameModel::messageEventHandlerFIREBAD(message &m) {
	//TODO célt tévesztett, garfikai kijelzés
}

void gameModel::messageEventHandler(std::string encodedString) {
	message m = JSON::JSONSingleton.decode(encodedString);
	if (m.validate()) {
		switch(m.getMsgType()){
			case 1 : messageEventHandlerHELLO(m); break;
			case 2 : messageEventHandlerOK(m); break;
			case 3 : messageEventHandlerBAD(m); break;
			case 4 : messageEventHandlerFIRE(m); break;
			case 5 : messageEventHandlerIMDIED(m); break;
			case 6 : messageEventHandlerFIREOK(m); break;
			case 7 : messageEventHandlerFIREBAD(m); break;
			case 8 : messageEventHandlerEXIT(m); break;
		}
	}
}

gameModel& gameModel::getSingleton() {
	static gameModel instance;
	return instance;
}

gameModel& GameModelSingleton = gameModel::getSingleton();

} /* namespace AstrOWar */
