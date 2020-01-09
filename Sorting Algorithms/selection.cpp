/*************************************************************************************************************************
* SELECTION SORT                                                                                                         *
*                                                                                                                        *
* ADAPTIVE: true                                                                                                         *
* STABLE: true                                                                                                           *
* Insertion sort is stable since it does not shift the element if it is equal.                                           *
* COMPLEXITY: O(n²)
* NUMBER OF COMPARISONS: 
* NUMBER OF SWAPS:                                                                                                       *
* ASSUMPTION: For insertion sort, we assume that the first element is already in sorted order                            *
*************************************************************************************************************************/

#include <iostream>

void selection (int A[], int size) {
    for (int i = 0; i < size; i++) {
        int j = i+1, k = i, temp;
        while (j < size) {
            //is j less than i
            if (A[j] < A[k])
                k = j;
            j++;
        }
        //swap places of k and i
        temp = A[k];
        A[k] = A[i];
        A[i] = temp;
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
    selection (A, size);
    return 0;
}