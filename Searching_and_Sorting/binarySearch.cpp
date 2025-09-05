#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool binarySearch(int arr[], int n, int target = 9)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target)
        {
            return true;
        }

        else if (arr[mid] > target)
        {
            end = mid-1;
        }
        
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 4, 9, 11, 15, 19, 30};
    vector<int> a = {1, 2, 4, 9, 11, 15, 19, 30};
    int n = sizeof(arr) / sizeof(int);



    if (binarySearch(arr, n, 11))
    {
        cout << "found" << endl;
    }
    else {
        cout  << "not found " << endl;
    }
    return 0;
}
