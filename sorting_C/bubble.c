#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n)
{
    // for (int i = 0; i < n; i++)
    // {
    // here optimization is that last ele of jth index we ignore because it already sorted after round 1,2,3 and so on. So, it should like j-i.
    //     for (int j = 0; j < n-1; j++)
    //     {
    //         if (arr[j] > arr[j+1])
    //         {
    //             int temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //         }
    //     }
    // }
    for (int i = 1; i < n; i++) // here i=1 is for arr[j+1] camparison.
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // int arr[] = {10, 1, 7, 6, 14, 9};
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(int);

    bubble(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}