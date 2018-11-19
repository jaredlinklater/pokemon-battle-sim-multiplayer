#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <string.h>
using namespace std;

class client {
public:
	int port;
	int sock;
	struct sockaddr_in address;
	struct sockaddr_in serv_addr;

	int init();
	int connectToServer();
	void sendToServer(int min, int max);
};

#endif