#include <stdio.h>
#include <time.h>
//merge sort

#define MAX_SIZE 100

void Merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 1; i <= n1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (int j = 1; j <= n2; j++)
    {
        R[j] = A[q + j];
    }
    L[n1 + 1] = 9999;
    R[n2 + 1] = 9999;

    int i = 1;
    int j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int n, i;
    int A[MAX_SIZE];

    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element for position %d: ", i);
        scanf("%d", &A[i]);
    }

    clock_t start = clock();

    printf("Given array is: ");
    printArray(A, n);

    MergeSort(A, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array is: ");
    printArray(A, n);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}