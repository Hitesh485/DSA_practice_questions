#include <iostream>
#include <vector>

/*
nearly sorted array are those array where elements are either i-1 or i or i+1 index according to index of sorted array.
*/

using namespace std;

int nearlySortedArray(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        // i-1 or i or i+1
        if (arr[mid] == target)
            return mid;
        if (arr[mid - 1] == target && ((mid - 1) >= 0))
            return mid - 1;
        if (arr[mid + 1] == target && ((mid + 1) <= arr.size() - 1))
            return mid + 1;
        else if (arr[mid] < target)
        {
            // right search space
            start = mid + 2; // because we already checked
        }
        else
        {
            end = mid - 2; // becuase we already checked
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int target = 80;
    cout << nearlySortedArray(arr, target) << endl;
    return 0;
}