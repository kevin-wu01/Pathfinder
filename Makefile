# compiler
CC = g++

# compiler flags:
# -g     - adds debugging information to exe file
# -Wall  - turns on most compiler warnings
CFLAGS = -g -Wall

# build target
main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: ./src/main.cpp $(ARG1)
	$(CC) $(CFLAGS) -c ./src/main.cpp