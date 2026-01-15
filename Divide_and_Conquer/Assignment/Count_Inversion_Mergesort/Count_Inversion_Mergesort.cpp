#include <iostream>
#include <vector>

using namespace std;

// Merge logic -> addon is count
long merge(vector<int> &arr, vector<int> &temp, int start, int end, int mid)
{
    int i = start, j = mid + 1, k = start;
    long count = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else // arr[i] > arr[j] // inverse count case
        {
            temp[k++] = arr[j++];
            // count inversion logic -> prefer notes
            count += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    // put all temp[] ele in original array[]
    while (start <= end)
    {
        arr[start] = temp[start];
        ++start;
    }
    return count;
}

long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start >= end)
        return 0;

    long count = 0;
    int mid = start + (end - start) / 2;
    count += mergeSort(arr, temp, start, mid); // why here count += 
    count += mergeSort(arr, temp, mid + 1, end); // why here count += 
    count += merge(arr, temp, start, end, mid);
    return count;
}

int main()
{
    vector<int> arr = {8,4,2,1};
    // vector<int> arr = {2, 1, 3, 1, 2};
    vector<int> temp(arr.size(), 0);

    long count = 0;
    count = mergeSort(arr, temp, 0, arr.size() - 1);

    cout << count << endl;
    return 0;
}