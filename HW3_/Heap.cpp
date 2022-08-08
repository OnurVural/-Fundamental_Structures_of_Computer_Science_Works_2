/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Implementation of MaxHeap class & its functions
*/
#include "Heap.h"

    Heap::Heap(){
        size = 0; //Empty heap
    }

    bool Heap::heapIsEmpty() const{
        return (size == 0);
    }

    void Heap::heapInsert(const HeapItemType& newItem){
        if (size >= MAX_HEAP){
            cout << "HEAP IS FULL..." << endl;
            return;
        }

        // INSERT TO NEXT EMPTY PLACE
        items[size] = newItem;

        int place = size;
        int parent = (place - 1)/2;
        // UNTIL PARENT IS SMALLER THAN CHILD SWAP VALUES
        while((place > 0) && (items[place].getPriorityNo() > items[parent].getPriorityNo())){
            HeapItemType temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent; // SET CURRENT PARENT AS CHILD
            parent = (place - 1)/2; // CALCULATE NEW PARENT
        }
        ++size;
    }
    void Heap::heapDelete(HeapItemType & rootItem){
        if (heapIsEmpty()){
            cout << "EMPTY HEAP CANNOT DELETE..." << endl;
            return;
        }
        else{
            // SIMPLY DELETE ROOT AT INDEX 0 AND DECREASE SIZE
            rootItem = items[0];
            items[0] = items[--size];
            // CALL HEAP REBUILD TO AVOID ANY VIOLATION IN HEAP PROPERTY
            heapRebuild(0);
        }

    }

    void Heap::heapDelete(){
         if (heapIsEmpty()){
            cout << "EMPTY HEAP CANNOT DELETE..." << endl;
            return;
        }
        else{
            // SIMPLY DELETE ROOT AT INDEX 0 AND DECREASE SIZE
            items[0] = items[--size];
            // CALL HEAP REBUILD TO AVOID ANY VIOLATION IN HEAP PROPERTY
            heapRebuild(0);
        }
    }

    HeapItemType Heap::peek(){
        // RETURN ROOT VALUE
        return items[0];
    }

    void Heap::heapRebuild(int root){
        int child = 2 * root + 1; // index of root's left child if any
        if (child < size){
                // root is not a leaf so that it has left child
            int rightChild = child + 1;

            // if root has right child, find larger ----> IF BOTH HAVE EQUAL PRIORITY VALUE, SELECT EARLIER
            if (( (rightChild < size) && (items[rightChild].getPriorityNo() > items[child].getPriorityNo())) ||
            ((rightChild < size) && (items[rightChild].getPriorityNo() == items[child].getPriorityNo()) && (items[rightChild].getRequestTime() < items[child].getRequestTime())))
                child = rightChild;
            // if root's item is smaller than larger child, swap values ----> IF BOTH PARENT AND CHILD HAVE SAME PRIORITY VALUE, SELECT EARLIER
            if ( (items[root].getPriorityNo() < items[child].getPriorityNo()) || (items[root].getPriorityNo() == items[child].getPriorityNo() && items[root].getRequestTime() > items[child].getRequestTime()) ){
                HeapItemType temp = items[root];
                items[root] = items[child];
                items[child] = temp;

                // check new subtree once again
                heapRebuild(child);
            }
        }

    }
