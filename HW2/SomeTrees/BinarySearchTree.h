/*
* Title: Binary Search Trees
* Author: N.ONUR VURAL
* ID: 21902330
* Section: 2
* Assignment: 2
* Description: BST class declaration
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"
#include <iostream>
using namespace std;

class BinarySearchTree
{
    public:
        //Constructor and destructor
        BinarySearchTree();
        ~BinarySearchTree();

        // USER INTERFACE
        //@return: true if BST is empty, false otherwise
        bool isEmpty();
        //@return: the corresponding height of BST
        int getHeight();
        //@return: the total number of nodes in BST
        int getNumberOfNodes();

        /* add a new node to the BST with given value
        @param newEntry: desired value to be added
        @return: true if the given entry is not in the BST, false if it already exists
        */
        bool add(const int newEntry);

        /* remove a node from BST with given value
        @param anEntry: desired value to be deleted
        @return: true if the given entry is in the BST, false if it does not exist
        */
        bool remove(const int anEntry);

        /* check whether BST has a node with given value
        @param anEntry: desired value to be checked
        @return: true if the given entry is in the BST, false if it does not exist
        */
        bool contains(const int anEntry);

        // traverse in Root-Left-Right fashion
        void preorderTraverse();
        // traverse in Left-Root-Right fashion
        void inorderTraverse();
        // traverse in Left-Right-Root fashion
        void postorderTraverse();
        // traverse level by level from left to right
        void levelorderTraverse();

        /* check the number of nodes with items on a given range in  a BST structure
        @param a: lower bound
        @param b: upper bound
        @return: the number of nodes within range
        */
        int span(const int a, const int b);

        //symmetrically change the left and right children in a BST
        void mirror();

    protected:

    private:
        BinaryNode *root; //THE POINTER OF ROOT
        // HELPER FUNCTIONS
        //helpers
        //As an addition gets the treePtr so that we can process the data recursively
        void destroyTree(BinaryNode*& treePtr);
        //As an addition gets the treePtr so that we can process the data recursively
        int getHeight(BinaryNode* treePtr);
        //finds the maximum of two given values-used for height function
        int maximum(int num1, int num2);

        //As an addition gets the treePtr so that we can process the data recursively
        int getNumberOfNodes(BinaryNode* treePtr);

        //As an addition gets the treePtr so that we can process the data recursively
        bool add(BinaryNode *& treePtr, const int newEntry);

        //As an addition gets the treePtr so that we can process the data recursively
        bool remove(BinaryNode *&treePtr, const int anEntry);

        //As an addition gets the treePtr so that we can process the data recursively
        void deleteBinaryNode(BinaryNode *&nodePtr);

        //to make the delete operation find the next largest to swap
        void processLeftmost(BinaryNode *&nodePtr, int& treeItem);

        //As an addition gets the treePtr so that we can process the data recursively
        bool contains(BinaryNode *treePtr, const int anEntry);

        //As an addition gets the treePtr so that we can process the data recursively
        void preorderTraverse(BinaryNode *treePtr);
        void inorderTraverse(BinaryNode *treePtr);
        void postorderTraverse(BinaryNode *treePtr);
        void levelorderTraverse(BinaryNode *treePtr);

        //As an addition gets the treePtr so that we can process the data recursively
        int span(BinaryNode *treePtr, const int a, const int b);

        //As an addition gets the treePtr so that we can process the data recursively
        void mirror(BinaryNode *&treePtr);
};

#endif // BINARYSEARCHTREE_H
