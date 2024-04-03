#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1) {
        printf("'%d' Element found at index '%d'\n", key, index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
