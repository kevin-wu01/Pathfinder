# compiler
CC = g++

# compiler flags:
# -g     - adds debugging information to exe file
# -Wall  - turns on most compiler warnings
CFLAGS = -g -Wall

# build target
main: main.o Grid.o
	$(CC) $(CFLAGS) -o main main.o Grid.o

main.o: ./src/main.cpp ./src/Grid.h
	$(CC) $(CFLAGS) -c ./src/main.cpp

Grid.o: ./src/Grid.h
	$(CC) $(CFLAGS) -c ./src/Grid.cpp

clean:
	rm -f *.o main
