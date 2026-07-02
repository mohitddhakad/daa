 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

void GenShiftTable(char p[], int t[])
{
    int i, j;
    int m = strlen(p);

    for (i = 0; i < MAX; i++)
        t[i] = m;

    for (j = 0; j < m - 1; j++)
        t[p[j]] = m - 1 - j;
}

int Horspool(char s[], char p[], int t[])
{
    int i, k;
    int n = strlen(s);
    int m = strlen(p);

    i = m - 1;

    while (i < n)
    {
        k = 0;

        while (k < m && p[m - 1 - k] == s[i - k])
            k++;

        if (k == m)
            return i - m + 1;

        i = i + t[s[i]];
    }

    return -1;
}

int main()
{
    char text[MAX];
    char pattern[MAX];
    int shiftTable[MAX];
    int found;

    printf("Enter the source string: ");
    scanf("%s", text);

    printf("Enter the pattern string: ");
    scanf("%s", pattern);

    GenShiftTable(pattern, shiftTable);

    found = Horspool(text, pattern, shiftTable);

    if (found == -1)
        printf("\nMatching Substring not found.\n");
    else
        printf("\nMatching Substring found at position: %d\n", found + 1);

    return 0;
}