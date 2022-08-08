/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : implementation of Queue class
*/
#include "Queue.h"

Queue::Queue(){
    //instantiate by pointing the both pointers to null
    backPtr = NULL;
    frontPtr= NULL;
}


Queue::~Queue(){
    while (!isEmpty()) //while not empty
        dequeue(); // remove from front
}

bool Queue::isEmpty() const{
    return backPtr == NULL;
}
void Queue::enqueue(QueueItemType newItem){
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
void Queue::dequeue(){
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

void Queue::getFront(QueueItemType& queueFront) const{
        queueFront = frontPtr->item; // return item
}
