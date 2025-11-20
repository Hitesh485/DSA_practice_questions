#include <iostream>
#include <vector>

using namespace std;

int binarySearch_rec(vector<int> &arr, int start, int end, int &target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start)/2;

    if (arr[mid] == target) return mid;
    
    else if (arr[mid] > target) 
    {
        return binarySearch_rec(arr, start, mid-1, target);
    }

    else
    {
        return binarySearch_rec(arr, mid+1, end, target);
    }
}

int main ()
{
    vector<int> arr = {12,33,45,62,92,101};
    int start = 0;
    int end = arr.size()-1;
    int target = 101;
    cout << binarySearch_rec(arr, start, end, target) << endl;
    return 0;
}