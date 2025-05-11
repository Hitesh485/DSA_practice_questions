#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int n, int s, int e)
{
    // merge two array's
    // copy ele and create new array

    // mid is for to calculate len of both array's
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create new array sizeof len1 and len2
    int *res1 = (int *)malloc(sizeof(int) * len1);
    int *res2 = (int *)malloc(sizeof(int) * len2);

    // copy ele to array
    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
    {
        res1[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        res2[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted array's
    mainArrayIndex = s;
    // printf("Main array index: %d \n", mainArrayIndex );
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (res1[index1] < res2[index2])
        {
            arr[mainArrayIndex++] = res1[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = res2[index2++];
        }
    }

    // copy rest ele
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = res1[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = res2[index2++];
    }

    // free both dynamic allocated array's.
    free(res1);
    free(res2);
}

void mergeSort(int arr[], int n, int s, int e)
{
    // basecase
    if (s >= e)
    {
        return;
    }

    // mid
    int mid = s + (e - s) / 2;

    // divide left subarray
    mergeSort(arr, n, s, mid);

    // divide right subarray
    mergeSort(arr, n, mid + 1, e);

    // merge
    merge(arr, n, s, e);
}

int main()
{
    // int arr[] = {10, 1, 7, 6, 14, 9};
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}