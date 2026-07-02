#include <stdio.h>

int a[20][20], visited[20], notvisited[20], n;

void dfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        // Check adjacent and not visited
        if (a[v][i] != 0 && visited[i] == 0)
        {
            visited[i] = 1;
            printf("%d ", i);
            dfs(i);
        }
    }
}

int main()
{
    int v, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nEnter the adjacency matrix of the given graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    printf("\nDFS traversal is:\n");

    visited[v] = 1;
    printf("%d ", v);

    dfs(v);

    // Check unreachable vertices
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            notvisited[j++] = i;
        }
    }

    if (j == 0)
    {
        printf("\nAll vertices are reachable from the starting vertex: %d\n", v);
    }
    else
    {
        printf("\nFollowing vertices are not reachable from the given starting vertex %d:\n", v);
        for (i = 0; i < j; i++)
        {
            printf("%d ", notvisited[i]);
        }
        printf("\n");
    }

    return 0;
}
