#include <iostream>
#include "server.h"
using namespace std;

int main() {
	Server server;
	server.init();
	server.beginListening();

	return 0;
}