#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target = 6)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            if (nums[s] > nums[e])
            {
                s = mid + 1;
                continue;
            }
            e = mid - 1;
        }
        else
        {
            if (nums[s] > nums[e])
            {
                e = mid - 1;
                continue;
            }
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{

    // vector<int> arr = {7, 6, 5, 4, 3, 2};
    vector<int> arr = {2, 3, 4, 5, 6, 7};
    cout << search(arr, 6) << endl;
    return 0;
}