#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void merge(int a[], int n1, int b[], int n2, int v[])
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            v[k++] = a[i++];
        else
            v[k++] = b[j++];
    }

    while (i < n1)
        v[k++] = a[i++];

    while (j < n2)
        v[k++] = b[j++];
}

void mergesort(int v[], int n)
{
    if (n <= 1)
        return;

    int n1 = n / 2;
    int n2 = n - n1;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = v[i];

    for (int i = 0; i < n2; i++)
        b[i] = v[i + n1];

    mergesort(a, n1);
    mergesort(b, n2);

    merge(a, n1, b, n2, v);
}

int main()
{
    int arr[MAX], n, ch;
    FILE *fp;
    clock_t start, end;
    double exetime;

    

    while (1)
    {
        printf("\n1. Sort Array using Merge Sort");
        printf("\n2. Benchmarking");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("Enter number of elements (max %d): ", MAX);
            scanf("%d", &n);

            if (n <= 0 || n > MAX)
            {
                printf("Invalid size!\n");
                break;
            }

            fp = fopen("input.txt", "w");

            for (int i = 0; i < n; i++)
                fprintf(fp, "%d ", rand() % 10000);

            fclose(fp);

            fp = fopen("input.txt", "r");

            for (int i = 0; i < n; i++)
                fscanf(fp, "%d", &arr[i]);

            fclose(fp);

            mergesort(arr, n);

            fp = fopen("output.txt", "w");

            for (int i = 0; i < n; i++)
                fprintf(fp, "%d ", arr[i]);

            fclose(fp);

            printf("Sorted! Check output.txt\n");

            break;

        case 2:

            printf("\nSize\tTime Taken(sec)\n");

            fp = fopen("mergeplot.dat", "w");

            for (int p = 100; p <= 1000; p += 100)
            {
                for (int i = 0; i < p; i++)
                    arr[i] = rand() % 1000;

                start = clock();

                mergesort(arr, p);

                end = clock();

                exetime = (double)(end - start) / CLOCKS_PER_SEC;

                printf("%d\t%lf\n", p, exetime);
                fprintf(fp, "%d\t%lf\n", p, exetime);
            }

            fclose(fp);

            printf("Data stored in mergeplot.dat\n");

            break;

        case 3:

            printf("Exiting...\n");
            exit(0);

        default:

            printf("Invalid choice!\n");
        }
    }

    return 0;
}