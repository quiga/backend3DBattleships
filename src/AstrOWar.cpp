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

namespace AstrOWar{
struct graphics{
	int i;
	void event1(bool){}
	void event2(int, int, int, bool, bool){}
	void event3(int){}
	void event4(){}
};
}

void run(int i){
	cout << "RUN START" << endl;

	AstrOWar::graphics g;
	AstrOWar::GameModelSingleton.init(&g);
	AstrOWar::GameModelSingleton.registerDeadEventHandler(&AstrOWar::graphics::event1);
	AstrOWar::GameModelSingleton.registerFireEventHandler(&AstrOWar::graphics::event2);
	AstrOWar::GameModelSingleton.registerHitEventHandler(&AstrOWar::graphics::event2);
	AstrOWar::GameModelSingleton.registerErrorEventHandler(&AstrOWar::graphics::event3);
	AstrOWar::GameModelSingleton.registerExitEventHandler(&AstrOWar::graphics::event4);

	cout << "RUN END" << endl;
}

int main(int argc, char* argv[]) {
	cout << "APP START" << endl;

	Thread first(std::bind(&run, argc));
	first.launch();

	cout << "APP END" << endl;
	return 0;
}
