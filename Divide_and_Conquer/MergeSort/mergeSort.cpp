#include <iostream>
#include <vector>

// (IMPORTANT)
// TODO -> Inversion Count - (Purpose -> Do not use extra space in merge sort).

using namespace std;

void merge(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int n = mid - start + 1;
    int m = end - mid;

    // create new array with size n
    vector<int> leftSubArr = vector<int>(n);
    // create new array with size m
    vector<int> rightSubArr = vector<int>(m);

    // copy ele to leftSubArr
    int k = start;
    for (int i = 0; i < n; i++)
    {
        leftSubArr[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < m; i++)
    {
        rightSubArr[i] = arr[k];
        k++;
    }

    // Merge logic
    // Now we having left sorted subarray and right sorted subarray. overwrite the main array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while (leftIndex < n && rightIndex < m)
    {
        if (leftSubArr[leftIndex] < rightSubArr[rightIndex])
        {
            arr[mainArrayIndex++] = leftSubArr[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = rightSubArr[rightIndex++];
        }
    }

    while (leftIndex < n)
    {
        arr[mainArrayIndex++] = leftSubArr[leftIndex++];
    }
    while (rightIndex < m)
    {
        arr[mainArrayIndex++] = rightSubArr[rightIndex++];
    }

    // delete left and right subarray using swap idiom.
    vector<int>().swap(leftSubArr);
    vector<int>().swap(rightSubArr);
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}

int main()
{
    vector<int> arr = {7, 3, 2, 16, 24, 4, 11, 9};
    int start = 0;
    int end = arr.size() - 1;
    mergeSort(arr, start, end);

    for (auto iter : arr)
    {
        cout << iter << " ";
    }
    cout << endl;
    return 0;
}