// MADE BY ONUR VURAL
TO READ THE FILES ffstream library is used 

// THE FOLLOWING MAKEFILE CAN BE USED TO COMPILE THE SRC FILES
# -*- Makefile -*-
hw4: main.o WordNetwork.o hashTable.o Stack.o Queue.o
	g++ main.o WordNetwork.o hashTable.o Stack.o Queue.o -o hw4

main.o: main.cpp WordNetwork.cpp hashTable.cpp Stack.cpp Queue.cpp
	g++ -c main.cpp

WordNetwork.o: WordNetwork.cpp hashTable.cpp Stack.cpp Queue.cpp
	g++ -c WordNetwork.cpp

hashTable.o: hashTable.cpp
	g++ -c hashTable.cpp

Stack.o: Stack.cpp
	g++ -c Stack.cpp

Queue.o: Queue.cpp
	g++ -c Queue.cpp

Remove:
	rm -f main.o WordNetwork.o hashTable.o Stack.o Queue.o hw4