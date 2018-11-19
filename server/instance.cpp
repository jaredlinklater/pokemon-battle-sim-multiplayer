#include <iostream>
#include "instance.h"
#include "game.h"

void instance::newGame() {
	game gameA;
	gameA.init();
	gameA.start();

	cout << endl << "Thanks for playing!" << endl;
}