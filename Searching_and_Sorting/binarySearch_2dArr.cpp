#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<vector<int>> &arr, int row, int col, int target)
{
    int start = 0;
    int end = (row*col)-1;

    while (start <= end)
    {
        int mid = start + (end-start)/2;
        int rowIndex = mid/col;
        int colIndex = mid%col;
        int element = arr[rowIndex][colIndex];

        if (element == target)
        {
            return true;
        }
        else if (element <= target)
        {
            // right search space
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return false;
}

int main ()
{
    int n = 5;
    int m = 4;
    vector<vector<int>> arr(n, vector<int>(m));

    arr = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}, {17,18,19,20}};

    int target = 18;

    cout << binarySearch(arr, n, m, target) << endl;
    return 0;
}