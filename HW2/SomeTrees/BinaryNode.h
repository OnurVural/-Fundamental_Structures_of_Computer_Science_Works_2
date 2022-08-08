/*
* Title: Binary Search Trees
* Author: N.ONUR VURAL
* ID: 21902330
* Section: 2
* Assignment: 2
* Description: Binary Node Declaration
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>
using namespace std;


class BinaryNode
{
    public:
    private:
        //empty constructor and uggraded constructor
        BinaryNode();
        BinaryNode(const int& nodeItem, BinaryNode *left = NULL, BinaryNode *right = NULL );

        int item; // the data item of tree
        // pointers to two children nodes
        BinaryNode *leftChildPtr;
        BinaryNode *rightChildPtr;

        // declare classes that should reach the private properties of Binary Node
        friend class BinarySearchTree;
        friend class NodeQueue;
};

#endif // BINARYNODE_H
