/*************************************************************************************************************************
* MERGE SORT                                                                                                         *
*                                                                                                                        *
* ADAPTIVE: False. Even if list is sorted, the algorithm would take the same time.                                       *
* STABLE: False. It does not preserve the order of elements.                                                             *
* COMPLEXITY: O(nlogn)                                                                                                      *
* NUMBER OF COMPARISONS:                                                                                                 *
* NUMBER OF SWAPS: n - 1                                                                                                 *
* INTERMEDIATE STEP: Intermediate steps are useful as k steps would give k smallest elements.                            *
* Selection sort is the only sorting technique with the least number of swaps.                                           *
*************************************************************************************************************************/
//M-way merging
//iterative and recursive merge sort
#include <iostream>

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid+1, k = l;
    int arr[100];
    while (i < mid+1 && j < h+1) {
        if (A[i] < A[j])
            arr[k++] = A[i++];
        else
            arr[k++] = A[j++];
    }
    while (j < h+1)
        arr[k++] = A[j++];
    while (i < mid+1)
        arr[k++] = A[i++];
    for (int p = 0; p < h+1; p++)
        A[p] = arr[p]; //fill the sorted elements back into the original array
}


void mergesort (int A[], int l, int h) {
    if (l < h) { //base case for recursion to end, this checks whether the array contains one element or not
        int mid = l + (h - l)/2; //to avoid integer overflow
        mergesort (A, l, mid);
        mergesort (A, mid+1, h);
        merge (A, l, mid, h);
    } 
}

int main () {
    int size;
    std :: cin >> size;
    int A[100];
    for (int i = 0; i < size; i++)
        std :: cin >> A[i];
    
    mergesort (A, 0, size-1);
    for (int i = 0; i < size; i++)
        std :: cout << A[i];
    return 0;
}