/*
 * GameModel.h
 *
 *  Created on: 2013.06.22.
 *      Author: quiga
 */

#ifndef GAMEMODEL_H_
#define GAMEMODEL_H_
#include "PhysicsModel.h"
#include "NetworkModel.h"
#include "SFML/Network.hpp"
#include <vector>
#include "../elements/Ship.h"
#include "../elements/Message.h"
#include "../../tools/json/Parser.h"


using namespace std;

namespace AstrOWar {

class GameModel{
private:
	std::vector<AstrOWar::Ship> kollekcio;
	map<int, Message> lista;
	PhysicsModel *pModel;	// fizikai model
	NetworkModel *nModel;

protected:
	GameModel();
	virtual ~GameModel();

	void messageEventHandler(std::string encodedString);
	void messageEventHandlerHELLO(Message &m);
	void messageEventHandlerEXIT(Message &m);
	void messageEventHandlerOK(Message &m);
	void messageEventHandlerBAD(Message &m);
	void messageEventHandlerFIRE(Message &m);
	void messageEventHandlerIMDIED(Message &m);
	void messageEventHandlerFIREOK(Message &m);
	void messageEventHandlerFIREBAD(Message &m);

	void sendMessageOnNetwork(Message msg);

	void _fire(Message &m);

public:
	static GameModel& getSingleton();
	void init();
	void createTeszt();
	static void cbBad(int i);
	void (NetworkModel::*startServer)(unsigned short);
	void (NetworkModel::*startClient)(std::string, unsigned short);
	// hálózati model

	//TODO  grafikai interface
	//TODO setIP
	//TODO setPort
	//TODO startServer
	//TODO startClient
	//TODO registerHandler:
	//TODO *találat
	//TODO *lövés

};

extern GameModel& GameModelSingleton;

} /* namespace AstrOWar */
#endif /* GAMEMODEL_H_ */
