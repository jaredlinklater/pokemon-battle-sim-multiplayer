#ifndef SERVER_H
#define SERVER_H

#include <unistd.h> //read
#include <netinet/in.h>
#include <string>
#include <cstring> //strlen
using namespace std;

class server {
public:
	int port;
	int server_fd, new_socket;
	struct sockaddr_in address;

	char buffer[4096] = {0};
	int connections;

	void init();
	int beginListening();
	void sendToClient(string s);

	void serverPrint(char* s);
	void clearBuffer();
};

#endif