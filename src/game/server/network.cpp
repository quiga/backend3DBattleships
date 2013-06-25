/*
 * network.cpp
 *
 *  Created on: 2013.06.23.
 *      Author: quiga
 */

#include "network.h"

namespace AstrOWar {

network::network() :
		reciverThread(&network::run, this) {
	init();
}
network::~network() {
}

void network::init() {
	mShouldStartGame = false;
	mSocketConnected = false;
	mThreadShouldEnd = false;
}

void network::startAsServer(unsigned short port) {
	mNetworkThread.reset(new sf::Thread(&network::listenForClient, this));
	mAddress.second = port;
	mNetworkThread->launch();
}

void network::startAsClient(std::string address, unsigned short port) {
	mNetworkThread.reset(new sf::Thread(&network::connectToServer, this));
	mAddress.first = address;
	mAddress.second = port;
	mNetworkThread->launch();
}

void network::listenForClient() {
	std::cout << "SERVER: " << "Server starts on port " << mAddress.second << std::endl;
	sf::TcpListener listener;

	listener.setBlocking(false);
	listener.listen(mAddress.second);

	mThreadShouldEnd = false;
	while (!mThreadShouldEnd) {
		if (listener.accept(mSocket) == sf::Socket::Done) {
			std::cout << "SERVER: " << "Incoming client: " << mSocket.getRemoteAddress()
					<< std::endl;
			mShouldStartGame = true;
			mSocketConnected = true;
			mThreadShouldEnd = true;
		}
	}
	std::cout << "SERVER: " << "Server Listen Ended" << std::endl;
}

void network::connectToServer() {
	std::cout << "CLIENT: " << "Connenting to " << mAddress.first << " on port "
			<< mAddress.second << std::endl;

	mThreadShouldEnd = false;
	while (!mThreadShouldEnd) {
		sf::Socket::Status status = mSocket.connect(mAddress.first,
				mAddress.second);
		if (status == sf::Socket::Done) {
			std::cout << "CLIENT: " << "Connected to server: " << mSocket.getRemoteAddress()
					<< std::endl;
			mShouldStartGame = true;
			mSocketConnected = true;
			mThreadShouldEnd = true;
			isListenReciver = true;
			reciverThread.launch();
		}
	}
	std::cout << "Connenction Ended" << std::endl;
}

void network::sendMessage(std::string msg) {
	if (mSocketConnected) {
		sf::Packet packetSend;
		packetSend << msg;
		mSocket.send(packetSend);
	}
}

std::string network::reciveMessage() {
	/*
	while (mSocketConnected) {
		std::string msg;
		sf::Packet packetReceive;

		mSocket.receive(packetReceive);
		if (packetReceive >> msg) {
			if (oldMsg != msg)
				if (!msg.empty()) {
					oldMsg = msg;
					std::cout << msg << std::endl;
				}
		}
	}
	*/
	return "";
}

void network::run() {
	std::cout << "run start" << std::endl;

	static std::string oldMsg;
	while (isListenReciver) {
		std::string msg;
		sf::Packet packetReceive;

		mSocket.receive(packetReceive);

		if (packetReceive >> msg) {
			if (oldMsg != msg)
				if (!msg.empty()) {
					std::cout << msg << std::endl;
					oldMsg = msg;
				}
		}
	}
}

network& network::getSingleton() {
	static network instance;
	return instance;
}

network& NetworkSingleton = network::getSingleton();

} /* namespace AstrOWar */
