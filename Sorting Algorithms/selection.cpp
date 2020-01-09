/*************************************************************************************************************************
* SELECTION SORT                                                                                                         *
*                                                                                                                        *
* ADAPTIVE: false. Even if list is sorted, the algorithm would take the same time.                                       *
* STABLE: false, it does not preserve the order of elements                                                              *
* COMPLEXITY: O(n²)                                                                                                      *
* NUMBER OF COMPARISONS:                                                                                                 *
* NUMBER OF SWAPS:                                                                                                       *
* INTERMEDIATE STEP: Intermediate steps are useful as k steps would give k smallest elements.                            *
* Selection sort is the only sorting technique with the least number of swaps                                            *
*************************************************************************************************************************/

#include <iostream>

void selection (int A[], int size) {
    for (int i = 0; i < size; i++) {
        int j = i+1, k = i, temp;
        while (j < size) {
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