# compiler
CC = g++

# compiler flags:
# -g     - adds debugging information to exe file
# -Wall  - turns on most compiler warnings
CFLAGS = -g -Wall

# build target
main: main.o Grid.o Node.o
	$(CC) $(CFLAGS) -o main main.o Grid.o Node.o

main.o: ./src/main.cpp ./src/Grid.h
	$(CC) $(CFLAGS) -c ./src/main.cpp

Grid.o: ./src/Grid.cpp ./src/Node.h
	$(CC) $(CFLAGS) -c ./src/Grid.cpp

Node.o: ./src/Node.cpp
	$(CC) $(CFLAGS) -c ./src/Node.cpp

clean:
	rm -f *.o main
