// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#define PORT 4434

void clientError(string error) {
	printf("%s\n", error);
	return -1;
}
   
int main() {
	struct sockaddr_in address;
	int sock = 0;
	struct sockaddr_in serv_addr;
	time_t timer = time(NULL);
	time (&timer);
	char *hello = ctime (&timer);
	char buffer[1024] = {0};

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return clientError("\nSocket creation error");
   
	memset(&serv_addr, '0', sizeof(serv_addr)); 
   
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	   
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
		clientError("\nInvalid address/ Address not supported");

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		clientError("\nConnection Failed");

	send(sock, hello, strlen(hello), 0); 
	printf("Hello message sent\n"); 
	read(sock, buffer, 1024); 
	printf("%s\n", buffer);
	
	return 0; 
}