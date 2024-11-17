#include <stdio.h>
#define MAX_SIZE 100

void quicksort(int A[],int  p,int r)
{
    if (p < r)
    {
        int q;
        q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j]<= x);
        {
            i = i + 1;
            A[i] = A[j];
        }
        return i + 1;
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
    printf("Enter the number of elements you want to add in Array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the element for position %d : ", i);
        scanf("%d", &A[i]);
    }

    printf("Given Array is: ");
    printArray(A, n);

    quicksort(A, 0, n - 1); 

    printf("Sorted Array is :");
    printArray(A, n);

    return 0;
}