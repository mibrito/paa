CC=g++
CFLAGS= -Wall -g -O3

all: tp2

tp2: io.o graph.o main.o
	$(CC) -o tp2 io.o graph.o main.o

# main.o: main.c teste.h
main.o: main.cpp io.hpp
	$(CC) -o main.o -c main.cpp $(CFLAGS)

io.o: io.cpp io.hpp
	$(CC) -o io.o -c io.cpp $(CFLAGS)

graph.o: graph.cpp graph.hpp
	$(CC) -o graph.o -c graph.cpp $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf tp2

run: tp2
	./tp2 ../tests/in/pdf1.in
