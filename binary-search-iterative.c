#include <stdio.h>

int binary_search(int array[], int size, int key)
{
    int start = 0, end = size - 1;
    for (int mid = (start + end) / 2; start <= end; mid = (start + end) / 2)
    {
        if (array[mid] == key)
        {
            return mid;
        }

        else if (array[mid] > key)
        {
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the sorted array: ");
    int array[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter element to be searched: ");
    scanf("%d", &key);

    int index = binary_search(array, size, key);

    if (index >= 0)
    {
        printf("%d found at index %d", key, index);
    }
    else
    {
        printf("Element not found");
    }
}   