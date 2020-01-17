/**************************************************************************************************************************
* QUICK SORT                                                                                                              *
*                                                                                                                         *
* ADAPTIVE: False. Even if list is sorted, the algorithm would take the same time.                                        *
* STABLE: False. It does not preserve the order of elements.                                                              *
* TIME COMPLEXITY: O(nlogn)  => BEST CASE                                                                                 *
*                  O(n²) => WORST CASE, when pivot is the extreme element                                                 *
* INTERMEDIATE STEP: Not useful as the array is fully sorted only at the end of the recursion                             *
* ONE LINE (not really) EXPLANATION: Tries to collect all elements smaller than the pivot at one end of the array and     *
* elements bigger than the pivot to the opposite end and then the pivot is "inserted" (actually swapped) after the  index *
* where the consolidation of smaller elements ends. Two new sub-arrays are now formed and the same thing happens all over *
* again on the subarrays                                                                                                  *
**************************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <random>

void swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int A[], int start, int end) {
    int i = start-1, j = start;
    //choose a random pivot 
    //REFERENCE: https://stackoverflow.com/a/7560564/10816572
    std :: random_device rd; // obtain a random number from hardware
    std :: mt19937 eng (rd()); // seed the generator
    std :: uniform_int_distribution <> distr (start, end); // define the range

    for (;j < end; j++) {
        if (A[j] < A[end]) {
            i++;
            //swap the values that were found out to be smaller than our lovely pivot
            swap (&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[j]);
    return (i+1);
}

void quicksort (int A[], int start, int end) {
    int pivot;

    if (start >= end) {
        return;
    }
    //first partition the list
    pivot = partition (A, start, end);
    //then send the sublists for partioning
    quicksort (A, start, pivot-1);
    quicksort (A, pivot, end);
}

int main () {
    int size, A[100];
    std :: cin >> size;
    
    //accept values for the array
    for (int i = 0; i < size; i++)
        std :: cin >> A[i];
    quicksort (A, 0, size-1);
    //display the array
    for (int i = 0; i < size; i++)
        std :: cout << A[i];
    return 0;
}