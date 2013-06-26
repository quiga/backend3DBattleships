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

void run(int i){
	cout << "RUN START" << endl;
	cout << "RUN END" << endl;
}

int main(int argc, char* argv[]) {
	cout << "APP START" << endl;

	Thread first(std::bind(&run, argc));
	first.launch();

	cout << "APP END" << endl;
	return 0;
}
