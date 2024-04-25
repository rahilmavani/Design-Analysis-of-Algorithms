#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lo, int hi) {
    int pivot = arr[lo];
    int i = lo + 1;  
    int j = hi;
    while (i <= j) { 
        while (i <= hi && arr[i] <= pivot) {
            i++;
        }
        while (j > lo && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[lo], &arr[j]);
    return j;
}



void quick_sort(int arr[], int lo, int hi) {
    if(lo < hi) {
        int j = partition(arr, lo, hi);
        quick_sort(arr, lo, j);
        quick_sort(arr, j+1, hi);
    }
}

int main() {
    int arr[] = {2, 4, 1, 0, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
