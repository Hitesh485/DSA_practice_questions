// class Solution {
// public:

//     int peak (vector<int> &arr)
//     {
//         int start = 0;
//         int end = arr.size()-1;
//         while (start <= end)
//         {
//             int mid = start + (end-start)/2;

//             if (arr[start] > arr[end])
//             {
//                 end = mid-1;
//             }
//             else if (arr[start] < arr[end])
//             {
//                 start = mid+1;
//             }
//             if (start == end == mid)
//             {
//                 return start;
//             }
//         }
//         return end;
//     }

//     int binarySearch(int s, int e, int target, vector<int>& nums)
//     {
//         while (s <= e)
//         {
//             int mid = s + (e-s)/2;
//             if (nums[mid] == target)
//             {
//                 return mid;
//             }
//             else if (nums[mid] > target)
//             {
//                 e = mid-1;
//             }
//             else
//             {
//                 s = mid+1;
//             }
//         }
//         return -1;
//     }
//     int search(vector<int>& nums, int target) {

//         // edge case 
//         if (nums.size() == 1)
//         {
//             if (nums[0] == target)
//             {
//                 return 0;
//             }
//             else
//             {
//                 return -1;
//             }
//         }

//         int ans = -1;
//         int peakIndex = peak(nums);
//         cout << "Peak = " << peakIndex;

//         if (nums[peakIndex] == target)
//         {
//             return peakIndex;
//         }
//         else if (nums[peakIndex] > target)
//         {
//             ans = binarySearch(peakIndex+1, nums.size()-1, target, nums);
//             if (ans != -1)
//             {
//                 return ans;
//             }
//         }
//         else
//         {
//             ans = binarySearch(0, peakIndex-1, target, nums);
//             if (ans != -1)
//             {
//                 return ans;
//             }
//         }
//         return -1;
//     }
// };