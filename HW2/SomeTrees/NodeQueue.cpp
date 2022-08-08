/*
* Title: Binary Search Trees
* Author: N.ONUR VURAL
* ID: 21902330
* Section: 2
* Assignment: 2
* Description: NodeQueue implementation
*/
#include "NodeQueue.h"

NodeQueue::NodeQueue(){
    //instantiate by pointing the both pointers to null
    backPtr = NULL;
    frontPtr= NULL;
}


NodeQueue::~NodeQueue(){
    while (!isEmpty()) //while not empty
        dequeue(); // remove from front
}

bool NodeQueue::isEmpty() const{
    return backPtr == NULL;
}
void NodeQueue::enqueue(QueueItemType newItem){
    // make a new node
    QueueNode *newPtr = new QueueNode;

    // set the item as given value
    newPtr->item = newItem;
    newPtr->next = NULL;

    // attach it to the very end of queue
    if (isEmpty())   // if it is empty you need to set it to front
        frontPtr = newPtr;
    else             // insert in a non-empty end
        backPtr->next = newPtr;

    backPtr = newPtr;  // update backptr

}
void NodeQueue::dequeue(){
        QueueNode *tempPtr = frontPtr;
        if (frontPtr == backPtr){   // special case
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next; // update the beginning with the second node

        tempPtr->next = NULL;  // defensive strategy
        delete tempPtr; // delete the node
}

void NodeQueue::getFront(QueueItemType& queueFront) const{
        queueFront = frontPtr->item; // return item
}



