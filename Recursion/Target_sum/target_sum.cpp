#include <iostream>
#include <climits>
#include <vector>
#include <climits>

using namespace std;

int miniNum(vector<int> &arr, int targetSum)
{
    if (targetSum == 0)
    {
        return 0;
    }

    if (targetSum < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = miniNum(arr, targetSum-arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans+1);
        }
    }
    return mini;
}

int main ()
{
    vector<int> arr = {1,2,3};
    int targetSum = 5;

    cout << miniNum(arr, targetSum) << endl;
    return 0;
}