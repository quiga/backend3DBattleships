//============================================================================
// Name        : AstrOWar.cpp
// Author      : Lászlóffy Barnabás (lasba)
// Version     :
// Copyright   : I'm all right!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "game/client/gameModel.h"
#include "game/server/network.h"

const unsigned short port = 50003;
const std::string address = "127.0.0.1";

int main(int argc, char** argv) {
	AstrOWar::GameModelSingleton.init();
	//AstrOWar::GameModelSingleton.createTeszt();

	char who;
	std::cout << "Do you want to be a server (s) or a client (c) ? ";
	std::cin >> who;

	if (who == 's'){
		AstrOWar::NetworkSingleton.startAsServer(port);
		while(!AstrOWar::NetworkSingleton.isEnableConnection()){}
		cout<<"Adat kuldese"<<endl;
		AstrOWar::NetworkSingleton.sendMessage("szeva");
	}
	else{
		AstrOWar::NetworkSingleton.startAsClient(address, port);
	}



	return 0;
}
