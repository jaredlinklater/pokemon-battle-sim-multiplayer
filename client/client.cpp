#include <iostream>
#include <sstream>
#include "client.h"

//Gets int input from command line and error checks
int getInput(int min, int max) {
	int input;
	string x;

	getline(cin, x);
	stringstream(x) >> input;
	while(!(input >= min && input <= max)) { //Error checking
		cout << "Invalid selection! Please enter a number from " << min << " to " << max << "." << endl;
		getline(cin, x);
		stringstream(x) >> input;
	}

	return input;
}

int clientError(string error) {
	printf("%s\n", error.c_str());
	return -1;
}
   
int client::init() {
	port = 4434;
	sock = 0;

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return clientError("\nSocket creation error");
   
	memset(&serv_addr, '0', sizeof(serv_addr));
   
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	   
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
		return clientError("\nInvalid address/ Address not supported");
	return 0;
}

int client::connectToServer() {
	char buffer[1024] = {0};
	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		return clientError("\nConnection Failed");

	char *message = "Attempting connection!\n";
	send(sock, message, strlen(message), 0);
	printf("Connecting...\n");

	read(sock, buffer, 1024);
	printf("%s\n", buffer);
	memset(buffer, 0, sizeof(buffer));
	
	/*read(sock, buffer, 1024);
	printf("%s\n", buffer);
	memset(buffer, 0, sizeof(buffer));
	*/

	char const *message2 = "hello1";
	send(sock, message2, strlen(message2), 0);

	while(1) {
		//sendToServer(1, 4);
	}
	
	return 0; 
}

void client::sendToServer(int min, int max) {
	char const *message = to_string(getInput(min, max)).c_str();
	send(sock, message, strlen(message), 0);
}