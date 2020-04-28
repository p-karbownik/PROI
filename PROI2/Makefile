__start__: a.out
	./a.out

a.out: main.o IntTest.o Person.o PersonTest.o
	g++ main.o IntTest.o Person.o PersonTest.o

main.o: main.cpp IntTest.h PersonTest.h
	g++ -c -Wall -pedantic main.cpp

PersonTest.o: PersonTest.h PersonTest.cpp DoublyLinkedList.h Person.h
	g++ -c -Wall -pedantic PersonTest.cpp

Person.o: Person.h Person.cpp
	g++ -c -Wall -pedantic Person.cpp

IntTest.o: IntTest.h IntTest.cpp DoublyLinkedList.h
	g++ -c -Wall -pedantic IntTest.cpp

remake : clean run

