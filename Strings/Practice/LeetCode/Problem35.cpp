#include <iostream>
#include <vector>

using namespace std;

int bs(int start, int end, vector<int> &nums, int target)
{
    int mid = -1;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            // case 1
            if (mid == 0)
            {
                return 0;
            }
            else if (nums[mid - 1] < target)
            {
                return mid;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    if (start == end)
    {
        // when (start < end) hits mid will not updates. we have to make sure it will updated so ->
        mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;
        else if (end == 0)
        {
            if (nums.size() == 1 && nums[0] < target)
            {
                return nums.size();
            }
            else
            {
                return 0;
            }
        }

        // 3rd case -> last + 1 index
        else
        {
            if (nums[mid] < target)
            {
                return nums.size();
            }
            else
            {
                return mid;
            }
        }
    }
    return -1;
}

int searchInsert(vector<int> &nums, int target)
{

    int start = 0;
    int end = nums.size() - 1;
    return bs(start, end, nums, target);
}

int main()
{
    vector<int> arr = {1,3,5,6}; // [1,2,6,10,12], [1], [1,3]
    int target = 5; // 2 // 7 // 0 // 12 // 2 // 0

    cout << searchInsert(arr, target) << endl;
    return 0;
}