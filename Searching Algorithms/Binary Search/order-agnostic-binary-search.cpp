#include <iostream> 

int OrderAgnosticBinarySearch (int arr[], int val, int low, int high) {
    bool order = true;
    //if the order is decreasing, set order to false
    if (arr[0] > arr[1])
        order = false;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val)
            return 0;
        else if (arr[mid] > val) {
            if (order)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        else {
            if (order)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main () {
    int arr[] = {1, 2, 3, 4, 10, 12, 20, 22};
    int arr1[] = {25, 23, 21, 19, 17, 15, 10, 9, 3, 1};

    std :: cout << OrderAgnosticBinarySearch (arr, 12, 0, 8) << std :: endl;
    std :: cout << OrderAgnosticBinarySearch (arr, 23, 0, 8) << std :: endl;
    std :: cout << std :: endl;
    std :: cout << OrderAgnosticBinarySearch (arr1, 19, 0, 10) << std :: endl;
    std :: cout << OrderAgnosticBinarySearch (arr1, 26, 0, 10) << std :: endl;
}