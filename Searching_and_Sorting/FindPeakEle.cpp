#include <iostream>
#include <vector>

using namespace std;

int peak(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        if (arr[start] <= arr[end])
        {
            return end;
        }

        int mid = start + (end - start) / 2;

        // peak ele
        if (arr[mid - 1]<arr[mid]> arr[mid + 1] && mid - 1 >= 0 && mid + 1 <= end)
        {
            return mid;
        }
        else if (arr[start] > arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid;
        }
    }
    return start;
}

int main()
{

    // vector<int> arr = {6, 7, 0, 1, 2, 3, 5};
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << peak(arr) << endl;

    return 0;
}