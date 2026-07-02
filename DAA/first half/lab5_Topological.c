#include<stdio.h>

void topological(int a[10][10], int n)
{
    int in[10], out[10], stack[10], top=-1;
    int i,j,k=0;

    // Calculate indegree
    for(i=0;i<n;i++)
    {
        in[i]=0;

        for(j=0;j<n;j++)
        {
            if(a[j][i]==1)
                in[i]++;
        }
    }

    while(1)
    {
        // Find indegree 0 vertices
        for(i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                stack[++top]=i;
                in[i]=-1;
            }
        }

        if(top==-1)
            break;

        // Remove vertex
        out[k]=stack[top--];

        // Reduce indegree
        for(i=0;i<n;i++)
        {
            if(a[out[k]][i]==1)
                in[i]--;
        }

        k++;
    }

    // Cycle detection
    if(k<n)
    {
        printf("\nGraph contains cycle\n");
        return;
    }

    printf("\nTopological sorting is:\n");

    for(i=0;i<k;i++)
        printf("%d\t",out[i]+1);
}

int main()
{
    int a[10][10],n,i,j;

    printf("Enter number of vertices:\n");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++)
    {
        printf("Enter row %d\n",i+1);

        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    topological(a,n);

    return 0;
}