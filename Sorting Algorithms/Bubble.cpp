/*******************************************************************************************************************
* BUBBLE SORT                                                                                                      *
*                                                                                                                  *
* ADAPTIVE: true                                                                                                   *
* Bubble sort is not adaptive by nature. But it can be converted to an adaptive algorithm using a flag variable.   *
* STABLE: true                                                                                                     *
* Bubble sort is stable since it does not interchange the places of originial elements. It performs a swap only    *
* when needed.                                                                                                     *
*******************************************************************************************************************/

#include <iostream>

void bubble (int A[], int size) {
    int temp = 0, flag = 0;
    for (int i=0; i<size-1; i++) {
        //for every one iteration of i (pass) that gets completed, one element gets sorted, hence one comparison reduces.
        for (int j=0; j<size-1-i; j++) {
            if (A[j] > A[j+1]) {
                flag = 1;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
            //if swapping was not done for any two numbers in the current iteration, the flag remains zero
            //this means the array is sorted
        }
        if (flag == 0)
            break;
    }
    for (int k = 0; k < size; k++)
        std :: cout << A[k];
}

int main () {
    int size;
    std :: cin >> size;
    int A[100];
    for (int i = 0; i < size; i++) {
        std :: cin >> A[i];
    }
    bubble (A, size);
    return 0;
}