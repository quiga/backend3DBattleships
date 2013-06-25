//============================================================================
// Name        : AstrOWar.cpp
// Author      : Lászlóffy Barnabás (lasba)
// Version     :
// Copyright   : I'm all right!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//#include "battleshipTeszt.h"
#include "game/models/GameModel.h"

const unsigned short port = 50003;
const std::string address = "127.0.0.1";

#define SERVER true
#define CLIENT false

//#define selector true
#define selector false

int main(int argc, char** argv) {


	AstrOWar::GameModelSingleton.init();

	cout << "APP START" << endl;
	/*
	if (selector) {
		cout << "SERVER START" << endl;
		battleshipTeszt playerOne(SERVER, port);
		playerOne.start();
	} else {
		cout << "KLIENS START" << endl;
		battleshipTeszt playerTwo(CLIENT, port, address);
		playerTwo.start();
	}
	*/
	return 0;
}
