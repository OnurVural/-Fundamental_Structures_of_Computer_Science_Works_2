/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Implementation of PrýorityQueue class & its functions
*/
#include "PriorityQueue.h"

        PriorityQueue::PriorityQueue()
        {
            //ctor
        }

        // JUST CALL THE PROPER FUNCTIONS OF MAXHEAP INSIDE THE FUNCTIONS

        bool PriorityQueue::pqIsEmpty() const {
            return h.heapIsEmpty();
        }

        void PriorityQueue::pqInsert(const PQItemType& newItem){
            h.heapInsert(newItem);
        }

        void PriorityQueue::pqDelete(PQItemType& priorityItem){
            h.heapDelete(priorityItem);
        }

        void PriorityQueue::pqDelete(){
             h.heapDelete();
        }

        HeapItemType PriorityQueue::peek(){
            return h.peek();
        }

