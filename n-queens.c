#include <stdio.h>
#include <stdbool.h>

int n;
int count = 0;

bool isSafe(char board[n][n], int row, int col);
void printBoard(char (*board)[n]);
void nqueen(char board[n][n], int row);

int main()
{
    printf("Number of queens : ");
    scanf("%d", &n);

    char board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '*';
        }
    }

    nqueen(board, 0);

    return 0;
}

void nqueen(char board[n][n], int row)
{

    if (n == row)
    {
        count++;
        printf("\nChess board %d\n", count);
        printBoard(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 'Q';
            nqueen(board, row + 1);
            board[row][i] = '*';
        }
    }
}

bool isSafe(char board[n][n], int row, int col)
{

    // vertical check
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // upper left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // upper right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void printBoard(char (*board)[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}