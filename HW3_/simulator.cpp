/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Implementation of simulator class & its functions
*/
#include "simulator.h"

simulator::simulator()
{
    //ctor
}

double simulator::simulate(Request *& requests, const int totalRequests, const int desiredMAXAvgTime, const int printerNo ){

    // FIRST DECLARE A 2D ARRAY WITH "printerNo" SIZE TO "MIMIC" THE PRINTERS WHERE EACH COLUMN REPRESENTS A PRINTER
    // ROW 1: CHECKS WHETHER THE PRINTER IS USED AT CURRENT TIME OR NOT, RETURNS 1 IF USED, ELSE OTHERWISE
    // ROW 2: KEEPS THE TIME PRINTER IS DONE WITH CURRENT REQUEST
    int **printers = new int* [2];
    for(int j = 0; j < 2; ++j) {
        printers[j] = new int[printerNo];
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < printerNo; j++)
        {
             printers[i][j] = 0;
        }
    }

    int i = 0; // to go through array
    int t = 0; // time in seconds
    double tAvg = 0; // AVERAGE TIME

    int leftToPrint = totalRequests;

    while ( leftToPrint != 0 ){
            // 1) COPY THE REQUESTS SENT IN GIVEN TIME
            for (; i < totalRequests && t >= requests[i].getRequestTime(); i++){
                if (requests[i].getRequestTime() == t)
                    PQ.pqInsert(requests[i]); // if we find request sent in given time we add it to the PQ
            }

            // 2) CHECK PRINTERS AND SEND REQUEST IN PROPER TIME
            for (int k = 0; k < printerNo; k++){
                if ( printers[0][k] == 0 && !PQ.pqIsEmpty()) // meaning that the current printer is empty and there is a request waiting!
                {
                    tAvg = tAvg + (t - PQ.peek().getRequestTime());
                    printers[0][k] = 1; // it is full now
                    printers[1][k] = t + PQ.peek().getProcessTime() -1; // keep completion time of request
                    PQ.pqDelete(); // remove request from waiting list
                    leftToPrint--;
                }
            }

            // 3) EMPTY PRINTERS AT PROPER TIME
            for (int k = 0; k < printerNo; k++){
                // If process is over make printer usable again by toggleing
                if ( printers[1][k] == t){
                    printers[0][k] = 0; // usable again
                    printers[1][k] = 0; // self defense
                }
            }
            t++; // time increases
    }

    tAvg = tAvg / totalRequests;

    // DEALLOC PRINTER ARRAY
    for(int g = 0; g < 2; ++g) {
    delete [] printers[g];
    }
    delete [] printers;

    return tAvg;

}


void simulator::display(Request *& requests, const int totalRequests, const int desiredMAXAvgTime, const int printerNo ){
    cout << "Minimum number of printers required: " << printerNo << endl;
    cout << endl;
    cout << "Simulation with " << printerNo << " printers:" << endl;
    cout << endl;

    // FIRST DECLARE A 2D ARRAY WITH "printerNo" SIZE TO "MIMIC" THE PRINTERS WHERE EACH COLUMN REPRESENTS A PRINTER
    // ROW 1: CHECKS WHETHER THE PRINTER IS USED AT CURRENT TIME OR NOT, RETURNS 1 IF USED, ELSE OTHERWISE
    // ROW 2: KEEPS THE TIME PRINTER IS DONE WITH CURRENT REQUEST
    int **printers = new int* [2];
    for(int j = 0; j < 2; ++j) {
        printers[j] = new int[printerNo];
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < printerNo; j++)
        {
             printers[i][j] = 0;
        }
    }

    int i = 0; // to go through array
    int t = 0; // time in seconds
    double tAvg = 0; // AVERAGE TIME

    int leftToPrint = totalRequests;

    while ( leftToPrint != 0 ){
            // 1) COPY THE REQUESTS SENT IN GIVEN TIME
            for (; i < totalRequests && t >= requests[i].getRequestTime() ; i++){
                if (requests[i].getRequestTime() == t)
                    PQ.pqInsert(requests[i]); // if we find request sent in given time we add it to the PQ
            }

            // 2) CHECK PRINTERS AND SEND REQUEST IN PROPER TIME
            for (int k = 0; k < printerNo; k++){
                if ( printers[0][k] == 0 && !PQ.pqIsEmpty()) // meaning that current printer is empty and there is a waiting request!
                {
                    cout << "Printer " << k << " prints print request " << PQ.peek().getRequestNo()
                    << " at minute " << t << " (wait: " << t - PQ.peek().getRequestTime() << " mins)" << endl;

                    tAvg = tAvg + (t - PQ.peek().getRequestTime());
                    printers[0][k] = 1; // it is full now
                    printers[1][k] = t + PQ.peek().getProcessTime() -1; // keep completion time of request
                    PQ.pqDelete(); // remove request from wait list
                    leftToPrint--;
                }
            }

            // 3) EMPTY PRINTERS AT PROPER TIME
            for (int k = 0; k < printerNo; k++){
                // If process is over make printer usable again by toggleing
                if ( printers[1][k] == t){
                    printers[0][k] = 0; // usable again
                    printers[1][k] = 0; // self defense
                }
            }
            t++;
    }

    tAvg = tAvg / totalRequests;

    // DEALLOC PRINTER ARRAY
    for(int g = 0; g < 2; ++g) {
    delete [] printers[g];
    }
    delete [] printers;
    cout << endl;
    cout << "Average waiting time: " << tAvg << " minutes"   << endl;
}
