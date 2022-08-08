/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : N.Onur Vural
* ID: 21902330
* Section : 2
* Assignment : 4
* Description : declaration of Queue class
*/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
typedef int QueueItemType;

class Queue
{
    public:
        // Constructor and destructor
        Queue();
        ~Queue();
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

    private:
        struct QueueNode{
        QueueItemType  item;
        QueueNode     *next;
    };
    //two nodes so that they point end and beginning of queue
    QueueNode *backPtr;
    QueueNode *frontPtr;
};

#endif // QUEUE_H
