/*
 * network.h
 *
 *  Created on: 2013.06.23.
 *      Author: quiga
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include <memory>
#include <iostream>
#include <vector>
//#include "../client/gameModel.h"

using namespace sf;

namespace AstrOWar {

class gameModel;

class network{
public:

	static network& getSingleton();

	void startAsServer(unsigned short port);
	void startAsClient(std::string address, unsigned short port);

	bool isEnableConnection(){return mSocketConnected;}

	void sendMessage(std::string msg);
	void registerMessageEventHandler(void (*cb)(std::string));
	bool isServer();

private:
	network();
	virtual ~network();
	void init();
	void run();

	void listenForClient();
	void connectToServer();
	std::string reciveMessage();

	std::shared_ptr<sf::Thread> mNetworkThread;

	bool mThreadShouldEnd;
	bool mSocketConnected;
	bool mShouldStartGame;
	bool _isServer;

	std::pair<std::string, unsigned short> mAddress;
	sf::TcpSocket mSocket;

	sf::Thread reciverThread;
	bool isListenReciver;

	void (*getMessage)(std::string);

};
extern network& NetworkSingleton;
} /* namespace AstrOWar */

#endif /* NETWORK_H_ */
