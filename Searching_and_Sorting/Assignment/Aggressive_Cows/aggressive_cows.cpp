class Solution {
  public:
    
    bool isPossibleSolution(vector<int> &stalls, int mid, int k, int n)
    {
        int p = stalls[0];
        int i = 0;
        
        while (i < n)
        {
            if (abs(p - stalls[i]) >= mid)
            {
                k--;
                p = stalls[i];
            }
            if (k <= 1)
            {
                return true;
            }
            i++;
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        
        int start = 0;
        int end = stalls[stalls.size()-1] - stalls[0];
        int ans = -1;
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (isPossibleSolution(stalls, mid, k, n))
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return ans;
    }
};