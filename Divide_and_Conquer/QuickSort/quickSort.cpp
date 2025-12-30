#include <iostream>
#include <vector>

// TODO -> Randomised Quick Sort

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    // step 1 : choose pivot element
    int pivotIndex = start;
    int pivotElement = arr[start];

    // step 2: Find correct poisition for pivot element and place it there
    // i = start +1 because we currently at pivot Element (start).
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }

    // when i exit this loop, i'll get the pivot element ki correct position ka index.
    int correctIndex = start + count;
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;

    // step 3: Left mai sare chote element and right mai sare bade elements
    int i = start;
    int j = end;

    while ( i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // case 2 : you found the element to swap
        // ????? -> Refer notes pdf for clarity
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end)
{
    // base case
    // 1. s > e and 2. s == e (single ele, already sorted)
    if (start >= end)
    {
        return;
    }

    // partition logic
    int index = partition(arr, start, end); 

    // left call
    quickSort(arr, start, index - 1);

    // right call
    quickSort(arr, index + 1, end);
}

int main()
{
    vector<int> arr = {8, 3, 4, 1, 20, 50, 50, 50, 30};

    int start = 0;
    int end = arr.size() - 1;

    quickSort(arr, start, end);

    for (auto iter : arr)
    {
        cout << iter << " ";
    }

    cout << endl;

    return 0;
}