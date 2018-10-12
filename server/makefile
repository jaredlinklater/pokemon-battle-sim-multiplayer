CXXFLAGS = -std=c++11 -Wall -pedantic

main: main.o server.o
	g++ -o $@ $^

server: server.o
	g++ -o $@ $^

client: client.o
	g++ -o $@ $^

clean:
	rm *.o 