#include <iostream>
#include "client.h"
using namespace std;

//Main function, initialises and starts game
int main() {
	client cli;
	cli.init();
	cli.connectToServer();

	cout << endl << "Thanks for playing!" << endl;

	return 0;
}