#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
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
            if (arr[mid] > arr[start])
            {
                start = mid;
            }
            else{
                end = mid-1;
            }
        }
        return start;
    }

    int binarySearch(int s, int e, int target, vector<int> &nums)
    {
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
    int search(vector<int> &nums, int target)
    {

        // edge case
        if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        int ans = -1;
        int peakIndex = peak(nums);
        cout << "Peak = " << peakIndex << endl;

        if (nums[peakIndex] == target)
        {
            return peakIndex;
        }

        // search in right subarray
        ans = binarySearch(peakIndex + 1, nums.size() - 1, target, nums);
        cout << "first ans = " << ans << endl;
        if (ans == -1)
        {
            // search in left subarray
            ans = binarySearch(0, peakIndex - 1, target, nums);
            cout << "second ans = " << ans << endl;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    // vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    vector<int> arr = {3,1};
    int target = 2;
    cout << s.search(arr, target) << endl;
    return 0;
}

// more short approach -> 
/*
class Solution {
public:
    int indexSearch(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + ((end - start) >> 1);

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target <= nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } 
            // Right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return indexSearch(nums, target);
    }
};
*/