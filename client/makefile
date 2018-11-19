CXXFLAGS = -std=c++11 -Wall -pedantic

client: main.o client.o
	g++ -o $@ $^

clean:
	rm *.o