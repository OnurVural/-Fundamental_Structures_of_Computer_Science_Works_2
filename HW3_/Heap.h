/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Declaration of MaxHeap class & its functions
*/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;
const int MAX_HEAP = 100; // DEFINE MAX HEAP SIZE
#include "Request.h"
typedef Request HeapItemType;

class Heap
{
    public:
        Heap();
        //~Heap();

        /*
        Checks whether the heap is empty or not
        @return: true if empty, else otherwise
        */
        bool heapIsEmpty() const;

        /*
        Inserts item to MaxHeap
        @param newItem: item to be inserted
        */
        void heapInsert(const HeapItemType& newItem);

        /*
        Deletes item from MaxHeap
        @param rootItem: item that is deleted
        */
        void heapDelete(HeapItemType & rootItem);

        /*
        Deletes item from MaxHeap
        */
        void heapDelete();

        /*
        Returns root value of MaxHeap
        @return: root item
        */
        HeapItemType peek();


    protected:
        /*
        Rebuilds the MaxHeap until it satisfies its properties
        */
        void heapRebuild(int root);

    private:
        HeapItemType items[MAX_HEAP];
        int size;
};

#endif // HEAP_H
