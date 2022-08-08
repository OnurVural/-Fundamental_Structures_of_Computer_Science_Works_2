/*
* Title: Binary Search Trees
* Author: N.ONUR VURAL
* ID: 21902330
* Section: 2
* Assignment: 2
* Description: The BST implementation
*/
#include "BinarySearchTree.h"
#include "NodeQueue.h"

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    destroyTree(root);
}

void BinarySearchTree::destroyTree(BinaryNode*& treePtr){
        if (treePtr) { // check while root is not empty
        // RECURSIVE CALL TO CLEAR THE TREE BY L-R CHILD AND ROOT
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL; // DEFENSE
        }
}

bool BinarySearchTree::isEmpty(){
    return (root == NULL);
}

int BinarySearchTree::getHeight(){
    return getHeight(root); //USE HELPER TO CHECK RECURSIVELY
}

int BinarySearchTree::getHeight(BinaryNode* treePtr){
    if (!treePtr) //base case for empty node
        return 0;
    else
        return maximum(getHeight(treePtr->leftChildPtr),getHeight(treePtr->rightChildPtr)) + 1; // check both children

}
int BinarySearchTree::maximum(int num1, int num2){
    if ( num1 >= num2 )
        return num1;
    else
        return num2;
}

int BinarySearchTree::getNumberOfNodes(){
    return getNumberOfNodes(root); //USE HELPER TO CHECK RECURSIVELY
}

int BinarySearchTree::getNumberOfNodes(BinaryNode* treePtr){
    if (!treePtr) //base case for empty node
        return 0;
    else{
        return 1 + getNumberOfNodes(treePtr->leftChildPtr) + getNumberOfNodes(treePtr->rightChildPtr); // GET TOTAL RECURSIVELY
    }
}

bool BinarySearchTree::add(const int newEntry){
     return (add(root, newEntry)); // USE HELPER TO CHECK RECURSIVELY WITH PLACING ROOT
}

bool BinarySearchTree::add(BinaryNode *&treePtr, const int newEntry){
    // INSERT TO CORRESPONDING LEAF IF POSITION FOUND
    if (!treePtr) {
        treePtr = new BinaryNode(newEntry, NULL, NULL); //WHEN A PROPER LEAF POS FOUND INSERT
        return true; //ADDITION SUCCESFULL
    }
    else if ( newEntry == treePtr->item) {
        return false; // IF ITEM ALREADY EXISTS EXIT IMMEDIAETLY
    }

    //CONTINUE SEARCHING FOR A PROPER LEAF POSITION DEPENDING ON THE VALUE
    else if ( newEntry < treePtr->item) // VALUE SMALLER THAN CURRENT
        return add(treePtr->leftChildPtr, newEntry); // CHECK LEFT SUBTREE
    else // VALUE LARGER THAN CURRENT
        return add(treePtr->rightChildPtr, newEntry); // CHECK RIGHT SUBTREE
}

bool BinarySearchTree::remove(const int anEntry){
    return remove(root, anEntry); //USE HELPER TO CHECK RECURSIVELY
}


bool BinarySearchTree::remove(BinaryNode *&treePtr, const int anEntry){
    if (treePtr == NULL)
        return false; //CHECKED ALL BUT FAILED
    //ITEM FOUND
    else if(anEntry == treePtr->item){
            deleteBinaryNode(treePtr); //CALL DELETE
            return true; //EXIT
    }
    //CONTINUE SEARCHING FOR A PROPER LEAF POSITION DEPENDING ON THE VALUE
    else if(anEntry < treePtr->item) // VALUE SMALLER THAN CURRENT
        remove(treePtr->leftChildPtr, anEntry); // CHECK LEFT SUBTREE
    else // VALUE LARGER THAN CURRENT
        remove(treePtr->rightChildPtr, anEntry); // CHECK RIGHT SUBTREE
}
void BinarySearchTree::deleteBinaryNode(BinaryNode *&nodePtr){
    BinaryNode *delPtr;
    int replacementItem;

    //(1) CHECK FOR LEAF
    if((nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL)){
        delete nodePtr; // directly delete - no worries
        nodePtr = NULL; //self defense
    }

    //(2) CHECK FOR NO LEFT CHILD
    else if(nodePtr->leftChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

    //(3) CHECK FOR NO LEFT CHILD
    else if(nodePtr->rightChildPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }

    //(4) CHECK FOR BOTH CHILDREN
    // FIND INORDER SUCCESSOR
    else{
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }
}

void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int& treeItem){
    //CHECK THE NODES UNTIL FOUND A PROPER LESF NODE TO SWAP AND DELETE IT
    if(nodePtr->leftChildPtr == NULL){
        treeItem = nodePtr->item; // COPY THE ITEM OF THAT NODE
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr; // DELETE THE LEAF NODE
    }
    else  processLeftmost(nodePtr->leftChildPtr, treeItem); //CONTINUE CHECKING
}

bool BinarySearchTree::contains(const int anEntry){
    contains(root, anEntry); //USE HELPER TO CHECK RECURSIVELY
}

bool BinarySearchTree::contains(BinaryNode *treePtr, const int anEntry){
    if(treePtr == NULL)
        return false;
    else if (anEntry == treePtr->item)
        return true;
    else if (anEntry < treePtr->item)
        contains(treePtr->leftChildPtr, anEntry);
    else
        contains(treePtr->rightChildPtr, anEntry);

}

void BinarySearchTree::preorderTraverse(){
    preorderTraverse(root); //USE HELPER TO CHECK RECURSIVELY
    cout << endl;
}
void BinarySearchTree::preorderTraverse(BinaryNode *treePtr){
    //ROOT - LEFT - RIGHT
    if(treePtr != NULL){
        cout << treePtr->item << ", ";
        preorderTraverse(treePtr->leftChildPtr);
        preorderTraverse(treePtr->rightChildPtr);
    }
    return;
}


void BinarySearchTree::inorderTraverse(){
    inorderTraverse(root); //USE HELPER TO CHECK RECURSIVELY
    cout << endl;
}
void BinarySearchTree::inorderTraverse(BinaryNode *treePtr){
    //LEFT - ROOT - RIGHT
    if(treePtr != NULL){
        inorderTraverse(treePtr->leftChildPtr);
        cout << treePtr->item << ", ";
        inorderTraverse(treePtr->rightChildPtr);
    }
    return;
}

void BinarySearchTree::postorderTraverse(){
    postorderTraverse(root); //USE HELPER TO CHECK RECURSIVELY
    cout << endl;
}
void BinarySearchTree::postorderTraverse(BinaryNode *treePtr){
    //LEFT - RIGHT - ROOT
    if(treePtr != NULL){
        postorderTraverse(treePtr->leftChildPtr);
        postorderTraverse(treePtr->rightChildPtr);
        cout << treePtr->item << ", ";
    }
    return;

}

void BinarySearchTree::levelorderTraverse(){
    levelorderTraverse(root); //USE HELPER TO CHECK RECURSIVELY
    cout << endl;
}

//O(N) AS ITERATIVELY LOOKS FOR ALL NODES IN WORST CASE SCENERIO
void BinarySearchTree::levelorderTraverse(BinaryNode *treePtr){
    if (treePtr){ // CHECK IF THERE ARE ELEMENTS INSIDE TREE
        NodeQueue nq;
        nq.enqueue(treePtr); // FIRST INSERT THE ROOT

        while (!(nq.isEmpty()))
        {
            BinaryNode *curNode;
            nq.getFront(curNode); //GET THE ITEM IN THE FRONT OF QUEUE
            cout << curNode->item << ", "; //PRINT THE ITEM
            nq.dequeue(); //AFTER PRINTING WE ARE FINISHED WITH THE CURRENT NODE

            // ADD TWO CHILDREN TO THE QUEUE SO THAT THEY CAN BE REACHED AFTER ONE BY ONE
            if (curNode->leftChildPtr != NULL)
                nq.enqueue(curNode->leftChildPtr);
            if (curNode->rightChildPtr != NULL)
                nq.enqueue(curNode->rightChildPtr);
        }
    }
}

int BinarySearchTree::span(const int a, const int b){
    span(root, a, b); //USE HELPER TO CHECK RECURSIVELY
}
int BinarySearchTree::span(BinaryNode *treePtr, const int a, const int b){
    if (!treePtr) //(1) BASE CASE
        return 0;
    //CHECK IF IT IS IN RANGE
    // CASE 1: When current has a value within range
    if ( a <= treePtr->item && b >= treePtr->item )
        return span(treePtr->leftChildPtr, a, b) + span(treePtr->rightChildPtr, a, b) + 1; //i++ as it is in range
    // CASE 2: When current has a value smaller than lower bound
    else if ( a > treePtr->item )
        span(treePtr->rightChildPtr, a, b); // recursively check larger by checking the next BIGGEST (right child)
    // CASE 3: When current has a value larger than upper bound
    else if ( b < treePtr->item )
        span(treePtr->leftChildPtr, a, b); // recursively check smaller by checking the next LARGEST (left child)
}

void BinarySearchTree::mirror(){
    mirror(root); //USE HELPER TO CHECK RECURSIVELY
}

void BinarySearchTree::mirror(BinaryNode *&treePtr){
    if (treePtr){
        // CALL RECURSION FOR BOTH CHILDREN
        mirror(treePtr->leftChildPtr);
        mirror(treePtr->rightChildPtr);
        // SWAP NODES
        BinaryNode *swapNode = treePtr->leftChildPtr;
        treePtr->leftChildPtr = treePtr->rightChildPtr;
        treePtr->rightChildPtr = swapNode;
    }
    return; //BASE CASE WHEN WE REACH EMPTY NODE
}

