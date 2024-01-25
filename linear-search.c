#include <stdio.h>

int linear_search(int array[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int index = linear_search(array, size, key);

    if (index >= 0)
    {
        printf("%d found at index %d\n", key, index);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}