#include <iostream>
#include "server.h"
using namespace std;

int main() {
	server serv;
	serv.init();
	serv.beginListening();

	return 0;
}