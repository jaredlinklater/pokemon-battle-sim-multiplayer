#include "server.h"

void serverError(string error) {
	printf("%s\n", error.c_str());
	exit(EXIT_FAILURE);
}

void Server::init() {
	port = 4434;

	//Socket file descriptor
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		serverError("Socket failed");

	//Set socket options
	int opt = 1;
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
		serverError("Setsockopt failed");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	//Bind socket to port
	if(bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0)
		serverError("Bind failed");
}

int Server::beginListening() {
	char buffer[4096] = {0};
	int addrlen = sizeof(address); 

	//Listen for new connections
	if(listen(server_fd, 3) < 0)
		serverError("Listening failed");

	while(1) {
		//Accept new connections
		if((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*)&addrlen)) < 0)
			serverError("Accepting connection failed");

		read(new_socket, buffer, 4096);
		printf("Message recieved:\n%s\n", buffer);
		char const *hello = "Hello from server";
		send(new_socket, hello, strlen(hello), 0);
	}

	return 0;
}