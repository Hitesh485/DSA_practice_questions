#include <iostream>
#include <vector>

// TC -> O(n * log(sum(arr)))
// SC -> O(1)

using namespace std;

int isPossibleSolution(vector<int> &arr, int mid, int k)
{
    int pageSum = 0;
    int count = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (pageSum + arr[i] > mid)
        {
            count++;
            pageSum = arr[i];
            if (count > k)
            {
                return false;
            }
        }
        else
        {
            pageSum += arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int k)
{
    // code here

    int n = arr.size();
    if (k > n)
        return -1;

    int start = 0;
    int ans = -1;
    int end = accumulate(arr.begin(), arr.end(), 0);

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossibleSolution(arr, mid, k))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    cout << findPages(arr, k) << endl;
    return 0;
}