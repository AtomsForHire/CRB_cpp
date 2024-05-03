CC = g++
CFLAGS = -Wall -g -std=c++17
INCLUDE = -I /usr/local/include

main: main.o 
	$(CC) $(CFLAGS) $(INCLUDE) -o main main.o

main.o: main.cpp 
	$(CC) $(CFLAGS) $(INCLUDE) -c main.cpp

clean:
	rm *.o main
