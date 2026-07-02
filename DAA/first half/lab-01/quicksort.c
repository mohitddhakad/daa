#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    int count = 0;

    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = si + count;

    swap(&arr[si], &arr[pivotIndex]);

    int i = si;
    int j = ei;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quicksort(int arr[], int si, int ei)
{
    if (si >= ei)
        return;

    int p = partition(arr, si, ei);

    quicksort(arr, si, p - 1);
    quicksort(arr, p + 1, ei);
}

int main()
{
    int arr[MAX], n, ch;
    clock_t start, end;
    double exetime;
    FILE *fp;
    

    while (1)
    {
        printf("\n1. Sort Array using Quick Sort");
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

            quicksort(arr, 0, n - 1);

            fp = fopen("output.txt", "w");

            for (int i = 0; i < n; i++)
                fprintf(fp, "%d ", arr[i]);

            fclose(fp);

            printf("Sorted! Check output.txt\n");

            break;

        case 2:

            printf("\nSize\tTime Taken(sec)\n");

            fp = fopen("plot.dat", "w");

            for (int p = 100; p <= 1000; p += 100)
            {
                for (int i = 0; i < p; i++)
                    arr[i] = rand() % 1000;

                start = clock();

                quicksort(arr, 0, p - 1);

                end = clock();

                exetime = (double)(end - start) / CLOCKS_PER_SEC;

                printf("%d\t%lf\n", p, exetime);
                fprintf(fp, "%d\t%lf\n", p, exetime);
            }

            fclose(fp);

            printf("Data stored in plot.dat\n");

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