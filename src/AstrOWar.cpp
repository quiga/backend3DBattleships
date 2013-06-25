//============================================================================
// Name        : AstrOWar.cpp
// Author      : Lászlóffy Barnabás (lasba)
// Version     :
// Copyright   : I'm all right!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "battleshipTeszt.h"

const unsigned short port = 50002;
const std::string address = "127.0.0.1";

#define SERVER true
#define CLIENT false

int main(int argc, char** argv) {
	cout << "SERVER START" << endl;

	battleshipTeszt playerOne(SERVER, port);
	playerOne.start();

	cout << "KLIENS START" << endl;

	battleshipTeszt playerTwo(CLIENT, port, address);
	playerTwo.start();

	return 0;
}
