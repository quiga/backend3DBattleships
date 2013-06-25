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
using namespace std;

namespace AstrOWar {

class gameModel {
private:
	std::vector<AstrOWar::Ship> kollekcio;
protected:
	gameModel();
	virtual ~gameModel();

public:
	static gameModel& getSingleton();
	void init();
	void createTeszt();
	static void cbBad(int i);
	// hálózati model

	// grafikai interface

	// fizikai model
	physicsModel pModel;
	sf::TcpSocket *mSocket;
};

extern gameModel& GameModelSingleton;

} /* namespace AstrOWar */
#endif /* GAMEMODEL_H_ */
