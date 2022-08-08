# -*- Makefile -*-
simulator: main.o simulator.o PriorityQueue.o Heap.o Request.o
	g++ main.o simulator.o PriorityQueue.o Heap.o Request.o -o simulator

main.o: main.cpp simulator.cpp PriorityQueue.cpp Heap.cpp Request.cpp
	g++ -c main.cpp

simulator.o: simulator.cpp PriorityQueue.cpp Heap.cpp Request.cpp
	g++ -c simulator.cpp

PriorityQueue.o: PriorityQueue.cpp Heap.cpp Request.cpp
	g++ -c PriorityQueue.cpp

Heap.o: Heap.cpp Request.cpp
	g++ -c Heap.cpp

Request.o: Request.cpp
	g++ -c Request.cpp

Remove:
	rm -f main.o simulator.o PriorityQueue.o Heap.o Request.o simulator
