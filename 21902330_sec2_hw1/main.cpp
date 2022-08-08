/*
* Title: Sorting and Algorithm Efficiency
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 1
* Description: main function to demonstrate the sorting algorithms
*/
#include <iostream>
#include "sorting.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

void displayArray(const int* , const int);
void createRandomArrays(int *&, int *&, int *&, int *&, const int size);
void createAscendingArrays(int *&, int *&, int *&, int *&, const int size);
void createDescendingArrays(int *&, int *&, int *&, int *&, const int size);
void performanceAnalysis(sorting);

using namespace std;

int main()
{
    sorting s;
    int comps = 0;
    int moves = 0;

    int arr[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    const int arrSize = 16;
    cout << "The array before selection sort: " << endl;
    displayArray(arr , arrSize);
    s.selectionSort(arr, arrSize, comps, moves);
    cout << endl;
    cout << "comp num is: " << comps <<  endl;
    cout << "move num is: " << moves <<  endl;
    cout << "The array after selection sort: " << endl;
    displayArray(arr , arrSize);

    cout << endl;
    cout << endl;
    int arrMs[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    cout << "The array before merge sort: " << endl;
    displayArray(arrMs , arrSize);
    comps = 0;
    moves = 0;
    s.mergeSort(arrMs, arrSize, comps, moves);
    cout << endl;
    cout << "comp num is: " << comps <<  endl;
    cout << "move num is: " << moves <<  endl;
    cout << "The array after merge sort: " << endl;
    displayArray(arrMs , arrSize);

    cout << endl;
    cout << endl;
    int arrQs[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    cout << "The array before quick sort: " << endl;
    displayArray(arrQs , arrSize);
    comps = 0;
    moves = 0;
    s.quickSort(arrQs, arrSize, comps, moves);
    cout << endl;
    cout << "comp num is: " << comps <<  endl;
    cout << "move num is: " << moves <<  endl;
    cout << "The array after quick sort: " << endl;
    displayArray(arrQs , arrSize);
    cout << endl;
    cout << endl;
    int arrRs[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    cout << "The array before radix sort: " << endl;
    displayArray(arrRs , arrSize);
    s.quickSort(arrRs, arrSize, comps, moves);
    cout << endl;
    cout << "The array after radix sort: " << endl;
    displayArray(arrRs , arrSize);

    cout << endl;
    cout << endl;
    cout << "THE ANALYSIS IS BEING DONE. PLEASE WAIT..." << endl;
    performanceAnalysis(s);

    return 0;
}
