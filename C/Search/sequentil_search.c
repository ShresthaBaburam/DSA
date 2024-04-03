#include <stdio.h>

int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int index = sequentialSearch(arr, n, key);
    if (index != -1) {
        printf("'%d' Element found at index '%d'\n", key, index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
