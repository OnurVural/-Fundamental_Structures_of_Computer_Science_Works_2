/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Declaration of simulator class & its functions
*/

#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Request.h"
#include "Heap.h"
#include "PriorityQueue.h"

class simulator
{
    public:
        // const
        simulator();

        /* Starts the simulation and returns the corresponding average time
        @param requests: request array
        @param totalRequests: size of request array
        @param desiredMAXAvgTime: the desired time
        @param printerNo: given printer number
        @return: corresponding average time
        */
        double simulate(Request *& requests, const int totalRequests, const int desiredMAXAvgTime, const int printerNo );

        /* Starts the simulation and prints the printing process as well as corresponding average time
        @param requests: request array
        @param totalRequests: size of request array
        @param desiredMAXAvgTime: the desired time
        @param printerNo: given printer number
        */
        void display(Request *& requests, const int totalRequests, const int desiredMAXAvgTime, const int printerNo );

    protected:

    private:
        PriorityQueue PQ; // Uses a PriorityQueue within
};

#endif // SIMULATOR_H
