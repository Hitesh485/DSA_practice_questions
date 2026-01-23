/* Brute Force solution -> n^2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int p1 = 0;
        int sum = 0;
        bool isFound = false;
        vector<int> ans;

        while (p1 < n-1)
        {
            if (isFound)
            {
                break;
            }
            int p2 = p1+1;
            sum = p1;
            

            while (p2 < n)
            {
                sum =  nums[p1] + nums[p2];
                if (sum == target)
                {
                    ans.push_back(p1);
                    ans.push_back(p2);
                    isFound = true;
                    break;
                }
                p2++;
            }
            p1++;
        }
        return ans;
    }
};



*/

/* using hashmap ->
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using hashmap
        unordered_map<int, int> mp;
        vector<int> ans(2);

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int difference = target - nums[i];
            if (mp.find(difference) != mp.end()) // present in hashmap
            {
                int val = mp.at(difference);
                ans[0] = val;
                ans[1] = i;
                break;
            }
            // push into the map (ele : index)
            mp.insert({nums[i], i});
        }
        return ans;
    }
};


*/
