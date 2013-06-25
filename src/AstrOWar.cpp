//============================================================================
// Name        : AstrOWar.cpp
// Author      : Lászlóffy Barnabás (lasba)
// Version     :
// Copyright   : I'm all right!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "game/models/GameModel.h"
#include "SFML/Network.hpp"
using namespace sf;
const unsigned short port = 50003;
const std::string address = "127.0.0.1";

#define SERVER true
#define CLIENT false

//#define selector true
#define selector false

int main(int argc, char* argv[]) {
	cout << "APP START" << endl;
	Thread game([]() {
		AstrOWar::GameModelSingleton.init();
		if (argc > 1) {
			AstrOWar::GameModelSingleton.startServer(port);
		}
		else {
			AstrOWar::GameModelSingleton.startClient(address, port);
		}
	});
	game.launch();
	cout << "APP END" << endl;
	return 0;
}
