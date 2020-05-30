/****************************************************************************************************************
* In a sorted array of integers, find the index of the first and the last occurrence of an element              *
*                                                                                                               *
*****************************************************************************************************************/

#include <iostream>

int FirstOccurrence (int arr[], int val, int low, int high) {
    int found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val) {
            found = mid;
            high = mid - 1;
        }
        else if (arr[mid] < val) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return found;
}

int LastOccurrence (int arr[], int val, int low, int high) {
    int found = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val) {
            found = mid;
            low = mid + 1;
        }
        else if (arr[mid] < val) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return found;
}



int main () {
    int arr[] = {2, 2, 2, 4, 6, 7, 10, 10, 10, 10};
    std :: cout << FirstOccurrence (arr, 10, 0, 10); // output: 6
    std :: cout << LastOccurrence (arr, 10, 0, 10) << std :: endl; // output: 9
    std :: cout << FirstOccurrence (arr, 2, 0, 10); // output: 0
    std :: cout << LastOccurrence (arr, 2, 0, 10) << std :: endl; // output: 2
    return 0;
}