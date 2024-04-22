#include <stdio.h>
#define INF 10000

void printmatrix(int size, int array[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == INF)
            {
                printf("%s\t", "INF");
            }
            else
            {
                printf("%d\t", array[i][j]);
            }
        }
        printf("\n");
    }
}

void floydwarshall(int size, int array[size][size])
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (array[i][k] + array[k][j] < array[i][j])
                {
                    array[i][j] = array[i][k] + array[k][j];
                }
            }
        }
    }
    printmatrix(size, array);
}

int main()
{

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("---------------------------------------------\n");
    printf("Note: Please enter '-1' for INFINITE value.\n");
    printf("---------------------------------------------\n");

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter [%d] row: ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = INF;
            }
        }
    }

    floydwarshall(n, matrix);

    return 0;
}