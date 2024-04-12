#include <stdio.h>

int merge_sort(int x[], int y[], int n, int m) {
    int i,j,k;
    i = 0; j = 0; k = 0;
    int len_z = n+m;
    int z[n+m];

    while(i < n && j < m) {
        if(x[i] < y[j]) {
            z[k] = x[i];
            i++;
            k++;
        }
        else {
            z[k] = y[j];
            j++;
            k++;
        }
    }

    while(i < n) {
        z[k] = x[i];
        i++;
        k++;
    }

    while(j < m) {
        z[k] = y[j];
        j++;
        k++;
    }
    for(int i = 0; i < len_z; i++) {
        printf("%d ", z[i]);
    }

}

int main() {
    int n, m;

    printf("Enter no. of elements in first array: ");
    scanf("%d", &n);
    int first[n];
    for(int i = 0; i < n; i++) {
        printf("Enter elements for first array: ");
        scanf("%d", &first[i]);
    }

    printf("Enter no. of elements in second array: ");
    scanf("%d", &m);
    int second[m];
    for(int i = 0; i < m; i++) {
        printf("Enter elements for second array: ");
        scanf("%d", &second[i]);
    }

    merge_sort(first, second, n, m);
}