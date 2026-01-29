#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 1. approach -> using sort() -> O(nlogn)
// int getSecondLargest(vector<int> &arr) {
//     int n = arr.size();

//     // Sort the array in non-decreasing order
//     sort(arr.begin(), arr.end());

//     // start from second last element as last element is the largest
//     for (int i = n - 2; i >= 0; i--) {

//         // return the first element which is not equal to the
//         // largest element
//         if (arr[i] != arr[n - 1]) {
//             return arr[i];
//         }
//     }

//     // If no second largest element was found, return -1
//     return -1;
// }

/*******************************************************************************/

// My Approach -> O(n) & O(1)
int getSecondLargest(vector<int> &arr)
{
    // 1. Find max
    int n = arr.size();
    int maxFirst = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (maxFirst < arr[i])
            maxFirst = arr[i];
    }

    // 2. All maxFirst ele = -1
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == maxFirst)
            arr[i] = -1;
    }

    // 3. Find again max
    int temp = maxFirst;
    maxFirst = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (maxFirst < arr[i])
        {
            maxFirst = arr[i];
        }
    }

    if (temp == maxFirst)
        return -1;
    return maxFirst;
}

/*******************************************************************************/

// Expected approach. Done only one pass. O(n) & O(1).
// int getSecondLargest(vector<int> &arr) {
//     int n = arr.size();

//     int largest = -1, secondLargest = -1;

//     // finding the second largest element
//     for (int i = 0; i < n; i++) {

//         // If arr[i] > largest, update second largest with
//         // largest and largest with arr[i]
//         if(arr[i] > largest) {
//         	secondLargest = largest;
//             largest = arr[i];
//         }
      
//         // If arr[i] < largest and arr[i] > second largest, 
//         // update second largest with arr[i]
//       	else if(arr[i] < largest && arr[i] > secondLargest) {
//         	secondLargest = arr[i];
//         }
//     }
//     return secondLargest;
// }

/*******************************************************************************/



int main()
{
    // [12, 35, 1, 10, 34, 1] = 34
    // [10, 5, 10]  = 5
    // [10, 10, 10]  = -1
    vector<int> arr = {};

    return 0;
}