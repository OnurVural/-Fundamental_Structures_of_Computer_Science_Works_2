/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Declaration of PriorityQueue class & its functions
*/
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"
typedef HeapItemType PQItemType;

class PriorityQueue
{
    public:
        // constructor
        PriorityQueue();

        /*
        Checks whether PQ is empty or not
        @return: true if empty, false otherwise
        */
        bool pqIsEmpty() const;

        /*
        Inserts an item to PQ
        @param newItem: item to be inserted
        */
        void pqInsert(const PQItemType& newItem);

        /*
        Deletes Largest Keyed Item in PQ
        @return: the item with highest priority
        */
        void pqDelete(PQItemType& priorityItem);

        /*
        Deletes Largest Keyed Item in PQ
        */
        void pqDelete();

        /*
        Checks Largest Keyed Item in PQ
        @return: item with highest priority
        */
        HeapItemType peek();

    protected:

    private:
        Heap h; //uses a MaxHeap within
};

#endif // PRIORITYQUEUE_H
