EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files main.o somefile.o
$(EXEC)	: main.o util.o Heap.o Edge.o Graph.o Vertex.o
# run is created by the command g++ -o run main.o somefile.o
	$(CC) -o $(EXEC) main.o util.o Heap.o Edge.o Graph.o Vertex.o

# main.o depends on the files main.h main.c
# main.o is created by the command g++ -c -Wall main.c
main.o	: main.cpp
	$(CC) $(CFLAGS) main.cpp

util.o	: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

Heap.o	: Heap.h Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp

Edge.o	: Edge.h Edge.cpp
	$(CC) $(CFLAGS) Edge.cpp

Graph.o	: Graph.h Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

Vertex.o	: Vertex.h Vertex.cpp
	$(CC) $(CFLAGS) Vertex.cpp

clean	:
	rm *.o
