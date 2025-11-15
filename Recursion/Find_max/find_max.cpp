#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int findMax(int arr[], int n, int &maxi)
{
    if (n <= 0)
    {
        return maxi;
    }

    // if (max < arr[n - 1])
    // {
    //     max = arr[n - 1];
    // }
    maxi  = max(maxi, arr[n-1]);

    return findMax(arr, n - 1, maxi);
}

int main()
{
    int arr[] = {32, 234, 23, 23, 5, 32, 2};
    int n = sizeof(arr) / sizeof(int);
    int maxi = INT_MIN;
    cout << findMax(arr, n, maxi) << endl;
    return 0;
}