#include <stdio.h>

int main()
{
    int n, i, j, k;
    int a[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }

    printf("Shortest Path Matrix:\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%d\t", a[i][j]);

        printf("\n");
    }

    return 0;
}