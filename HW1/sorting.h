/*
* Title: Sorting and Algorithm Efficiency
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 1
* Description: Declaration of "sorting" class having 4 different sorting algorithms
*/
#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
class sorting
{
    public:
    sorting();
    void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void radixSort(int *arr, const int size);

    // helpers of selectionSort
    int indexLargest( const int *arr, int size, int &compCount);
    void swapItem( int &x, int &y, int &moveCount);

    //helpers of mergeSort
    void mergeSort(int *arr, const int size, int first, int last, int &compCount, int &moveCount);
    void mergeHalves(int *arr, const int size,int first, int midPoint, int last, int &compCount, int &moveCount );

    // helpers of quickSort
    void quickSort(int *arr, const int size, int first, int last, int &compCount, int &moveCount);
    void partitionCreate( int *arr, const int size, int first, int last, int &pivotI, int &compCount, int &moveCount);

    int indexSmallest( const int *arr, int size);

    protected:

    private:
};

#endif // SORTING_H
