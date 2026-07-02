#include <stdio.h>

// Maximum value return karega
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, m;
    int i, j;

    int p[20];      // Profit Array
    int w[20];      // Weight Array
    int v[20][20];  // DP Table

    // Number of items input lo
    printf("Enter number of items: ");
    scanf("%d", &n);

    // Sabhi items ke profits input lo
    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    // Sabhi items ke weights input lo
    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    // Knapsack Capacity input lo
    printf("Enter knapsack capacity: ");
    scanf("%d", &m);

    // First Column ko 0 initialize karo
    for(i = 0; i <= n; i++)
        v[i][0] = 0;

    // First Row ko 0 initialize karo
    for(j = 0; j <= m; j++)
        v[0][j] = 0;

    // DP Table Fill karo
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            // Agar current item ka weight capacity se zyada hai
            if(j < w[i])
            {
                // Item include nahi kar sakte
                v[i][j] = v[i-1][j];
            }
            else
            {
                // Include aur Exclude me se maximum profit choose karo
                v[i][j] = max(v[i-1][j],
                              p[i] + v[i-1][j-w[i]]);
            }
        }
    }

    // DP Table Print karo
    printf("\nDP Table:\n");

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= m; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    // Final Maximum Profit
    printf("\nMaximum Profit = %d\n", v[n][m]);

    return 0;
}