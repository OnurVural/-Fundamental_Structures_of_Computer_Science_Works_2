/*
* Title: Sorting and Algorithm Efficiency
* Author: N.Onur VURAL
* ID: 21902330
* Section: 2
* Assignment: 1
* Description: Implementation of "sorting" class having 4 different sorting algorithms
*/
#include "sorting.h"

sorting::sorting()
{
}
void sorting::selectionSort(int *arr, const int size, int &compCount, int &moveCount){
    for ( int last = size - 1; last >= 1; --last ){
        int maximum = indexLargest( arr, last + 1, compCount); // find maximum to swap
        swapItem(arr[maximum], arr[last], moveCount );
    }
}

int sorting::indexLargest( const int *arr, int size, int &compCount){
    int indexSoFar = 0;
    for ( int currentIndex = 1; currentIndex < size; ++currentIndex){
        compCount++; // each iteration means new comparison
        if (arr[currentIndex] > arr[indexSoFar]){
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar;
}

int sorting::indexSmallest( const int *arr, int size){
    int indexSoFar = 0;
    for ( int currentIndex = 1; currentIndex < size; ++currentIndex){
        if (arr[currentIndex] < arr[indexSoFar]){
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar;
}

void sorting::swapItem( int &x, int &y, int &moveCount){
        int temp = x;
        x = y;
        y = temp;
        moveCount = moveCount + 3; // as it takes 3 moves for swap operation
}

void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    // call the helper funct
    mergeSort(arr, size, 0, size-1, compCount, moveCount);
}

void sorting::mergeSort(int *arr, const int size, int first, int last, int &compCount, int &moveCount){
    if ( first < last ){
        int midPoint = (first + last)/2;

        // divide & conquer method recursion
        mergeSort(arr, size, first,  midPoint, compCount, moveCount); // first half
        mergeSort(arr, size, midPoint + 1, last, compCount, moveCount); // second half
        // combine two halves
        mergeHalves(arr, size, first,  midPoint, last, compCount, moveCount );

    }
}
void sorting::mergeHalves(int *arr, const int size, int first, int midPoint, int last, int &compCount, int &moveCount ){
    int tempArr[size];

    int start1 = first;
    int end1 = midPoint;
    int start2 = midPoint + 1;
    int end2 = last;
    int i = start1; // current index

    for (; (start1 <= end1) && (start2 <= end2); ++i){

        if ( arr[start1] < arr[start2]){
                tempArr[i] = arr[start1];
                ++start1; ++moveCount;
                //----
        }
        else{
                tempArr[i] = arr[start2];
                ++start2; ++moveCount;
                //--------------

        }
        ++compCount;

    }

    //copy remainding in first arr
    for ( ; start1 <= end1; ++start1, ++i){
            tempArr[i] = arr[start1]; ++moveCount;
    }

    for ( ; start2 <= end2; ++start2, ++i){
            tempArr[i] = arr[start2]; ++moveCount;
    }

    // transfer to original arr
    for ( i = first; i <= last; ++i){
        arr[i] = tempArr[i]; ++moveCount;
    }

}

void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount){
    quickSort(arr, size, 0, size - 1, compCount, moveCount);
}

void sorting::quickSort(int *arr, const int size, int first, int last, int &compCount, int &moveCount){
    int pivotI; // the index of pivot;

    if ( first < last ){

        partitionCreate( arr, size, first, last, pivotI, compCount, moveCount);

        quickSort(arr, size, first, pivotI -1, compCount, moveCount);
        quickSort(arr, size, pivotI + 1, last, compCount, moveCount);
    }

}

void sorting::partitionCreate( int *arr, const int size, int first, int last, int &pivotI, int &compCount, int &moveCount){
    int pivot = arr[first];
    moveCount++;

    int lastS1 = first;
    int firstOfUnknowns = first + 1;

    for (; firstOfUnknowns <= last; ++firstOfUnknowns){

        if ( arr[firstOfUnknowns] < pivot){
        ++lastS1;
        swapItem(arr[firstOfUnknowns], arr[lastS1], moveCount);
        }
        ++compCount;
    }

    swapItem(arr[first], arr[lastS1], moveCount);
    pivotI = lastS1;
}

void sorting::radixSort(int *arr, const int size){

    int  finalArrayIndex, current;
    //first we need to find the largest element to determine the digits to go through
    int maximum = arr[0];
    for ( int i = 1; i < size; i++){
        if (arr[i] > maximum) // sequential search
            maximum = arr[i];
    }

    int d = 0; // the digit

    while ( int(maximum != 0)){
        maximum = maximum / 10;
        d++;
    }
    // sort n d-digit integers in arr
    for ( int j = 0; j < d; j++){
        int groups[10][size]; // init 10 groups according to the digits
        int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // to keep digit occurene record
        for (int i = 0; i < size; i++){
            current = ((int)(arr[i]/pow(10, j)))%10; // jth digit of arr
            groups[ current ][counter[current]] = arr[i]; // place arr[i] at the end of group current
            counter[current] = counter[current] + 1; // increase current counter corresponding current digit
        }

        //replace arr with all items in group0 to group10
        finalArrayIndex = 0;
        for (int group = 0; group < 10; group++) {
            // we need to check the counter to see how many items must be obtained for each group
            for (int counterCheck = 0; counterCheck < counter[group]; counterCheck++)
            {
                arr[finalArrayIndex] = groups[group][counterCheck];
                finalArrayIndex++;
            }
        }

    }
}

void displayArray(const int *arr, const int size){
    for ( int i = 0; i < size; i++)
        cout << arr[i] << ", " ;
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int * a = new int[size];

    for( int i = 0; i < size; i++ )
        a[i] = rand();
    for( int i = 0; i < size; i++ ){
            arr1[i] = a[i];
            arr2[i] = a[i];
            arr3[i] = a[i];
            arr4[i] = a[i];
    }
    delete [] a;
}


void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
    int * a = new int[size];

    //createRandomArrays(arr1, arr2, arr3, arr4, size);
    for( int i = 0; i < size; i++ )
        a[i] = rand();

    //sort(a, a + size);
    for ( int i = 0; i < size - 1; i++){
        int minimumIndex = i;
        for (int j = i + 1; j < size; j++){
            if (a[j] < a[minimumIndex])
                    minimumIndex = j;
        }
        int temp = a[minimumIndex];
        a[minimumIndex] = a[i];
        a[i] = temp;
    }


    for( int i = 0; i < size; i++ ){
            arr1[i] = a[i];
            arr2[i] = a[i];
            arr3[i] = a[i];
            arr4[i] = a[i];
    }
    delete [] a;
}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size){
int * a = new int[size];
    for( int i = 0; i < size; i++ )
        a[i] = rand();

    //sort(a, a + size);
    for ( int i = 0; i < size - 1; i++){
        int maxIndex = i;
        for (int j = i + 1; j < size; j++){
            if (a[j] > a[maxIndex])
                    maxIndex = j;
        }
        int temp = a[maxIndex];
        a[maxIndex] = a[i];
        a[i] = temp;
    }


    for( int i = 0; i < size; i++ ){
            arr1[i] = a[i];
            arr2[i] = a[i];
            arr3[i] = a[i];
            arr4[i] = a[i];
    }
    delete [] a;

}

void performanceAnalysis(sorting s){
    const int size1 = 6000;
    const int size2 = 10000;
    const int size3 = 14000;
    const int size4 = 18000;
    const int size5 = 22000;
    const int size6 = 26000;
    const int size7 = 30000;

    int dataNum[] = {6000, 10000, 14000, 18000, 22000, 26000, 30000 };

    int compCount = 0;
    int moveCount = 0;
    int *arr1 = new int[size1];
    int *arr2 = new int[size1];
    int *arr3 = new int[size1];
    int *arr4 = new int[size1];

    int arrDataSS[7][9]; //randomized, ascending and descending data
    int arrDataMS[7][9];
    int arrDataQS[7][9];
    int arrDataRS[7][3];


    createRandomArrays(arr1, arr2, arr3, arr4, size1);
    //Store the starting time
    double duration;
    clock_t startTime = clock();
    //Code block
    s.selectionSort(arr1, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    //cout << "            " << duration << " milliseconds." << endl;
    arrDataSS[0][0] = duration;
    arrDataSS[0][1] = compCount;
    arrDataSS[0][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[0][0] = duration;
    arrDataMS[0][1] = compCount;
    arrDataMS[0][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[0][0] = duration;
    arrDataQS[0][1] = compCount;
    arrDataQS[0][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size1 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[0][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size1];
    arr2 = new int[size1];
    arr3 = new int[size1];
    arr4 = new int[size1];
    createAscendingArrays(arr1, arr2, arr3, arr4, size1);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[0][3] = duration;
    arrDataSS[0][4] = compCount;
    arrDataSS[0][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[0][3] = duration;
    arrDataMS[0][4] = compCount;
    arrDataMS[0][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[0][3] = duration;
    arrDataQS[0][4] = compCount;
    arrDataQS[0][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size1 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[0][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size1];
    arr2 = new int[size1];
    arr3 = new int[size1];
    arr4 = new int[size1];
    createDescendingArrays(arr1, arr2, arr3, arr4, size1);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[0][6] = duration;
    arrDataSS[0][7] = compCount;
    arrDataSS[0][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[0][6] = duration;
    arrDataMS[0][7] = compCount;
    arrDataMS[0][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size1, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[0][6] = duration;
    arrDataQS[0][7] = compCount;
    arrDataQS[0][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size1 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[0][2] = duration;

    delete []arr4;
    //---------------FOR SIZE 10000------------------------------------------
    arr1 = new int[size2];
    arr2 = new int[size2];
    arr3 = new int[size2];
    arr4 = new int[size2];
    createRandomArrays(arr1, arr2, arr3, arr4, size2);

    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[1][0] = duration;
    arrDataSS[1][1] = compCount;
    arrDataSS[1][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[1][0] = duration;
    arrDataMS[1][1] = compCount;
    arrDataMS[1][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[1][0] = duration;
    arrDataQS[1][1] = compCount;
    arrDataQS[1][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size2 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[1][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size2];
    arr2 = new int[size2];
    arr3 = new int[size2];
    arr4 = new int[size2];
    createAscendingArrays(arr1, arr2, arr3, arr4, size2);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[1][3] = duration;
    arrDataSS[1][4] = compCount;
    arrDataSS[1][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[1][3] = duration;
    arrDataMS[1][4] = compCount;
    arrDataMS[1][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[1][3] = duration;
    arrDataQS[1][4] = compCount;
    arrDataQS[1][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size2 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[1][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size2];
    arr2 = new int[size2];
    arr3 = new int[size2];
    arr4 = new int[size2];
    createDescendingArrays(arr1, arr2, arr3, arr4, size2);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[1][6] = duration;
    arrDataSS[1][7] = compCount;
    arrDataSS[1][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[1][6] = duration;
    arrDataMS[1][7] = compCount;
    arrDataMS[1][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size2, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[1][6] = duration;
    arrDataQS[1][7] = compCount;
    arrDataQS[1][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size2 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[1][2] = duration;

    delete []arr4;

    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //---------------FOR SIZE 14000------------------------------------------
    arr1 = new int[size3];
    arr2 = new int[size3];
    arr3 = new int[size3];
    arr4 = new int[size3];
    createRandomArrays(arr1, arr2, arr3, arr4, size3);

    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[2][0] = duration;
    arrDataSS[2][1] = compCount;
    arrDataSS[2][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[2][0] = duration;
    arrDataMS[2][1] = compCount;
    arrDataMS[2][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[2][0] = duration;
    arrDataQS[2][1] = compCount;
    arrDataQS[2][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size3 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[2][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size3];
    arr2 = new int[size3];
    arr3 = new int[size3];
    arr4 = new int[size3];
    createAscendingArrays(arr1, arr2, arr3, arr4, size3);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[2][3] = duration;
    arrDataSS[2][4] = compCount;
    arrDataSS[2][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[2][3] = duration;
    arrDataMS[2][4] = compCount;
    arrDataMS[2][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[2][3] = duration;
    arrDataQS[2][4] = compCount;
    arrDataQS[2][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size3 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[2][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size3];
    arr2 = new int[size3];
    arr3 = new int[size3];
    arr4 = new int[size3];
    createDescendingArrays(arr1, arr2, arr3, arr4, size3);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[2][6] = duration;
    arrDataSS[2][7] = compCount;
    arrDataSS[2][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[2][6] = duration;
    arrDataMS[2][7] = compCount;
    arrDataMS[2][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size3, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[2][6] = duration;
    arrDataQS[2][7] = compCount;
    arrDataQS[2][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size3 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[2][2] = duration;

    delete []arr4;

    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //---------------FOR SIZE 18000------------------------------------------
    arr1 = new int[size4];
    arr2 = new int[size4];
    arr3 = new int[size4];
    arr4 = new int[size4];
    createRandomArrays(arr1, arr2, arr3, arr4, size4);

    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[3][0] = duration;
    arrDataSS[3][1] = compCount;
    arrDataSS[3][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[3][0] = duration;
    arrDataMS[3][1] = compCount;
    arrDataMS[3][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[3][0] = duration;
    arrDataQS[3][1] = compCount;
    arrDataQS[3][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size4 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[3][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size4];
    arr2 = new int[size4];
    arr3 = new int[size4];
    arr4 = new int[size4];
    createAscendingArrays(arr1, arr2, arr3, arr4, size4);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[3][3] = duration;
    arrDataSS[3][4] = compCount;
    arrDataSS[3][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[3][3] = duration;
    arrDataMS[3][4] = compCount;
    arrDataMS[3][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[3][3] = duration;
    arrDataQS[3][4] = compCount;
    arrDataQS[3][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size4 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[3][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size4];
    arr2 = new int[size4];
    arr3 = new int[size4];
    arr4 = new int[size4];
    createDescendingArrays(arr1, arr2, arr3, arr4, size4);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[3][6] = duration;
    arrDataSS[3][7] = compCount;
    arrDataSS[3][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[3][6] = duration;
    arrDataMS[3][7] = compCount;
    arrDataMS[3][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size4, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[3][6] = duration;
    arrDataQS[3][7] = compCount;
    arrDataQS[3][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size4 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[3][2] = duration;

    delete []arr4;

    //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    //---------------FOR SIZE 22000------------------------------------------
    arr1 = new int[size5];
    arr2 = new int[size5];
    arr3 = new int[size5];
    arr4 = new int[size5];
    createRandomArrays(arr1, arr2, arr3, arr4, size5);

    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[4][0] = duration;
    arrDataSS[4][1] = compCount;
    arrDataSS[4][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[4][0] = duration;
    arrDataMS[4][1] = compCount;
    arrDataMS[4][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[4][0] = duration;
    arrDataQS[4][1] = compCount;
    arrDataQS[4][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size5 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[4][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size5];
    arr2 = new int[size5];
    arr3 = new int[size5];
    arr4 = new int[size5];
    createAscendingArrays(arr1, arr2, arr3, arr4, size5);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[4][3] = duration;
    arrDataSS[4][4] = compCount;
    arrDataSS[4][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[4][3] = duration;
    arrDataMS[4][4] = compCount;
    arrDataMS[4][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[4][3] = duration;
    arrDataQS[4][4] = compCount;
    arrDataQS[4][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size5 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[4][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size5];
    arr2 = new int[size5];
    arr3 = new int[size5];
    arr4 = new int[size5];
    createDescendingArrays(arr1, arr2, arr3, arr4, size5);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[4][6] = duration;
    arrDataSS[4][7] = compCount;
    arrDataSS[4][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[4][6] = duration;
    arrDataMS[4][7] = compCount;
    arrDataMS[4][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size5, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[4][6] = duration;
    arrDataQS[4][7] = compCount;
    arrDataQS[4][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size5 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[4][2] = duration;

    delete []arr4;
    //---------------FOR SIZE 26000------------------------------------------
    arr1 = new int[size6];
    arr2 = new int[size6];
    arr3 = new int[size6];
    arr4 = new int[size6];
    createRandomArrays(arr1, arr2, arr3, arr4, size6);

    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[5][0] = duration;
    arrDataSS[5][1] = compCount;
    arrDataSS[5][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[5][0] = duration;
    arrDataMS[5][1] = compCount;
    arrDataMS[5][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[5][0] = duration;
    arrDataQS[5][1] = compCount;
    arrDataQS[5][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size6 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[5][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size6];
    arr2 = new int[size6];
    arr3 = new int[size6];
    arr4 = new int[size6];
    createAscendingArrays(arr1, arr2, arr3, arr4, size6);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[5][3] = duration;
    arrDataSS[5][4] = compCount;
    arrDataSS[5][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[5][3] = duration;
    arrDataMS[5][4] = compCount;
    arrDataMS[5][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[5][3] = duration;
    arrDataQS[5][4] = compCount;
    arrDataQS[5][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size6 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[5][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size6];
    arr2 = new int[size6];
    arr3 = new int[size6];
    arr4 = new int[size6];
    createDescendingArrays(arr1, arr2, arr3, arr4, size6);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[5][6] = duration;
    arrDataSS[5][7] = compCount;
    arrDataSS[5][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[5][6] = duration;
    arrDataMS[5][7] = compCount;
    arrDataMS[5][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size6, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[5][6] = duration;
    arrDataQS[5][7] = compCount;
    arrDataQS[5][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size6 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[5][2] = duration;

    delete []arr4;

    //---------------FOR SIZE 30000------------------------------------------
    arr1 = new int[size7];
    arr2 = new int[size7];
    arr3 = new int[size7];
    arr4 = new int[size7];
    createRandomArrays(arr1, arr2, arr3, arr4, size7);

    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[6][0] = duration;
    arrDataSS[6][1] = compCount;
    arrDataSS[6][2] = moveCount;

    delete []arr1;
    //----------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[6][0] = duration;
    arrDataMS[6][1] = compCount;
    arrDataMS[6][2] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[6][0] = duration;
    arrDataQS[6][1] = compCount;
    arrDataQS[6][2] = moveCount;

    delete []arr3;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.radixSort(arr4, size7 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[6][0] = duration;

    delete []arr4;
    //-------------------------------------------------



    arr1 = new int[size7];
    arr2 = new int[size7];
    arr3 = new int[size7];
    arr4 = new int[size7];
    createAscendingArrays(arr1, arr2, arr3, arr4, size7);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[6][3] = duration;
    arrDataSS[6][4] = compCount;
    arrDataSS[6][5] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[6][3] = duration;
    arrDataMS[6][4] = compCount;
    arrDataMS[6][5] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[6][3] = duration;
    arrDataQS[6][4] = compCount;
    arrDataQS[6][5] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size7 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[6][1] = duration;

    delete []arr4;
     //-------------------------------------------------



    arr1 = new int[size7];
    arr2 = new int[size7];
    arr3 = new int[size7];
    arr4 = new int[size7];
    createDescendingArrays(arr1, arr2, arr3, arr4, size7);
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.selectionSort(arr1, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataSS[6][6] = duration;
    arrDataSS[6][7] = compCount;
    arrDataSS[6][8] = moveCount;

    delete []arr1;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.mergeSort(arr2, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataMS[6][6] = duration;
    arrDataMS[6][7] = compCount;
    arrDataMS[6][8] = moveCount;

    delete []arr2;
    //--------------------------------------------------
    compCount = 0;
    moveCount = 0;

    startTime = clock();
    //Code block
    s.quickSort(arr3, size7, compCount, moveCount);
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataQS[6][6] = duration;
    arrDataQS[6][7] = compCount;
    arrDataQS[6][8] = moveCount;

    delete []arr3;
    //----------------------------------------------------------------
    startTime = clock();
    //Code block
    s.radixSort(arr4, size7 );
    //Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    arrDataRS[6][2] = duration;

    delete []arr4;
    //----------------------------------------------------------------

    cout << "Analysis of Selection Sort" << endl;
    cout << "-Array Size-     -Elapsed Time-      -compCount-   -moveCount- " << endl;

    cout << "Randomized Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataSS[i][0] << "ms              ";
            cout << arrDataSS[i][1] << "      ";
            cout << arrDataSS[i][2] << "    ";
            cout << endl;
    }

    cout << "Ascending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataSS[i][3] << "ms              ";
            cout << arrDataSS[i][4] << "      ";
            cout << arrDataSS[i][5] << "    ";
            cout << endl;
    }
    cout << "Descending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataSS[i][6] << "ms              ";
            cout << arrDataSS[i][7] << "      ";
            cout << arrDataSS[i][8] << "    ";
            cout << endl;
    }
    cout << "------------------------------------------------------------" <<  endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "-Array Size-     -Elapsed Time-      -compCount-   -moveCount- " << endl;
    cout << "Randomized Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataMS[i][0] << "ms              ";
            cout << arrDataMS[i][1] << "      ";
            cout << arrDataMS[i][2] << "    ";
            cout << endl;
    }

    cout << "Ascending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataMS[i][3] << "ms              ";
            cout << arrDataMS[i][4] << "      ";
            cout << arrDataMS[i][5] << "    ";
            cout << endl;
    }
    cout << "Descending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataMS[i][6] << "ms              ";
            cout << arrDataMS[i][7] << "      ";
            cout << arrDataMS[i][8] << "    ";
            cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    cout << "Analysis of Quick Sort" << endl;
    cout << "-Array Size-     -Elapsed Time-      -compCount-   -moveCount- " << endl;
    cout << "Randomized Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataQS[i][0] << "ms              ";
            cout << arrDataQS[i][1] << "      ";
            cout << arrDataQS[i][2] << "    ";
            cout << endl;
    }

    cout << "Ascending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataQS[i][3] << "ms              ";
            cout << arrDataQS[i][4] << "      ";
            cout << arrDataQS[i][5] << "    ";
            cout << endl;
    }
    cout << "Descending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataQS[i][6] << "ms              ";
            cout << arrDataQS[i][7] << "      ";
            cout << arrDataQS[i][8] << "    ";
            cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    cout << "Analysis of Radix Sort" << endl;
    cout << "-Array Size-     -Elapsed Time- " << endl;
    cout << "Randomized Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataRS[i][0] << "ms              ";
            cout << endl;
    }

    cout << "Ascending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataRS[i][1] << "ms              ";
            cout << endl;
    }
    cout << "Descending Inputs: " << endl;
    for ( int i = 0; i < 7; i++){
            cout << dataNum[i] << "               ";
            cout << arrDataRS[i][2] << "ms              ";
            cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;




}
