#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int n, int arr[]) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 1; j < n-1; j++) {
            if(arr[j - 1] > arr[j]) {
                swap(&arr[j-1], &arr[j]);
            }
        }
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
    bubble_sort(n, arr);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}