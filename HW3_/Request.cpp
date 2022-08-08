/*
* Title: Heaps
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 3
* Description: Implementation of Request class & its functions
*/
#include "Request.h"
        // EMPTY CONSTRUCTOR: C1
        Request::Request()
        {
            //ctor
        }

        // CONSTRUCTOR: C2
        Request::Request(int rNo, int pNo, int rTime, int pTime){
            requestNo = rNo;
            priorityNo = pNo;
            requestTime = rTime;
            processTime = pTime;

        }

        // SIMPLE SETTER FUNCTIONS
        void Request::setRequestNo(int rNo){
            requestNo = rNo;
        }
        void Request::setPriorityNo(int pNo){
            priorityNo = pNo;
        }
        void Request::setRequestTime(int rTime){
            requestTime = rTime;
        }
        void Request::setProcessTime(int pTime){
            processTime = pTime;
        }

        // SIMPLE GETTER FUNCTIONS
        int Request::getRequestNo(){
            return requestNo;
        }
        int Request::getPriorityNo(){
            return priorityNo;
        }
        int Request::getRequestTime(){
            return requestTime;
        }
        int Request::getProcessTime(){
            return processTime;
        }
