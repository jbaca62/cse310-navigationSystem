EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files main.o somefile.o
$(EXEC)	: main.o util.o Heap.o Element.o
# run is created by the command g++ -o run main.o somefile.o
	$(CC) -o $(EXEC) main.o util.o Heap.o Element.o

# main.o depends on the files main.h main.c
# main.o is created by the command g++ -c -Wall main.c
main.o	: main.cpp
	$(CC) $(CFLAGS) main.cpp

util.o	: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

Heap.o	: Heap.h Heap.cpp
	$(CC) $(CFLAGS) Heap.cpp

Element.o	: Element.h Element.cpp
	$(CC) $(CFLAGS) Element.cpp

clean	:
	rm *.o
