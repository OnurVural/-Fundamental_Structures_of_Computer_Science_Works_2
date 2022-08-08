/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: main method to test printer simulation
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>


#include "Request.h"
#include "Heap.h"
#include "PriorityQueue.h"
#include "simulator.h"
using namespace std;

int main(int argc, char **argv)
{
    double timeAvgDesired = atof(argv[2]);
    //double timeAvgDesired = 10;

    ifstream inputFile;
    int totalRequest;
    int requestNum;
    int priorityNum;
    int requestTime;
    int processTime;

    inputFile.open(argv[1]);
    //inputFile.open("print_jobs.txt");

    cout << "The MAX POSSIBLE average time is: " << timeAvgDesired << endl;

    inputFile >> totalRequest;
    cout << "Total requests: " << totalRequest << endl;

    Request* rHolder = new Request[totalRequest];
    int i = 0;


    while(inputFile >> requestNum >> priorityNum >> requestTime >> processTime){
            Request r(requestNum, priorityNum, requestTime, processTime);
            rHolder[i] = r;
            i++;
            //cout << requestNum << ", " << priorityNum << ", " <<  requestTime << ", " << processTime << endl;
    }
    inputFile.close();

    for ( i = 0; i < totalRequest; i++ ){
        cout << rHolder[i].getRequestNo() << ", " << rHolder[i].getPriorityNo() << ", " << rHolder[i].getRequestTime() << ", " << rHolder[i].getProcessTime() << endl;
    }


    simulator Sim;
    double timeAvg;

    // FIND THE SUITABLE PRINTER NO
    int printerNo = 0;
    do{
        printerNo++;
        timeAvg = Sim.simulate(rHolder, totalRequest, timeAvgDesired, printerNo );
    }while(timeAvg > timeAvgDesired);

    // DISPLAY THE RESULTS FOR THE SUITABLE PRINTER NO...
    Sim.display(rHolder, totalRequest, timeAvgDesired, printerNo);


    delete [] rHolder;
    return 0;
}
