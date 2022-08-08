/*
* Title: Binary Search Trees
* Author: N.ONUR VURAL
* ID: 21902330
* Section: 2
* Assignment: 2
* Description: Binary Node implementation
*/
#include "BinaryNode.h"

BinaryNode::BinaryNode(){} //DEFAULT CONSTRUCTOR EMPTY

//MAIN CONSTRUCTOR
BinaryNode::BinaryNode(const int& nodeItem, BinaryNode *left, BinaryNode *right)
:item(nodeItem),leftChildPtr(left),rightChildPtr(right){
}

