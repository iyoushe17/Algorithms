#include <iostream>

int BinarySearch (int arr[], int val, int low, int high) {
    // preventing int overflow

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val)
            return 0;

        else if (arr[mid] > val)
            high = mid - 1;

        else 
            low = mid + 1;
    }
    return -1;
}



int main () {
    int arr[] = {2, 4, 5, 8, 12, 18, 23, 31};
    std :: cout << BinarySearch (arr, 18, 0, 8) << std :: endl;
    std :: cout << BinarySearch (arr, 10, 0, 8);
    return 0;
}