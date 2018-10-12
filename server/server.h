#include <unistd.h> //read
#include <netinet/in.h>
#include <string>
#include <cstring> //strlen
using namespace std;

class Server {
public:
	int port;
	int server_fd, new_socket;
	struct sockaddr_in address;

	void init();
	int beginListening();
};