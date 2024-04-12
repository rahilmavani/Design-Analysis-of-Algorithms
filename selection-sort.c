#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n) {
    int i, pos;
    for (pos = 0; pos < n - 1; pos++) {
        int min = INT_MAX; 
        int min_idx = -1; 
        for (i = pos; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
                min_idx = i;
            }
        }
        swap(&arr[pos], &arr[min_idx]); 
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter the elements: ");
        scanf("%d", &arr[i]);
    }

    printf("Sorted Array: ");
    selection_sort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}