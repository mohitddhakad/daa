#include <stdio.h>

int a[20][20], q[20], visited[20], notvisited[20];
int n, f = -1, r = -1;

void bfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        // If vertex is adjacent and not visited
        if (a[v][i] != 0 && visited[i] == 0)
        {
            r++;
            q[r] = i;         // insert into queue
            visited[i] = 1;   // mark visited
            printf("%d ", i); // print properly
        }
    }

    f++; // move front

    // Continue BFS if queue is not empty
    if (f <= r)
        bfs(q[f]);
}

int main()
{
    int v, i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nEnter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    // Input validation
    if (v < 0 || v >= n)
    {
        printf("\nInvalid starting vertex!\n");
        return 0;
    }

    // Initialize queue
    f = r = 0;
    q[r] = v;

    printf("\nBFS traversal is:\n");

    visited[v] = 1;
    printf("%d ", v);

    bfs(v);

    // Check unreachable vertices
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            notvisited[j++] = i;
    }

    if (j == 0)
    {
        printf("\nAll vertices are reachable from the starting vertex: %d\n", v);
    }
    else
    {
        printf("\nFollowing vertices are not reachable from the starting vertex %d:\n", v);
        for (i = 0; i < j; i++)
            printf("%d ", notvisited[i]);
        printf("\n");
    }

    return 0;
}