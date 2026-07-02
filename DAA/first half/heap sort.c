#include <stdio.h> heap sort 0 based indexing
#include <stdlib.h>
#include <time.h>

#define MAX 500000

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i;

    // Build Max Heap
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // Heap Sort
    for (i = n - 1; i >= 1; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int a[MAX];
    int i, n, ch, value, p;
    FILE *fp;
    clock_t start, end;
    double exetime;

    while (1)
    {
        printf("\n===== HEAP SORT MENU =====\n");
        printf("1. Heap Sort\n");
        printf("2. Record Execution Time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:

            printf("Enter number of elements: ");
            scanf("%d", &n);

            fp = fopen("input.txt", "w");

            for (i = 0; i < n; i++)
            {
                value = rand() % 10000;
                fprintf(fp, "%d\n", value);
            }

            fclose(fp);

            printf("Random numbers stored in input.txt\n");

            fp = fopen("input.txt", "r");

            for (i = 0; i < n; i++)
            {
                fscanf(fp, "%d", &a[i]);
            }

            fclose(fp);

            heapSort(a, n);

            fp = fopen("output.txt", "w");

            for (i = 0; i < n; i++)
            {
                fprintf(fp, "%d\n", a[i]);
            }

            fclose(fp);

            printf("Sorted elements stored in output.txt\n");

            break;

        case 2:

            fp = fopen("plot.dat", "w");

            for (p = 10000; p <= 100000; p += 10000)
            {
                for (i = 0; i < p; i++)
                {
                    a[i] = rand() % 10000;
                }

                start = clock();

                heapSort(a, p);

                end = clock();

                exetime = (double)(end - start) / CLOCKS_PER_SEC;

                printf("N = %d\tTime = %lf seconds\n", p, exetime);

                fprintf(fp, "%d %lf\n", p, exetime);
            }

            fclose(fp);

            printf("Execution times stored in plot.dat\n");

            break;

        case 3:

            exit(0);

        default:

            printf("Invalid Choice!\n");
        }
    }

    return 0;
}