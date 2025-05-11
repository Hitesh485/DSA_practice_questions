#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void selection (int arr[], int n)
{
    int min  = INT_MAX;
    for (int i = 0; i < n-1; i++)
    {
        // first ele is smallest
        min = i;

        for (int j = i; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(int);

    selection(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}