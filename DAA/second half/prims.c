#include <stdio.h>

#define MAX 20
#define INF 999

int minKey(int key[], int visited[], int n)
{
    int min = INF;
    int index;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0 && key[i] < min)
        {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void prim(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    for(int i = 0; i < n; i++)
    {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i = 0; i < n - 1; i++)
    {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] && visited[v] == 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int cost = 0;

    printf("\nEdge\tWeight\n");

    for(int i = 1; i < n; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[parent[i]][i]);
        cost += graph[parent[i]][i];
    }

    printf("Cost = %d\n", cost);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    prim(graph, n);

    return 0;
}