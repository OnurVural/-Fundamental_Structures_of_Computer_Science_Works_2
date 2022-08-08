/*
* Title: Binary Search Trees
* Author: N.ONUR VURAL
* ID: 21902330
* Section: 2
* Assignment: 2
* Description: NodeQueue declaration
*/
#ifndef NODEQUEUE_H
#define NODEQUEUE_H
#include "BinaryNode.h"
#include <iostream>
using namespace std;
typedef BinaryNode* QueueItemType;

class NodeQueue
{
    public:
        // Constructor and destructor
        NodeQueue();
        ~NodeQueue();
        // Queue operations:
        //return true if queue is empty, false otherwise
        bool isEmpty() const;
        //add an item to the end of the current queue
        void enqueue(QueueItemType newItem);
        //remove item from the first position of queue
        void dequeue();
        //return item in the first position of queue
        void getFront(QueueItemType& queueFront) const;

    protected:
    //node structure pointing to next node
    private:
    struct QueueNode{
        QueueItemType  item;
        QueueNode     *next;
    };
    //two nodes so that they point end and beginning of queue
    QueueNode *backPtr;
    QueueNode *frontPtr;
};

#endif // NODEQUEUE_H




