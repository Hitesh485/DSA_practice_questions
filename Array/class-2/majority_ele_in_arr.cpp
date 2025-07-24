#include <iostream>
#include <vector>
#include <unordered_map>

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

using namespace std;

int majorityElement(vector<int> &nums)
{
    // O(n^2) and O(1)
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                ++count;
            }
        }

        if (nums.size() / 2 < count)
        {
            return nums[i];
        }
    }
    return -1;
}

// Hashing -> unordered_map ->> O(n), O(n)
int majorityElement2(vector<int> &nums)
{
    // using hashing -> unordered_map ->> O(n), O(n)

    unordered_map<int, int> count;

    for (auto ele : nums)
    {
        count[ele]++;
        if (count[ele] > nums.size() / 2)
        {
            return ele;
        }
    }
    return -1;
}

// Boyer-Moore Voting Algo -> O(n) Time, O(1) space
int findMajority__(int arr[], int n)
{
    int i, candidate = -1, votes = 0;
    // Finding majority candidate
    for (i = 0; i < n; i++)
    {
        if (votes == 0)
        {
            candidate = arr[i];
            votes = 1;
        }
        else
        {
            if (arr[i] == candidate)
                votes++;
            else
                votes--;
        }
    }
    int count = 0;
    // Checking if majority candidate occurs more than n/2
    // times
    for (i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;
    return -1;
}

int main()
{
    int arr[] = {1, 1, 1, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int majority = findMajority__(arr, n);
    cout << " The majority element is : " << majority << endl;
    return 0;
}