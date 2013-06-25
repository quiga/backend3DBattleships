/*
 * battleshipTeszt.cpp
 *
 *  Created on: 2013.06.24.
 *      Author: quiga
 */

#include "battleshipTeszt.h"

battleshipTeszt::battleshipTeszt(bool isServer, const unsigned short port,
		std::string address) :
		server(isServer), port(port), address(address), mThread(
				&battleshipTeszt::Client, this) {
	AstrOWar::GameModelSingleton.init();
}

battleshipTeszt::battleshipTeszt(bool isServer, const unsigned short port) :
		server(isServer), port(port), address(""), mThread(
				&battleshipTeszt::Server, this) {
	AstrOWar::GameModelSingleton.init();
}

battleshipTeszt::~battleshipTeszt() {
}

void battleshipTeszt::Server() {
	std::cout << "SZERVER indítása" << std::endl;
	AstrOWar::NetworkSingleton.startAsServer(port);
	while (!AstrOWar::NetworkSingleton.isEnableConnection()) {
		sf: sleep(sf::milliseconds(500));
	}
	std::cout << "SERVER: " << "Adat kuldese" << std::endl;
	AstrOWar::NetworkSingleton.sendMessage("SERVER_");
}

void battleshipTeszt::Client() {
	std::cout << "KLIENS indítása" << std::endl;
	AstrOWar::NetworkSingleton.startAsClient(address, port);
}

void battleshipTeszt::start() {
	mThread.launch();
}
