#include <stdio.h>
#include <stdbool.h>

int n;
int count = 0;

void print_board(char board[n][n])
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

void helper(char board[n][n], int row)
{
    if (n == row)
    {
        count++;
        printf("Chess board number: %d\n", count);
        print_board(board);
        return;
    }
}

bool is_safe(char board[n][n], int row, int col)
{   
    //Vertical check
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == 'Q')
            return false;
    }

    //Horizontal check
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    //Lower left check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    //Lower right check
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    //Upper left check
    for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    //Upper right check
    for (int i = row + 1, j = col + 1; i < n && j < n; i++, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void n_queens(char board[n][n], int row)
{

    if (n == row)
    {
        count++;
        printf("\nChess board %d\n", count);
        print_board(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (is_safe(board, row, i))
        {
            board[row][i] = 'Q';
            n_queens(board, row + 1);
            board[row][i] = '*';
        }
    }
}

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

    n_queens(board, 0);

    return 0;
}
