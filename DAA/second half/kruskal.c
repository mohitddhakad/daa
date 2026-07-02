#include <stdio.h>

#define INF 999

int cost[10][10], parent[10];
int n, i, j;

int find(int i)
{
    while (parent[i])a
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int a, b, u, v, min, ne = 1, Mcost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }

    printf("\nEdges in MST:\n");

    while (ne < n) {

        min = INF;

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d - %d = %d\n", a, b, min);
            Mcost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total Cost = %d\n", Mcost);

    return 0;
}