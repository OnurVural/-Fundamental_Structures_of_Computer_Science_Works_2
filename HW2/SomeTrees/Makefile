# -*- Makefile -*-
hw2: main.o BinarySearchTree.o NodeQueue.o BinaryNode.o
	g++ main.o BinarySearchTree.o NodeQueue.o BinaryNode.o -o hw2

BinaryNode.o: BinaryNode.cpp
	g++ -c BinaryNode.cpp

NodeQueue.o: NodeQueue.cpp BinaryNode.cpp
	g++ -c NodeQueue.cpp

BinarySearchTree.o: BinarySearchTree.cpp NodeQueue.cpp BinaryNode.cpp
	g++ -c BinarySearchTree.cpp

main.o: main.cpp BinarySearchTree.cpp NodeQueue.cpp BinaryNode.cpp
	g++ -c main.cpp

Remove:
	rm -f BinaryNode.o NodeQueue.o BinarySearchTree.o main.o hw2
