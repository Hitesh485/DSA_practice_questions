#include <iostream>
#include <vector>

using namespace std;

int missingEle(vector<int> &arr)
{
    int ptr = 1;

    while (ptr <= arr.size())
    {
        if (arr[ptr - 1] != ptr)
        {
            return ptr;
        }
        ptr++;
    }
    return -1;
}

bool absoluteDiff(int ele1, int ele2)
{
    // cout << "abs : " << (abs(ele1 - ele2) == 1) << endl;
    return (abs(ele1 - ele2) == 1);
}

int missingEleWithBinarySearch(vector<int> &arr)
{
        int start = 0;
        int end = arr.size() - 1;
        
        // edge case (single ele)
        if (arr[0] == 2)
        {
            return 1;
        }
    
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
    
            if (!absoluteDiff(arr[mid], arr[mid + 1]))
            {
                return arr[mid] + 1;
            }
            else if (!absoluteDiff(arr[mid], arr[mid - 1]))
            {
                return arr[mid] - 1;
            }
    
            // update start , mid and end indexes ->
            if (arr[mid] != mid + 1)
            {
                end = mid - 1;
            }
            else if (arr[start] != start + 1)
            {
                end = mid - 1;
            }
            else if (arr[end] != end + 1)
            {
                start = mid + 1;
            }
            else
            {
                start++;
                end--;
            }
        }
        // edge case (if no missing ele found then need to return end missing ele)
        return arr.size()+1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    // cout << missingEle (arr) << endl;
    cout << missingEleWithBinarySearch(arr) << endl;
    return 0;
}
