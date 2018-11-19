#include <iostream>
#include "server.h"
#include "instance.h"
using namespace std;

void serverError(string error) {
	printf("%s\n", error.c_str());
	exit(EXIT_FAILURE);
}

void server::clearBuffer() {
	memset(buffer, 0, sizeof(buffer));
}

void server::serverPrint(char* s) {
	printf("%s%s\n", s, buffer);
	clearBuffer();
}

void server::init() {
	port = 4434;

	//Get socket file descriptor
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		serverError("Socket failed");

	//Set socket options
	int opt = 1;
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1)
		serverError("Setsockopt failed");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	//Bind socket to port
	if(bind(server_fd, (struct sockaddr*) &address, sizeof(address)) == -1)
		serverError("Bind failed");
}

int server::beginListening() {
	int addrlen = sizeof(address); 

	//Listen for new connections
	if(listen(server_fd, 3) == -1)
		serverError("Listening failed");

	while(1) {
		//Accept new connections
		if((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*)&addrlen)) < 0)
			serverError("Accepting connection failed");

		sendToClient("Connected! Starting new game...\n");
		printf("Connected on socket %i\n", new_socket);

		/*instance instance1;
		instance1.newGame();*/

		/*read(new_socket, buffer, 4096);
		serverPrint("Message recieved:\n    ");*/

		sendToClient("Hello from server!");

		while(1) {
			if(recv(new_socket, buffer, 4096, 0) == 0) {
				serverError("Connection closed");
			}
			serverPrint("Message recieved:\n    ");
		}
	}
	return 0;
}

void server::sendToClient(string s) {
	send(new_socket, s.c_str(), strlen(s.c_str()), 0);
}