/*******************************************************************************************************************
* INSERTION SORT                                                                                                    *
*                                                                                                                   *
* ADAPTIVE: true                                                                                                    *
* Bubble sort is not adaptive by nature. But it can be converted to an adaptive algorithm using a flag variable.    *
* STABLE: true                                                                                                      *
* Bubble sort is stable since it does not interchange the places of originial elements. It performs a swap only     *
* when needed.                                                                                                      *
* COMPLEXITY: O(n²)                                                                                                 *
* ASSUMPTION: For insertion sort, we assume that the first element is already in sorted order                       *
********************************************************************************************************************/

#include <iostream>

void insertion (int A[], int size) {
    int temp = 0;
    for (int i=1; i<size-1; i++) {
        for (int j=i-1; j>-1; j--) {
            if (A[j] > A[j+1]) {
                temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }
    }
    for (int k = 0; k < size; k++)
        std :: cout << A[k];
}

int main () {
    int size;
    std :: cin >> size;
    int A[100];
    for (int i = 0; i < size; i++)
        std :: cin >> A[i];
    insertion (A, size);
    return 0;
}