/*************************************************************************************************************************
* COUNT SORT                                                                                                         *
*************************************************************************************************************************/

#include <iostream>

int findMax (int A[], int size) {
    int max = 0;

    for (int i=0; i<size; i++) {
        if (A[i] > max)
            max = A[i];
    }
    
    return max;
}

void count (int A[], int size) {
    int max, *C;

    //find the largest element in the array
    max = findMax (A, size);

    //declare array of size equal to largest element
    C = new int[max + 1];

    //populate the array with zeroes
    for (int i=0; i < max + 1; i++)
        C[i] = 0;

    for (int i=0; i<size; i++)
        C[A[i]]++;

    int j = 0;
    for (int i=0; i < max + 1; i++) {
        if (C[i] != 0) {
            int times = C[i];
            while (times--)
                A[j++] = i;
        }
    }
}


int main () {
    int size;
    std :: cin >> size;
    int A[100];

    for (int i = 0; i < size; i++)
        std :: cin >> A[i];

    count (A, size);

    for (int i = 0; i < size; i++)
    std :: cout << A[i];

    return 0;
}