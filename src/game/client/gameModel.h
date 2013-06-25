/*
 * gameModel.h
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_
#include "physicsModel.h"
#include "SFML/Network.hpp"
#include "../../tools/json/Parser.h"
#include <vector>
#include "Ship.h"
#include "../server/message.h"
#include "../server/network.h"

using namespace std;

namespace AstrOWar {

class gameModel {
private:
	std::vector<AstrOWar::Ship> kollekcio;
	map<int, message> lista;
	physicsModel pModel;	// fizikai model
	sf::TcpSocket *mSocket;

protected:
	gameModel();
	virtual ~gameModel();

	void messageEventHandler(std::string encodedString);
	void messageEventHandlerHELLO(message &m);
	void messageEventHandlerEXIT(message &m);
	void messageEventHandlerOK(message &m);
	void messageEventHandlerBAD(message &m);
	void messageEventHandlerFIRE(message &m);
	void messageEventHandlerIMDIED(message &m);
	void messageEventHandlerFIREOK(message &m);
	void messageEventHandlerFIREBAD(message &m);

	void sendMessageOnNetwork(message msg);

public:
	static gameModel& getSingleton();
	void init();
	void createTeszt();
	static void cbBad(int i);
	// hálózati model

	// grafikai interface


};

extern gameModel& GameModelSingleton;

} /* namespace AstrOWar */
#endif /* GAMEMODEL_H_ */
