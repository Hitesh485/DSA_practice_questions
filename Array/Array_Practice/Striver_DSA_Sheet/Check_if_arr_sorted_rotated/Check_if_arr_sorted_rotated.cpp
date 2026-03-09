#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& arr) {
        
        int n = arr.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i-1] > arr[i]) count++;
        }

        // last ele comp with first ele
        if (arr[n-1] > arr[0]) count++;

        if (count > 1) return false;
        return true;
    }
};

int main ()
{
    
    return 0;
}