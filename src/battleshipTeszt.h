/*
 * battleshipTeszt.h
 *
 *  Created on: 2013.06.24.
 *      Author: quiga
 */

#ifndef BATTLESHIPTESZT_H_
#define BATTLESHIPTESZT_H_

#include "game/client/gameModel.h"
#include "game/server/network.h"

#include <iostream>

class battleshipTeszt {
	bool server;
	std::string address;
	unsigned short port;
	sf::Thread mThread;

	void Server();
	void Client();

public:
	battleshipTeszt(bool isServer, const unsigned short port, std::string address);
	battleshipTeszt(bool isServer, const unsigned short port);
	virtual ~battleshipTeszt();

	void start();
};

#endif /* BATTLESHIPTESZT_H_ */
