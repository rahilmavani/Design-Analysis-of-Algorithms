#include <stdio.h>


void merge(int arr[], int lo, int mid, int hi) {
    int i,j,k;
    int out[200];
    i = lo;
    j = mid+1;
    k = lo;

    while(i <= mid && j <= hi) {
        if(arr[i] < arr[j]) {
            out[k] = arr[i];
            i++; k++;
        }
        else {
            out[k] = arr[j];
            j++; k++;
        }
    }
    while(i <= mid) {
        out[k] = arr[i];
        i++; k++;
    } 
    while(j <= hi) {
        out[k] = arr[j];
        j++; k++;   
    }

    for (int x = 0; x <= hi; x++) {
        arr[x] = out[x];
    }
}

void merge_sort(int arr[], int lo, int hi) {
    int mid;
    if(lo < hi) {
        mid = (lo + hi) / 2;
        merge_sort(arr, lo, mid);
        merge_sort(arr, mid+1, hi);
        merge(arr, lo, mid, hi);
    }
    
}   


void main(){
    
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter the elements: ");
        scanf("%d", &arr[i]);
    }

    printf("Sorted Array: ");
    merge_sort(arr, 0, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}