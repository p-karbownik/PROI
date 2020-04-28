__start__: a.out
	./a.out

a.out: main.o CircularBuffer.o
	g++ main.o CircularBuffer.o

main.o: main.cpp CircularBuffer.h
	g++ -c -Wall -pedantic main.cpp

CircuralBuffer.o: CircularBuffer.h CircularBuffer.cpp
	g++ -c -Wall -pedantic CircularBuffer.cpp

remake : clean run

