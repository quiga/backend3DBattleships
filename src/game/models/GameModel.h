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

class graphics;
// csak egy mintaosztály, nem létezik

class GameModel {
private:
	std::vector<AstrOWar::Ship> kollekcio;// a hajók listája, mindegyikből 1 példány
	map<int, Message> lista;					// elküldött üzeneteket tárolja
	PhysicsModel *pModel;									// fizikai model
	NetworkModel *nModel;									// hálózati model

	void (graphics::*fireHandler)(int, int, int);	// lövés esetén értesítés
	void (graphics::*hitHandler)(int, int, int, bool);// találat esetén értesítés
	void (graphics::*deadHandler)(bool);			// halál esetén értesítés
	void (graphics::*exitHandler)();				// kilépés esetén értesítés
	void (graphics::*errorHandler)(int);	// hiba esetén értesítés, hibakóddal

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

	//INFO grafikai interface
	void startServer(unsigned short port);
	void startClient(std::string address, unsigned short port);

	void registerFireEventHandler(void (graphics::*fire)(int, int, int));
	void registerHitEventHandler(void (graphics::*hit)(int, int, int, bool));

	void registerDeadEventHandler(void (graphics::*dead)(bool));
	void registerExitEventHandler(void (graphics::*exit)());

	void registerErrorEventHandler(void (graphics::*error)(int));
};

extern GameModel& GameModelSingleton;

} /* namespace AstrOWar */
#endif /* GAMEMODEL_H_ */
