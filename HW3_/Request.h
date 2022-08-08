/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Declaration of Request class & its functions
*/
#ifndef REQUEST_H
#define REQUEST_H


class Request
{
    public:
        // const 1 & 2
        Request();
        Request(int rNo, int pNo, int rTime, int pTime);

        // SETTER FUNCTIONS
        void setRequestNo(int rNo);
        void setPriorityNo(int pNo);
        void setRequestTime(int rTime);
        void setProcessTime(int pTime);

        // GETTER FUNCTIONS
        int getRequestNo();
        int getPriorityNo();
        int getRequestTime();
        int getProcessTime();

    protected:

    private:
        int requestNo; // Unique request number
        int priorityNo; // Priority value of request
        int requestTime; // The time that request is sent
        int processTime; // The time it takes to complete request
};

#endif // REQUEST_H
