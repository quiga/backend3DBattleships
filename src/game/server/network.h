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

using namespace sf;

namespace AstrOWar {

class network{
public:

	void startAsServer(unsigned short port);
	void startAsClient(std::string address, unsigned short port);
	static network& getSingleton();
	bool isEnableConnection(){return mSocketConnected;}

	void sendMessage(std::string msg);
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

	std::vector<std::string> messageList;
	sf::Mutex mutex;

	std::pair<std::string, unsigned short> mAddress;
	sf::TcpSocket mSocket;
	std::string oldMsg;

	sf::Thread reciverThread;
	bool isListenReciver;

};
extern network& NetworkSingleton;
} /* namespace AstrOWar */

#endif /* NETWORK_H_ */
