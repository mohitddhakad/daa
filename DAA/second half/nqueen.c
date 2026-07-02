#include <stdio.h>
#include <stdlib.h>

int board[20], count = 0;

int check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}
void queen(int row, int n)
{
    if (row == n)
    {
        count++;
        printf("\nSolution %d\n", count);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf("- ");
            }
            printf("\n");
        }
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (check(row, col))
        {
            board[row] = col;
            queen(row + 1, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter number of Queens: ");
    scanf("%d", &n);

    if (n == 2 || n == 3)
        printf("No Solution");
    else
        queen(0, n);

    return 0;
}