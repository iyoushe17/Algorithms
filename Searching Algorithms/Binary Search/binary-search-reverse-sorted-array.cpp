#include <iostream> 

int BinarySearch (int arr[], int val, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val)
            return 0;
        else if (arr[mid] > val)
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main () {
    int arr[] = {31, 23, 18, 12, 8, 5, 4, 2};
    std :: cout << BinarySearch (arr, 18, 0, 8) << std :: endl;
    std :: cout << BinarySearch (arr, 10, 0, 8);
    return 0;
}