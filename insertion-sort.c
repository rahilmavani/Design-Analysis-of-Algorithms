#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
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
    insertion_sort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}